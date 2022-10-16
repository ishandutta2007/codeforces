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
const int MAXN=5e5+10;
int n,u[MAXN],v[MAXN],w[MAXN],fa[MAXN],fac[MAXN];
int col[MAXN],sz[MAXN],val[MAXN];
int topv[MAXN];
vector<int>bucket[MAXN],top[MAXN];
vector<int>e[MAXN],g[MAXN];
ll ans;
void dfs1(int u){
    sz[u]=1;
    for(auto v:e[u])if(v!=fa[u]){
        fa[v]=u;dfs1(v);sz[u]+=sz[v];
    }
}
void dfs2(int u){
    if(u!=1){
        if(bucket[col[u]].size())fac[u]=bucket[col[u]].back();
        bucket[col[u]].push_back(u);
    }
    for(auto v:e[u])if(v!=fa[u])dfs2(v);
    if(u!=1)bucket[col[u]].pop_back();
}
void dfs3(int u){
    if(u!=1){
        val[u]=sz[u];
        for(auto v:g[u])val[u]-=sz[v];
        if(fac[u]){
            ans+=1ll*val[u]*val[fac[u]];
        }else{
            ans+=1ll*val[u]*topv[col[u]];
        }
    }  
    for(auto v:e[u])if(v!=fa[u])dfs3(v);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n-1){
        cin>>u[i]>>v[i]>>w[i];
        e[u[i]].push_back(v[i]);e[v[i]].push_back(u[i]);
    }
    dfs1(1);
    rep(i,1,n-1){
        if(fa[u[i]]==v[i])swap(u[i],v[i]);
        col[v[i]]=w[i];
    }
    dfs2(1);
    rep(i,1,n)if(fac[i])g[fac[i]].push_back(i);else if(col[i])top[col[i]].push_back(i);
    rep(i,1,n){
        topv[i]=n;
        for(auto u:top[i])topv[i]-=sz[u];
    }
    dfs3(1);
    cout<<ans<<endl;
    return 0;
}