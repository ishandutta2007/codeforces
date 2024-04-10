#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
int n,m,q,P[N],h[N],dp[N],p[LN][N],t,c[N],x[N],y[N],z[N];
vector<ll> adj[N];
vector<pll> ed,ad[N];
int gp(int x){
    return P[x]?P[x]=gp(P[x]):x;
}
void uni(int v, int u){
    v=gp(v);
    u=gp(u);
    if(v==u) return;
    P[u]=v;
}
void dfs(int v, int p){
    dp[v]=h[v];
    for(auto [u,i] : ad[v]){
        if(i==p) continue;
        if(!h[u]){
            h[u]=h[v]+1;
            dfs(u,i);
            dp[v]=min(dp[v],dp[u]);
            if(dp[u]<=h[v]) uni(v,u);
            else ed.pb({v,u});
        }else{
            dp[v]=min(dp[v],h[u]);
            uni(v,u);
        }
    }
}
void sfd(int v, int P){
    c[v]=t;
    p[0][v]=P;
    for(int i=1; i<LN; i++) p[i][v]=p[i-1][p[i-1][v]];
    for(int u : adj[v]){
        if(u!=P){
            h[u]=h[v]+1;
            sfd(u,v);
        }
    }
}
int lca(int v, int u){
    if(h[v]>h[u]) swap(v,u);
    for(int i=LN; i--;){
        if(h[p[i][u]]>=h[v]) u=p[i][u];
    }
    if(v==u) return v;
    for(int i=LN; i--;){
        if(p[i][u]!=p[i][v]) v=p[i][v],u=p[i][u];
    }
    return p[0][v];
}
void bruh(int v, int P){
    for(int u : adj[v]){
        if(u==P) continue;
        bruh(u,v);
        x[v]+=x[u];
        y[v]+=y[u];
        z[v]+=z[u];
    }
    if(x[v]!=z[v] && y[v]!=z[v]){
        cout << "No\n";
        exit(0);
    }
}
int main(){
    fast_io;
    cin >> n >> m >> q;
    for(int i=1; i<=m; i++){
        int v,u;
        cin >> v >> u;
        ad[v].pb({u,i});
        ad[u].pb({v,i});
    }
    for(int i=1; i<=n; i++){
        if(!h[i]){
            h[i]=1;
            dfs(i,0);
        }
        adj[i]={};
    }
    for(auto [v,u] : ed){
        v=gp(v);
        u=gp(u);
        adj[v].pb(u);
        adj[u].pb(v);
    }
    for(int i=1; i<=n; i++){
        if(gp(i)!=i) continue;
        if(!p[0][i]){
            h[i]=1;
            sfd(i,0);
            t++;
        }
    }
    for(int i=0; i<q; i++){
        int v,u;
        cin >> v >> u;
        v=gp(v);
        u=gp(u);
        if(c[v]!=c[u]){
            cout << "No\n";
            return 0;
        }
        x[v]++;
        y[u]++;
        z[lca(v,u)]++;
    }
    for(int i=1; i<=n; i++){
        if(gp(i)==i && !p[0][i]) bruh(i,0);
    }
    cout << "Yes\n";
    return 0;
}