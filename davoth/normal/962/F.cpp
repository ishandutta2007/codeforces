#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=22,SQ=547,M=4.2e6+10;
const ll INF=1e18;
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
ll n,m,h[N],cnt[N],a[N],b[N],bd[N];
bool tr[N],f[N];
pll ed[N];
vector<pll> adj[N];
void dfs(ll v){
    f[v]=1;
    for(auto [i,u] : adj[v]){
        if(!f[u]) h[u]=h[v]+1,tr[i]=1,dfs(u);
    }
}
void calc(ll v){
    f[v]=1;
    a[v]=cnt[v];
    for(auto [i,u] : adj[v]){
        if(!f[u]) calc(u),a[v]+=a[u];
    }
}
void mx(ll v){
    f[v]=1;
    for(auto [i,u] : adj[v]){
        if(f[u]) continue;
        b[u]=b[v];
        if(a[u]>=2) b[u]=h[u];
        mx(u);
    }
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=0; i<m; i++){
        cin >> ed[i].F >> ed[i].S;
        adj[ed[i].F].pb({i,ed[i].S});
        adj[ed[i].S].pb({i,ed[i].F});
    }
    for(ll i=1; i<=n; i++) if(!f[i]) dfs(i);
    for(ll i=0; i<m; i++){
        if(h[ed[i].F]>h[ed[i].S]) swap(ed[i].F,ed[i].S);
        auto [v,u]=ed[i];
        if(!tr[i]) cnt[u]++,cnt[v]--;
    }
    memset(f,0,sizeof f);
    for(ll i=1; i<=n; i++) if(!f[i]) calc(i);
    memset(f,0,sizeof f);
    for(ll i=1; i<=n; i++) if(!f[i]) mx(i);
    for(ll i=0; i<m; i++){
        if(tr[i]) continue;
        auto [v,u]=ed[i];
        if(h[v]<b[u]) bd[i]=1,cnt[v]--,cnt[u]++;
    }
    memset(f,0,sizeof f);
    for(ll i=1; i<=n; i++) if(!f[i]) calc(i);
    for(ll i=0; i<m; i++){
        auto [v,u]=ed[i];
        if(tr[i] && a[u]!=1) bd[i]=1;
    }
    vector<ll> ans;
    for(ll i=0; i<m; i++) if(!bd[i]) ans.pb(i+1);
    cout << ans.size() << '\n';
    for(ll i : ans) cout << i << ' ';
    cout << '\n';
    return 0;
}