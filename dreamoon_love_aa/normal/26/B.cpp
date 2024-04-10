#include<stdio.h>
char s[1000100];
main(){
    int an=0,i,k=0;
    gets(s);
    for(i=0;s[i];i++){
        if(s[i]==')'){
            if(k){
                k--;
                an+=2;
            }
        }
        else k++;
    }
    printf("%d\n",an);
}