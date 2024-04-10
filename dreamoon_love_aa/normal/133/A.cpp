#include<stdio.h>
main(){
    int i;
    char s[1024];
    gets(s);
    for(i=0;s[i];i++){
        if(s[i]=='H'||s[i]=='Q'||s[i]=='9')break;
    }
    if(s[i])puts("YES");
    else puts("NO");
}