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
const int N=2e5+10,LN=20,M=2e4+10,SQ=350,B=737,inf=1e9;
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
ll n,k,a[N],sz[N],dp[N],pd[N],m1[N],m2[N],ans,mn=-1;
vector<ll> adj[N];
void dfs(ll v, ll p, ll m){
    sz[v]=1;
    dp[v]=0;
    if(a[v]<m){
        for(ll u : adj[v]){
            if(u!=p){
                dfs(u,v,m);
                sz[v]+=sz[u];
            }
        }
        return;
    }
    dp[v]=1;
    m1[v]=m2[v]=0;
    for(ll u : adj[v]){
        if(u==p) continue;
        dfs(u,v,m);
        sz[v]+=sz[u];
        if(dp[u]==sz[u]) dp[v]+=sz[u];
        else{
            if(m1[v]<dp[u]){
                m2[v]=m1[v];
                m1[v]=dp[u];
            }else if(m2[v]<dp[u]) m2[v]=dp[u];
        }
    }
    dp[v]+=m1[v];
    ans=max(ans,dp[v]+m2[v]);
}
int main(){
    fast_io;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(mn==-1 || a[i]<a[mn]) mn=i;
    }
    for(int i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    ll l=1,r=1e6+1;
    while(r-l>1){
        ll m=(l+r)>>1;
        ans=0;
        dfs(mn,0,m);
        if(ans>=k) l=m;
        else r=m;
    }
    cout << l << '\n';
    return 0;
}