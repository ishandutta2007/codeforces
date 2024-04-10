#include<bits/stdc++.h>
using namespace std;
const int N=333;
int T,n,m,a[N][N],b[N][N],fl;
void solve(){
    scanf("%d%d",&n,&m);fl=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]),b[i][j]=4;
    for(int i=1;i<=n;i++)
        b[i][1]=b[i][m]=3;
    for(int i=1;i<=m;i++)
        b[1][i]=b[n][i]=3;
    b[1][1]=b[1][m]=b[n][m]=b[n][1]=2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]>b[i][j])fl=0;
    puts(fl?"YES":"NO");
    if(fl)for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=m;j++)printf("%d ",b[i][j]);
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}