#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;
const int maxl=20;

int n,m;
vector<int> adj[maxn];
int dep[maxn],fa[maxl][maxn],sze[maxn];

void dfs(int u){
    sze[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!dep[v]){
            dep[v]=dep[u]+1;
            fa[0][v]=u;
            dfs(v);
            sze[u]+=sze[v];
        }
    }
}

int calc(int u,int v){
    int u1=u,v1=v,lca;
    if(dep[u1]>dep[v1]) swap(u1,v1);
    for(int i=maxl-1;i>=0;i--){
        if(dep[fa[i][v1]]>=dep[u1])v1=fa[i][v1];
    }
    if(u1==v1)lca=u1;
    else{
        for(int i=maxl-1;i>=0;i--){
            if(fa[i][u1]!=fa[i][v1]){
                u1=fa[i][u1];v1=fa[i][v1];
            }
        }
        lca=fa[0][u1];
    }
    int dis=dep[u]+dep[v]-dep[lca]*2;
    if(dis&1) return 0;
    dis>>=1;
    if(dep[u]==dep[v]){
        return n-sze[u1]-sze[v1];
    }else{
        if(dep[v]>dep[u]){
            swap(u,v);swap(u1,v1);
        }
        int d1=dis-1;
        for(int i=maxl-1;i>=0;i--){
            if((1<<i)<=d1){
                d1-=(1<<i);
                u=fa[i][u];
            }
        }
        return sze[fa[0][u]]-sze[u];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[1]=1;
    dfs(1);
    for(int i=1;i<maxl;i++){
        for(int j=1;j<=n;j++){
            fa[i][j]=fa[i-1][fa[i-1][j]];
        }
    }
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        if(u==v){
            cout<<n<<'\n';
        }else{
            cout<<calc(u,v)<<'\n';
        }
    }
    return 0;
}