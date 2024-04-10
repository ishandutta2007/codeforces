#include<stdio.h>
char s[1024]="ROYGBIV";
main(){
    int n,i;
     scanf("%d",&n);
     for(i=7;i<n;i++)
        s[i]=s[(i-7)%4+3];
     puts(s);
}