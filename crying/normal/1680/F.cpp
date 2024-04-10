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
const int MAXN=1e6+10;
int T,n,m;
int fa[MAXN],u[MAXN],v[MAXN],tag[MAXN];
vector<int>e[MAXN],t[MAXN];
int col[MAXN],vis[MAXN];
int f[MAXN][20],depth[MAXN];
int ban[MAXN],sum[MAXN];
int Find(int x){
    if(fa[x]==x)return fa[x];
    return fa[x]=Find(fa[x]);
}
int dfs(int u,int c,int id=1){
    vis[u]=1;col[u]=c;
    for(auto v:e[u]){
        if(vis[v]){
            if(id==1 && col[v] != (c^1))return 0;
        }else{
            if(!dfs(v,c^1,id))return 0;
        }
    }
    return 1;
}
void dfs(int u){
    depth[u]=depth[f[u][0]]+1;
    rep(i,1,19)f[u][i]=f[f[u][i-1]][i-1];
    for(auto v:t[u])if(v!=f[u][0]){f[v][0]=u;dfs(v);}
}
int lca(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    per(j,19,0)if(depth[x]-(1<<j)>=depth[y])x=f[x][j];
    if(x==y)return x;
    per(j,19,0)if(f[x][j]!=f[y][j])x=f[x][j],y=f[y][j];
    return f[x][0];
}
int dis(int x,int y){return depth[x]+depth[y]-2*depth[lca(x,y)]+1;}
void spread(int u){
    for(auto v:t[u])if(v!=f[u][0]){
        spread(v);
        ban[u]+=ban[v];sum[u]+=sum[v];
    }
}
void solve(){
    cin>>n>>m;
    rep(i,1,n)fa[i]=i,e[i].clear(),t[i].clear();
    rep(i,1,m){
        tag[i]=0;
        cin>>u[i]>>v[i];
        int p=Find(u[i]),q=Find(v[i]);
        e[u[i]].push_back(v[i]);e[v[i]].push_back(u[i]);
        if(p==q)continue;
        tag[i]=1;fa[p]=q;t[u[i]].push_back(v[i]);t[v[i]].push_back(u[i]);
    }
    rep(i,1,n)col[i]=vis[i]=0;
    if(dfs(1,0)){
        cout<<"YES\n";
        rep(i,1,n)cout<<col[i];cout<<'\n';
        return;
    }
    rep(i,1,n)col[i]=vis[i]=ban[i]=sum[i]=0,e[i].clear();
    rep(i,1,n)rep(j,0,19)f[i][j]=0;
    dfs(1);
    int cnt=0;
    rep(i,1,m)if(!tag[i]){
        int len=dis(u[i],v[i]);
        if(even(len)){
            ban[u[i]]++;ban[v[i]]++;ban[lca(u[i],v[i])]-=2;
        }else{
            cnt++;
            sum[u[i]]++;sum[v[i]]++;sum[lca(u[i],v[i])]-=2;
        }
    }
    spread(1);
    int U=0,V=0;
    rep(i,2,n)if(!ban[i] && sum[i]==cnt){U=i;V=f[i][0];}
    rep(i,1,m)if(!tag[i]){
        int len=dis(u[i],v[i]);
        if(odd(len) && cnt==1)U=u[i],V=v[i];
    }
    if(!U){cout<<"NO\n";return;}
    cout<<"YES\n";
    rep(i,1,m){
        if(u[i]==U && v[i]==V)continue;
        if(u[i]==V && v[i]==U)continue;
        e[u[i]].push_back(v[i]);e[v[i]].push_back(u[i]);
    }
    col[U]=col[V]=1;vis[V]=1;
    dfs(U,1,0);dfs(V,1,0);
    rep(i,1,n)cout<<col[i];cout<<'\n';
    cnt=0;
    rep(i,1,m){
        assert(col[u[i]] || col[v[i]]);
        if(col[u[i]] && col[v[i]])cnt++;
    }
    assert(cnt<=1);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}