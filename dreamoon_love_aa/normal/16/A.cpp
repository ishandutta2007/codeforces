#include<stdio.h>
char s[110][110];
main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++){
        for(j=1;j<m;j++)
            if(s[i][j]!=s[i][j-1])break;
        if(j<m)break;
        if(i&&s[i][0]==s[i-1][0])break;
    }
    if(i==n)puts("YES");
    else puts("NO");
}