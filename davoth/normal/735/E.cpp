#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e15;
const ld ep=1e-7;
const int MH=1000696969,MOD=1000000007,MD=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
ll n,k,dp[N][42],ans;
vector<ll> adj[N];
void dfs(ll v, ll p){
    dp[v][0]=dp[v][k+1]=1;
    for(ll u : adj[v]){
        if(u==p) continue;
        dfs(u,v);
        ll t[42];
        memset(t,0,sizeof t);
        for(ll i=0; i<=k+k; i++){
            for(ll j=0; j<=k+k; j++){
                ll g;
                if(i<=k && j<=k){
                    g=min(i,j+1);
                }else if(i>k && j>k){
                    g=max(i,j+1);
                }else if(i<=k && j>k){
                    if(i+j<=k+k) g=i;
                    else g=j+1;
                }else{
                    if(i+j<=k+k) g=j+1;
                    else g=i;
                }
                t[g]=(t[g]+dp[v][i]*dp[u][j])%MOD;
            }
        }
        for(ll i=0; i<=k+k; i++) dp[v][i]=t[i];
    }
}
int main(){
    fast_io;
    cin >> n >> k;
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1,0);
    for(ll i=0; i<=k; i++) ans=(ans+dp[1][i])%MOD;
    cout << ans << '\n';
    return 0;
}