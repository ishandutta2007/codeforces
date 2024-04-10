#include<stdio.h>
int d[3];
main(){
    int i,j;
    char s[8];
    for(i=0;i<3;i++){
        scanf("%s",s);
        if(s[1]=='<')d[s[2]-'A']++;
        else d[s[0]-'A']++;
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            if(d[j]==i)break;
        if(j==3)break;
        printf("%c",'A'+j);
    }
    if(i<3)puts("Impossible");
    else puts("");
}