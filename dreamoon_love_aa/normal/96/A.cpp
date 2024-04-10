#include<stdio.h>
main(){
    char s[128];
    int i,j;
    scanf("%s",s);
    for(i=0;s[i];i+=j){
        for(j=1;s[i+j]&&s[i+j]==s[i];j++);
        if(j>=7)break;
    }
    if(s[i])puts("YES");
    else puts("NO");
}