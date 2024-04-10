#include<stdio.h>
#include<string.h>
main(){
    int len,neg;
    char s[111],*t;
    scanf("%s",s);
    if(s[0]=='-'){
        t=s+1;
        neg=1;
    }
    else{
        t=s;
        neg=0;
    }
    len=strlen(t);
    if(neg){
        if(len<3)puts("byte");
        else if(len==3){
            if(strcmp(t,"128")<=0)puts("byte");
            else puts("short");
        }
        else if(len<5)puts("short");
        else if(len==5){
            if(strcmp(t,"32768")<=0)puts("short");
            else puts("int");
        }
        else if(len<10)puts("int");
        else if(len==10){
            if(strcmp(t,"2147483648")<=0)puts("int");
            else puts("long");
        }
        else if(len<19)puts("long");
        else if(len==19){
            if(strcmp(t,"9223372036854775808")<=0)puts("long");
            else puts("BigInteger");
        }
        else puts("BigInteger");
    }
    else{
        if(len<3)puts("byte");
        else if(len==3){
            if(strcmp(t,"127")<=0)puts("byte");
            else puts("short");
        }
        else if(len<5)puts("short");
        else if(len==5){
            if(strcmp(t,"32767")<=0)puts("short");
            else puts("int");
        }
        else if(len<10)puts("int");
        else if(len==10){
            if(strcmp(t,"2147483647")<=0)puts("int");
            else puts("long");
        }
        else if(len<19)puts("long");
        else if(len==19){
            if(strcmp(t,"9223372036854775807")<=0)puts("long");
            else puts("BigInteger");
        }
        else puts("BigInteger");
    }
}