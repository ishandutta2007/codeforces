#include<stdio.h>
main(){
    int i,j;
    char s[4][5];
    for(i=0;i<3;i++)scanf("%s",s[i]);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            if(s[i][j]!=s[2-i][2-j])break;
        if(j<3)break;
    }
    if(i<3)puts("NO");
    else puts("YES");
}