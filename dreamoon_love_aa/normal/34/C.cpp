#include<stdio.h>
#include<stdlib.h>
int n,a[1111];
bool is_digit(char c){return c>='0'&&c<='9';}
main(){
    char s[9999];
    int first=1,i=0,j;
    gets(s);
    while(1){
        a[atoi(s+i)]=1;
        while(is_digit(s[i]))i++;
        if(!s[i])break;
        i++;
    }
    for(i=1;i<=1000;i++){
        if(a[i]){
            if(!first)putchar(',');
            else first=0;
            for(j=i+1;a[j];j++);
            if(i+1==j)printf("%d",i);
            else printf("%d-%d",i,j-1);
            i=j-1;
        }
    }
    puts("");
}