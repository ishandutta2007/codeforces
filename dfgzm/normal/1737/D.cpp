#include<bits/stdc++.h>
using namespace std;
const int maxn=510,maxm=maxn*maxn;
const long long inf=1e12;
struct edge{
    int next,to;
}e[maxm*2];
int head[maxn],len;
void add(int x,int y){
    e[++len]={head[x],y};
    head[x]=len;
}
int i,j,k,n,m;
long long a[maxn][maxn];
long long dis[maxn][maxn];
int main(){
    int T;
    cin>>T;
    cerr<<inf<<endl;
    while(T--){
        cin>>n>>m;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=(i==j?0:inf);
        for(i=1;i<=m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[x][y]=a[y][x]=min(a[x][y],(long long)z);
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                dis[i][j]=i==j?0:(a[i][j]==inf?inf:1);
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
        long long Ans=inf;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++){
                if(i==j)continue;
                // cerr<<i<<' '<<j<<' '<<dis[1][i]<<' '<<dis[j][n]<<endl;
                Ans=min(Ans,1ll*a[i][j]*(dis[1][i]+dis[j][n]+1));
                for(k=1;k<=n;k++)
                    Ans=min(Ans,1ll*a[i][j]*(dis[i][k]+dis[1][k]+dis[k][n]+2));
            }
        cout<<Ans<<endl;
    }
}