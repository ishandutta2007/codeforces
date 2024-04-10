#include<stdio.h>
char s1[110],s2[110];
main(){
    int i;
    scanf("%s%s",s1,s2);
    for(i=0;s1[i];i++){
        if(s1[i]==s2[i])putchar('0');
        else putchar('1');
    }
    puts("");
}