#include<stdio.h>
main(){
    int n,i;
    char s[111];
    scanf("%d%s",&n,s);
    for(i=0;i<n;){
        if(i)putchar('-');
        if(i+3<n){
            putchar(s[i]);
            putchar(s[i+1]);
            i+=2;
        }
        else{
            while(i<n){
                putchar(s[i]);
                i++;
            }
        }
    }
    puts("");
}