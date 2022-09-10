#include<stdio.h>
#define SIZE 1000000
main(){
    int n,an1=0,an2=0,i;
    scanf("%d",&n);
    for(i=0;i<100&&i*4<=n;i++){
        if((n-i*4)%7==0){
            if(an1+an2==0){
                an1=i;
                an2=(n-i*4)/7;
            }
            else{
                if(an1+an2>i+(n-i*4)/7){
                    an1=i;
                    an2=(n-i*4)/7;
                }
            }
        }
    }
    if(an1+an2==0)puts("-1");
    else{
        for(i=0;i<an1;i++)putchar('4');
        for(i=0;i<an2;i++)putchar('7');
        puts("");
    }
}