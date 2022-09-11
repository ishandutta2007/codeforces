#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,mi_x=100,mi_y=100,ma_x,ma_y,i,j;
char s[99][99];
main(){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(s[i][j]=='*'){
                mi_x=min(mi_x,i);
                mi_y=min(mi_y,j);
                ma_x=max(ma_x,i);
                ma_y=max(ma_y,j);
            }
    for(i=mi_x;i<=ma_x;i++,puts(""))
        for(j=mi_y;j<=ma_y;j++)putchar(s[i][j]);
}