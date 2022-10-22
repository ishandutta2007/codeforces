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
const int N=1e5+10,LN=18,M=1e6+10,SQ=500,B=737,inf=1e9;
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
ll n,m,h[N],ps[N],f[N],P[LN][N];
vector<pll> adj[N];
pll dp[2][N];
ll lca(ll v, ll u){
    if(h[v]>h[u]) swap(v,u);
    for(ll i=LN; i--; ){
        if(h[P[i][u]]>=h[v]) u=P[i][u];
    }
    if(v==u) return v;
    for(ll i=LN; i--; ){
        if(P[i][u]!=P[i][v]) v=P[i][v],u=P[i][u];
    }
    return P[0][v];
}
void dfs(ll v){
    dp[0][v]={-inf,v};
    if(f[v]) dp[0][v].F=0;
    for(auto [u,w] : adj[v]){
        if(u==P[0][v]) continue;
        P[0][u]=v;
        h[u]=h[v]+1;
        dfs(u);
        if(dp[0][u].F+w>dp[0][v].F){
            dp[0][v]={dp[0][u].F+w,dp[0][u].S};
        }else if(dp[0][v].F==dp[0][u].F+w) dp[0][v].S=v;
    }
}
void sfd(ll v){
    if(dp[1][v].F<0 && f[v]) dp[1][v]={0,v};
    vector<pll> vec={dp[1][v]};
    for(auto [u,w] : adj[v]) if(u!=P[0][v]) vec.pb({dp[0][u].F+w,dp[0][u].S});
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    ll x=vec[0].F,y=0;
    for(pll p : vec) if(p.F==x) y++;
    for(auto [u,w] : adj[v]){
        if(u==P[0][v]) continue;
        if(dp[0][u].S!=vec[0].S) dp[1][u]=vec[0];
        else dp[1][u]=vec[1];
        if((dp[0][u].F+w==x && y>2) || (dp[0][u].F+w<x && y>1)) dp[1][u].S=v;
        dp[1][u].F+=w;
    }
    for(auto [u,w] : adj[v]){
        if(u!=P[0][v]) sfd(u);
    }
    if(!f[v]) return;
    pll p=dp[0][v];
    if(dp[1][v].F>p.F) p=dp[1][v];
    else if(dp[1][v].F==p.F) p.S=v;
    ll z=lca(v,p.S);
    ps[v]++;
    ps[p.S]++;
    ps[z]--;
    ps[P[0][z]]--;
}
void calc(ll v){
    for(auto [u,w] : adj[v]){
        if(u!=P[0][v]){
            calc(u);
            ps[v]+=ps[u];
        }
    }
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=m; i++){
        ll x;
        cin >> x;
        f[x]=1;
    }
    for(ll i=1; i<n; i++){
        ll v,u,w;
        cin >> v >> u >> w;
        adj[v].pb({u,w});
        adj[u].pb({v,w});
    }
    h[1]=1;
    dfs(1);
    for(ll i=1; i<LN; i++) for(ll j=1; j<=n; j++) P[i][j]=P[i-1][P[i-1][j]];
    for(ll i=1; i<=n; i++) dp[1][i]={-inf,i};
    sfd(1);
    calc(1);
    ll x=0,y=0;
    for(ll i=1; i<=n; i++){
        if(!f[i]){
            if(ps[i]>x){
                x=ps[i];
                y=0;
            }
            if(x==ps[i]) y++;
        }
    }
    cout << x << ' ' << y << '\n';
    return 0;
}