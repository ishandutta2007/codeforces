#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;
const int maxl=20;

int dep[maxn],fa[maxl][maxn],dfn[maxn],otn[maxn],c1;
int n;
vector<int> adj[maxn];

void dfs(int u){
    dfn[u]=++c1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!dep[v]){
            fa[0][v]=u;
            dep[v]=dep[u]+1;
            dfs(v);
        }
    }
    otn[u]=c1;
}

int e0,e1;
int lca(int u,int v){
    if(dep[v]<dep[u]) swap(u,v);
    for(int i=maxl-1;i>=0;i--){
        if(dep[fa[i][v]]>=dep[u]) v=fa[i][v];
    }
    if(u==v) return u;
    for(int i=maxl-1;i>=0;i--){
        if(fa[i][u]!=fa[i][v]){
            u=fa[i][u];v=fa[i][v];
        }
    }
    e0=u,e1=v;
    return fa[0][u];
}

inline int gdis(int u,int v){
    int l=lca(u,v);
    return dep[u]+dep[v]-(dep[l]<<1)+1;
}
inline int calc(int s,int x,int y){
    int a=gdis(s,x),b=gdis(s,y),v=gdis(x,y);
    return (a+b-v)/2+1;
}
int main(){
    int q;
    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u;
        adj[u].push_back(i+1);
        adj[i+1].push_back(u);
    }
    dep[1]=1;
    dfs(1);
    for(int i=1;i<maxl;i++){
        for(int j=1;j<=n;j++){
            fa[i][j]=fa[i-1][fa[i-1][j]];
        }
    }
    while(q--){
        int u,v,w;
        cin>>u>>v>>w;
        cout<<max(calc(u,v,w),max(calc(v,u,w),calc(w,u,v)))<<'\n';
    }
    return 0;
}