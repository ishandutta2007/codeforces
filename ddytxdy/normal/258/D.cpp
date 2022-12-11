#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,a[N];double f[N][N],g[N][N],ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)f[i][j]=a[i]>a[j];
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);if(x>y)swap(x,y);
        memcpy(g,f,sizeof(f));f[x][y]=0.5;
        for(int j=1;j<x;j++)f[j][x]=f[j][y]=0.5*(g[j][x]+g[j][y]);
        for(int j=x+1;j<y;j++)f[x][j]=0.5*(g[x][j]+1-g[j][y]),f[j][y]=0.5*(g[j][y]+1-g[x][j]);
        for(int j=y+1;j<=n;j++)f[x][j]=f[y][j]=0.5*(g[x][j]+g[y][j]);
    }
    for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)ans+=f[i][j];
    printf("%.9f",ans);
}