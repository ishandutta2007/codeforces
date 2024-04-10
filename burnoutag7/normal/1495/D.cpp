//
//
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int n,m,d[405][405];
vector<int> g[405];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++)d[i][i]=0;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        d[u][v]=d[v][u]=1;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ll ans=1;
            int cnt=0;
            for(int x=1;x<=n;x++)if(d[x][i]+d[x][j]>d[i][j]){
                int fa=0;//too many fathers lmao
                for(int y:g[x])fa+=d[y][i]+1==d[x][i]&&d[y][j]+1==d[x][j];
                ans=ans*fa%mod;
            }else cnt++;
            if(cnt!=d[i][j]+1)ans=0;
            cout<<ans<<' ';
        }
        cout<<'\n';
    }

    return 0;
}