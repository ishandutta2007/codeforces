#include<stdio.h>
char S[9]="hello";
main(){
    char s[111];
    int i,j;
    scanf("%s",s);
    for(i=j=0;j<5&&s[i];i++)
        if(S[j]==s[i])j++;
    if(j==5)puts("YES");
    else puts("NO");
}