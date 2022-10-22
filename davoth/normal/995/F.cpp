#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const ll N=3e3+10,LN=20,SQ=550,M=5e4+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,D,inv[N],f[N],dp[N][N],t[N],ans;
vector<ll> adj[N];
void dfs(ll v){
    for(ll i=1; i<N; i++) dp[v][i]=1;
    for(ll u : adj[v]){
        dfs(u);
        for(ll i=1; i<N; i++) dp[v][i]=dp[v][i]*dp[u][i]%MOD;
    }
    for(ll i=1; i<N; i++) dp[v][i]=(dp[v][i]+dp[v][i-1])%MOD;
}
ll C(ll x, ll y){
    if(x<y) return 0;
    return f[x]*inv[y]%MOD*inv[x-y]%MOD;
}
int main(){
    fast_io;
    f[0]=inv[0]=1;
    for(ll i=1; i<N; i++) f[i]=i*f[i-1]%MOD,inv[i]=pow(f[i],MOD-2,MOD);
    cin >> n >> D;
    for(ll i=2; i<=n; i++){
        ll x;
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1);
    t[0]=1;
    for(ll i=1; i<=n; i++){
        t[i]=t[i-1]*(D-i+1)%MOD*pow(i,MOD-2,MOD)%MOD;
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<i; j++){
            dp[1][i]=(dp[1][i]-C(i,j)*dp[1][j]%MOD+MOD)%MOD;
        }
        ans=(ans+dp[1][i]*t[i]%MOD)%MOD;
    }
    cout << ans << '\n';
    return 0;
}