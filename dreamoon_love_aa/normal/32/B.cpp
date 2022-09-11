#include<stdio.h>
main(){
    int i;
    char s[999];
    gets(s);
    for(i=0;s[i];i++){
        if(s[i]=='.')putchar('0');
        else{
            i++;
            if(s[i]=='.')putchar('1');
            else putchar('2');
        }
    }
    puts("");
}