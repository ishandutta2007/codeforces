#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int n,m;
int u[MAXN],v[MAXN],tag[MAXN];
struct DSU{
    int fa[MAXN];
    int Find(int x){
        if(fa[x]==x)return x;
        return fa[x]=Find(fa[x]);
    }
    void Merge(int x,int y){
        x=Find(x);y=Find(y);
        if(x==y)return;
        fa[x]=y;
    }
}dsu;
vector<int>e[MAXN];
int depth[MAXN],fa[MAXN][20];
void dfs(int u){
    depth[u]=depth[fa[u][0]]+1;
    rep(j,1,19)fa[u][j]=fa[fa[u][j-1]][j-1];
    for(auto v:e[u])if(v==fa[u][0])continue;else{
        fa[v][0]=u;
        dfs(v);
    }
}
int LCA(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    per(j,19,0)if(depth[x]-(1<<j)>=depth[y])x=fa[x][j];
    if(x==y)return x;
    per(j,19,0)if(fa[x][j]!=fa[y][j])x=fa[x][j],y=fa[y][j];
    return fa[x][0];    
}
int Find(int u,int lim){
    per(j,19,0)if(depth[u]-(1<<j)>depth[lim])u=fa[u][j];
    return u;
}
int resttag[MAXN];
int all;

void upd(int l,int r){
    if(depth[l]<depth[r])swap(l,r);
    int lca=LCA(l,r);
    if(lca!=r){ 
        all++;
        resttag[l]--;resttag[r]--;
    }else{
        resttag[Find(l,r)]++;
        resttag[l]--;
    }
}
void spread(int u){
    resttag[u]+=resttag[fa[u][0]];
    for(auto v:e[u])if(v==fa[u][0])continue;else spread(v);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n)dsu.fa[i]=i;
    rep(i,1,m){
        cin>>u[i]>>v[i];
        if(dsu.Find(u[i])==dsu.Find(v[i]))continue;
        tag[i]=1;dsu.Merge(u[i],v[i]);
        e[u[i]].push_back(v[i]);e[v[i]].push_back(u[i]);
    }
    dfs(1);
    rep(i,1,m)if(!tag[i])upd(u[i],v[i]);
    spread(1);
    rep(i,1,n)if(all+resttag[i]==0){
        cout<<'1';
    }else{
        cout<<'0';
    }


    return 0;
}