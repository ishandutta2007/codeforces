#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=30,M=1e6+10;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll t;
bool f[N],g[N];
vector<ll> adj[N];
void dfs(ll v){
    f[v]=1;
    g[v]=1;
    for(ll u : adj[v]) if(g[u]) g[v]=0;
    for(ll u : adj[v]) if(!f[u]) dfs(u);
}
void sfd(ll v){
    f[v]=1;
    for(ll u : adj[v]){
        if(!f[u] && (g[u] || g[v])) sfd(u);
    }
}
int main() {
    cin >> t;
    while(t--){
        ll n,m,c=0;
        cin >> n >> m;
        for(ll i=1; i<=n; i++) adj[i]={},f[i]=g[i]=0;
        for(ll i=0; i<m; i++){
            ll v,u;
            cin >> v >> u;
            adj[v].pb(u);
            adj[u].pb(v);
        }
        dfs(1);
        for(ll i=1; i<=n; i++) f[i]=0;
        sfd(1);
        for(ll i=1; i<=n; i++) if(!f[i]) c=1;
        if(c) cout << "NO\n";
        else{
            cout << "YES\n";
            ll k=0;
            for(ll i=1; i<=n; i++) if(g[i]) k++;
            cout << k << '\n';
            for(ll i=1; i<=n; i++) if(g[i]) cout << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}