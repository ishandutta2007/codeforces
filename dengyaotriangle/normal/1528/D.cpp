#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=605;

int n,m;
int adj[maxn][maxn];
int dis[maxn];
bool vis[maxn];
int tmp[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    memset(adj,0x3f,sizeof(adj));
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a][b]=c;
    }

    for(int u=0;u<n;u++)for(int t=0;t<2;t++){
        for(int i=1;i<n;i++)adj[u][i]=min(adj[u][i],adj[u][i-1]+1);
        adj[u][0]=min(adj[u][0],adj[u][n-1]+1);
    }
    for(int i=0;i<n;i++){
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[i]=0;
        for(int t=1;t<=n;t++){
            int u=-1;
            for(int i=0;i<n;i++){
                if(!vis[i]&&(u==-1||dis[i]<dis[u]))u=i;
            }
            vis[u]=1;
            int dlt=dis[u]%n;
            for(int i=0;i<dlt;i++){
                tmp[i]=adj[u][i-dlt+n];
            }
            for(int i=dlt;i<n;i++){
                tmp[i]=adj[u][i-dlt];
            }
            for(int j=0;j<n;j++){
                if(!vis[j]){
                    
                    if(dis[u]+tmp[j]<dis[j]){
                        dis[j]=dis[u]+tmp[j];
                    }
                }
            }
        }
        for(int j=0;j<n;j++)cout<<dis[j]<<' ';
        cout<<'\n';
    }
    return 0;
}