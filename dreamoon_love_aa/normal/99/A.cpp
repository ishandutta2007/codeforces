#include<stdio.h>
main(){
    int i;
    char s[1024];
    gets(s);
    for(i=0;s[i];i++)
        if(s[i]=='.')break;
    if(s[i-1]=='9')puts("GOTO Vasilisa.");
    else{
        if(s[i+1]>='5')s[i-1]++;
        s[i]=0;
        puts(s);
    }
}