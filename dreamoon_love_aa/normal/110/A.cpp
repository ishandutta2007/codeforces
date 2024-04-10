#include<stdio.h>
main(){
    int an=0,i;
    char s[24];
    gets(s);
    for(i=0;s[i];i++){
        if(s[i]=='4'||s[i]=='7')an++;
    }
    if(an==4||an==7)puts("YES");
    else puts("NO");
}