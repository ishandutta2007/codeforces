#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10,LN=17,M=1e3+10,SQ=600,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=/*1000000007*/ 998244353;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
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
ll n,dp[N][3];
vector<ll> adj[N];
void dfs(ll v, ll p=0){
    dp[v][0]=dp[v][2]=1;
    for(ll u : adj[v]){
        if(u==p) continue;
        dfs(u,v);
        ll a=dp[v][0],b=dp[v][1],c=dp[v][2];
        dp[v][0]=a*(dp[u][0]+dp[u][1])%MOD;
        dp[v][1]=b*(dp[u][0]+dp[u][1])%MOD;
        dp[v][2]=c*(dp[u][0]+dp[u][1])%MOD;
        dp[v][1]=(dp[v][1]+dp[u][1]*b+dp[u][2]*c)%MOD;
        dp[v][2]=(dp[v][2]+c*dp[u][1])%MOD;
    }
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1);
    cout << (dp[1][0]+dp[1][1])%MOD << '\n';
    return 0;
}