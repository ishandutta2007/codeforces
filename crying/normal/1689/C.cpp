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
const int MAXN=3e5+10;
int T,n,ans,sz[MAXN],fa[MAXN];
int lc[MAXN],rc[MAXN],u[MAXN],v[MAXN];
int dp[MAXN];
vector<int>e[MAXN];
void dfs(int u){
    sz[u]=1;
    for(auto v:e[u])if(v!=fa[u]){
        fa[v]=u;dfs(v);sz[u]+=sz[v];
    }
}
void dfs2(int u){
    dp[u]=0;
    if(!lc[u] && !rc[u])return;
    if(lc[u])dfs2(lc[u]);
    if(rc[u])dfs2(rc[u]);
    dp[u]=max(dp[lc[u]]+sz[rc[u]]-1,dp[rc[u]]+sz[lc[u]]-1);
}
void solve(){
    cin>>n;rep(i,1,n)e[i].clear(),fa[i]=lc[i]=rc[i]=0;
    rep(i,1,n-1){
        cin>>u[i]>>v[i];
        e[u[i]].push_back(v[i]);e[v[i]].push_back(u[i]);
    }
    dfs(1);
    rep(i,2,n)if(!lc[fa[i]])lc[fa[i]]=i;else rc[fa[i]]=i;
    ans=0;
    dfs2(1);
    cout<<dp[1]<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();


    return 0;
}