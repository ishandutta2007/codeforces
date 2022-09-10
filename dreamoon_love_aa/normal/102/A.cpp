#include<stdio.h>
int a[101];
bool match[101][101];
main(){
    int n,m,x,y,i,j,k,an=-1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    while(m--){
        scanf("%d%d",&x,&y);
        match[x][y]=match[y][x]=1;
    }
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            for(k=j+1;k<=n;k++){
                if(match[i][j]&&match[j][k]&&match[i][k]){
                    if(an==-1||an>a[i]+a[j]+a[k])
                        an=a[i]+a[j]+a[k];
                }
            }
    printf("%d\n",an);
}