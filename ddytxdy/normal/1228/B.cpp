#include<bits/stdc++.h>
using namespace std;
const int N=1e3+50,mod=1e9+7;
int n,m,a[N],b[N],c[N][N],ans=1;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++)c[i][j]=1;
        c[i][a[i]+1]=2;
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=b[j];i++){
            if(c[i][j]==2)puts("0"),exit(0);
            c[i][j]=1;
        }
        if(c[b[j]+1][j]==1)puts("0"),exit(0);
        c[b[j]+1][j]=2;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)!c[i][j]?ans=ans*2%mod:0;
    printf("%d\n",ans);
    return 0;
}