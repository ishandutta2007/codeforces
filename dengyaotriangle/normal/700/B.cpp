#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n,k;
bool g[maxn];
int sz[maxn],uz[maxn];
long long sl[maxn],ul[maxn];
vector<int> adj[maxn];

void dfs0(int u,int f){
    sz[u]=g[u];
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v!=f){
            dfs0(v,u);
            sz[u]+=sz[v];
            sl[u]+=sl[v]+sz[v];
        }
    }
}
long long ans=0;

void dfs1(int u,int f){
    int mp=uz[u];
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v!=f){
            mp=max(mp,sz[v]);
            uz[v]=uz[u]+sz[u]-sz[v];
            ul[v]=ul[u]+(sl[u]-(sl[v]+sz[v]))+uz[v];
            dfs1(v,u);
        }
    }
    if(mp<=k){
        ans=max(ans,ul[u]+sl[u]);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=(k*2);i++){
        int x;cin>>x;g[x]=1;
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);adj[v].push_back(u);
    }
    dfs0(1,0);
    dfs1(1,0);
    cout<<ans;
    return 0;
}//qwq