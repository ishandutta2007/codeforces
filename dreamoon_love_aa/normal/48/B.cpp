#include<stdio.h>
#include<algorithm>
using namespace std;
int a[55][55];
main(){
    int i,j,n,m,s,t,an=100000;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
    scanf("%d%d",&s,&t);
    for(i=1;i<=n;i++)
        for(j=2;j<=m;j++)a[i][j]+=a[i][j-1];
    for(i=1;i<=m;i++)
        for(j=2;j<=n;j++)a[j][i]+=a[j-1][i];
    for(i=s;i<=n;i++)
        for(j=t;j<=m;j++)
            an=min(an,a[i][j]+a[i-s][j-t]-a[i][j-t]-a[i-s][j]);
    for(i=t;i<=n;i++)
        for(j=s;j<=m;j++)
            an=min(an,a[i][j]+a[i-t][j-s]-a[i][j-s]-a[i-t][j]);
    printf("%d\n",an);
}