/*
Made By : Ujjwal Roy
Date : 13/09/2015
*/

//Headers Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Global variables
int options=-1;
char passwd[30];
char ans='n';

//Function Prototypes
void menu();
void accesLevel();
void password();
void adminControl();
void changePassword();
char* loadPassword();
void addItem();

//Structure used in Code
typedef struct item{
char name[100];
float price;
}ITEM;




//Main Function
int main()
{
    accesLevel();
    return 0;
}



void accesLevel() {
    system("cls");
    printf("\n Super Market System  \n");
    printf(" --------------------\n");
    printf("\n 1.Admin\n 2.Customer\n 3.Exit\n Enter your Choice: ");
    fflush(stdin);
    scanf("%d",&options);

    switch(options){
    case 1:
        adminControl();
        break;
    case 2:
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("\n Invalid Option....Please Try again or Choose EXIT to quit!");
        delay(2000);
        accesLevel();

    }
}

void adminControl(){

    do{
        system("cls");
        printf("\n Admin Controls \n");
        printf(" --------------------\n");
        printf("\n 1.Change password\n 2.Add New Item \n 3.Modify Items \n 4.Delete Items \n 5.View Items \n 6.Return Back \n 7.Exit");
        printf("\n Enter your choice: ");
        fflush(stdin);
        scanf("%d",&options);

        switch(options){
        case 1:
            changePassword();
            break;
        case 2:
            addItem();
            break;
        case 3:
            break;
        case 4:
        case 5:
        case 6:
            accesLevel();
        case 7:
            exit(0);
        default:
            printf("\n Invalid Option....Please Try again or Choose EXIT to quit!");
            delay(2000);
            adminControl();

        }
        printf("\n Do you wish to continue(y/n) : ");
        fflush(stdin);
        ans=getchar();
    } while(ans=='Y' || ans=='y');

}

void changePassword() {
    FILE *fp;
    int i;
    char c,pword[30];

    remove("PASSWORD.txt"); //Removing exiting passowrd

    fp=fopen("PASSWORD.txt","w");
    if(fp == NULL)
    {
        printf(" File Error");
        exit(1);
    }

    printf(" Enter the new Password: ");
    fflush(stdin);
    for(i=0;i<30;i++)
    {
        c=getchar();
        if(c == EOF || c == '\n')
            break;

        fputc(c,fp);

    }
    fclose(fp);

    printf(" Password Changed ");


}

void password(char *password) {
    int i,j;
    char enter,passcode[30]={'A'};

    system("cls");
    printf("\n Enter the password : \n ");

    for(i=0;(passcode[i] <='0' && passcode[i] >='0')||(passcode[i] >='A' || passcode[i] >='a'  && passcode[i] <='Z' || passcode[i] <='z') && i<30 ;i++){
            fflush(stdin);
            passcode[i]=getche();
            putchar(8);
            fflush(stdin);
            putc(42,stdout);

            if(passcode[i] == '\r')
            {
                passcode[i]='\n';

                break;
            }

    }

  /* for(j=0;j<i;j++)
   {
       if(passcode[j]!= *(password+j))
        exit(0);

       else adminControl();
   }*/
    adminControl();
}

char* loadPassword(){

    FILE *fp,*filecreate;
    char ch;
    int i=0;
    unsigned char *passwd;
    char password[30]="ujjwal";

    fp=fopen("PASSWORD.txt","r");

    if(fp == NULL)
    {
        printf("\n Problem with the PASSWORD fileSystem");


    }

    while(i<30)
    {
        ch=fgetc(fp);

        if(ch == EOF || ch=='\n')
        {
            break;
        }

        *(passwd+i)=ch;
        i++;

    }

    if(i == 0) return password;

    return passwd;

}

void addItem() {

    FILE *fp;
    fp=("ITEM.txt","w");
    size_t nwritten;
    ITEM t;

    if(fp == NULL ){
        printf("Error in File Operation.Exiting...");
        delay(1000);
        exit(1);
    }

     nwritten = fwrite(t, sizeof t, 1, fp);


   if (nwritten < 1)
   {
      fprintf(stderr, "Writing to file failed.\n");
      exit(1);
   }

   fclose(f);

}


