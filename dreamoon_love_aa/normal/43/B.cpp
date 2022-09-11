#include<stdio.h>
char s1[999],s2[999];
int d[128];
main(){
    int i;
    gets(s1);
    gets(s2);
    for(i=0;s1[i];i++)
        d[s1[i]]++;
    for(i=0;s2[i];i++){
        if(s2[i]==' ')continue;
        d[s2[i]]--;
        if(d[s2[i]]<0)break;
    }
    if(s2[i])puts("NO");
    else puts("YES");
}