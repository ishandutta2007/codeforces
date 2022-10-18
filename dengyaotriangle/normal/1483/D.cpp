#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=605;

int n;
long long w[maxn][maxn],d[maxn][maxn],c[maxn][maxn];
long long rd[maxn];

int main(){
    int m;
    cin>>n>>m;
    memset(w,0x3f,sizeof(w));
    for(int i=1;i<=m;i++){
        int u,v,x;cin>>u>>v>>x;
        w[u][v]=w[v][u]=x;
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int u,v,x;
        cin>>u>>v>>x;
        d[u][v]=d[v][u]=x;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)c[i][j]=i==j?0:w[i][j];
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int i=1;i<=n;i++)rd[i]=-1;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                rd[k]=max(rd[k],d[j][k]-c[i][j]);
            }
        }
        for(int j=1;j<=n;j++)if(w[i][j]<INT_MAX){
            bool ok=0;
            for(int k=1;k<=n;k++){
                if(c[j][k]+w[i][j]<=rd[k]){
                    ok=1;break;
                }
            }
            ans+=ok;
        }
    }
    cout<<ans/2;
    return 0;
}