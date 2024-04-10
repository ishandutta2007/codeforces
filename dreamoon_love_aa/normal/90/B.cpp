#include<stdio.h>
#define SIZE 128
int n,m;
char s[SIZE][SIZE];
main(){
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            for(k=0;k<n;k++)
                if(k!=i&&s[i][j]==s[k][j])break;
            if(k<n)continue;
            for(k=0;k<m;k++)
                if(k!=j&&s[i][j]==s[i][k])break;
            if(k<m)continue;
            printf("%c",s[i][j]);
        }
    puts("");
}