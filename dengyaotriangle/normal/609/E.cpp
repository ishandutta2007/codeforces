#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
const int maxl=25;

struct edge{
    int u,v;
    long long w;
    int i;
};
bool cmp(edge a,edge b){
    return a.w<b.w;
}

int dsu[maxn];
edge e[maxn];
int n,m;
int dep[maxn];
int fa[maxl][maxn],mi[maxl][maxn];
long long ae[maxn];
vector<pair<int,long long> > adj[maxn];

int grt(int u){
    if(dsu[u]==u)return u;
    dsu[u]=grt(dsu[u]);
    return dsu[u];
}

void mrg(int a,int b){
    a=grt(a);b=grt(b);
    dsu[b]=a;
}

bool ism(int a,int b){
    return grt(a)==grt(b);
}

void dfs(int u){
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i].first;
        long long w=adj[u][i].second;
        if(!dep[v]){
            dep[v]=dep[u]+1;
            fa[0][v]=u;
            mi[0][v]=w;
            dfs(v);
        }
    }
}

int gmin(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    int miv=0;
    for(int i=maxl-1;i>=0;i--){
        if(dep[fa[i][v]]>=dep[u]){
            miv=max(miv,mi[i][v]);
            v=fa[i][v];
        }
    }
    if(u==v) return miv;
    for(int i=maxl-1;i>=0;i--){
        if(fa[i][u]!=fa[i][v]){
            miv=max(miv,mi[i][v]);
            miv=max(miv,mi[i][u]);
            u=fa[i][u];
            v=fa[i][v];
        }
    }
    return max(miv,max(mi[0][u],mi[0][v]));
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)dsu[i]=i;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
        e[i].i=i;
    }
    sort(e+1,e+1+m,cmp);
    long long ans=0;
    for(int i=1;i<=m;i++){
        if(!ism(e[i].u,e[i].v)){
            mrg(e[i].u,e[i].v);
            ans+=e[i].w;
            adj[e[i].u].push_back(make_pair(e[i].v,e[i].w));
            adj[e[i].v].push_back(make_pair(e[i].u,e[i].w));
        }
    }
    dep[1]=1;
    dfs(1);
    for(int i=1;i<maxl;i++){
        for(int j=1;j<=n;j++){
            fa[i][j]=fa[i-1][fa[i-1][j]];
            mi[i][j]=max(mi[i-1][j],mi[i-1][fa[i-1][j]]);
        }
    }
    for(int i=1;i<=m;i++){
        ae[e[i].i]=ans-gmin(e[i].u,e[i].v)+e[i].w;
    }
    for(int i=1;i<=m;i++)cout<<ae[i]<<'\n';
    return 0;
}