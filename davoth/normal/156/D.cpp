#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,SQ=547,M=1e6+10;
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
ll n,m,k,t,sz[N],ans=1;
bool c[N];
vector<ll> adj[N];
void dfs(ll v, ll g){
    c[v]=true;
    sz[g]++;
    for(ll u : adj[v]){
        if(!c[u]) dfs(u,g);
    }
}
int main(){
    fast_io;
    cin >> n >> m >> k;
    for(ll i=0; i<m; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(ll i=1; i<=n; i++) if(!c[i]) dfs(i,t++),ans=ans*sz[t-1]%k;
    if(t==1) return cout << 1%k << '\n',0;
    ans=ans*pow(n,t-2,k)%k;
    cout << ans << '\n';
    return 0;
}