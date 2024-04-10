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
const int N=3e5+10,LN=20,SQ=550,M=5e4+10;
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
vector<pll> adj[N];
bool hide[N];
ll sz[N],n,m,phi,ans,lans,PO[N];
map<ll,ll> mp[N];
void init() {
    phi = m;
    int t = m;
    for (int i = 2; i * i <= t; i++) {
        if (t % i) continue;
        while (t % i == 0) t /= i;
        phi -= phi / i;
    }
    if (t > 1) phi -= phi / t;
    phi--;
}
void plant(ll v , ll p = 0-1){
    sz[v] = 1;
    for(auto [u,w] : adj[v])
        if(u != p && !hide[u]){
            plant(u , v);
            sz[v] += sz[u];
        }
}
ll find_centroid(ll v , ll n , ll p = -1){
    bool found = 1;
    while(found){
        found = 0;
        for(auto [u,w] : adj[v])
            if(u != p && !hide[u] && sz[u] * 2 > n){
                found = 1;
                p = v;
                v = u;
                break;
            }
    }
    return v;
}
void dfs(ll v, ll h, ll P, ll H, ll p=-1){
    mp[P][h]++;
    for(auto [u,w] : adj[v]){
        if(hide[u] || u==p) continue;
        dfs(u,(h+w*pow(10,H,m))%m,P,H+1,v);
    }
}
void sfd(ll v, ll h, ll P, ll H, ll p=-1){
    ll k=(m-h)*PO[H]%m;
    ans+=mp[P][k];
    for(auto [u,w] : adj[v]){
        if(hide[u] || u==p) continue;
        sfd(u,(h*10+w)%m,P,H+1,v);
    }
}
void solve(ll v){
    plant(v);
    v = find_centroid(v , sz[v]);
    hide[v] = 1;
    mp[v][0]++;
    lans=ans;
    for(auto [u,w] : adj[v]){
        if(!hide[u]) sfd(u,w%m,v,1,v),dfs(u,w%m,v,1,v);
    }
    mp[v].clear();
    for(ll i=adj[v].size()-1; i>=0; i--){
        auto [u,w]=adj[v][i];
        if(!hide[u]) sfd(u,w%m,v,1,v),dfs(u,w%m,v,1,v);
    }
    ans+=mp[v][0];
    for(auto [u,w] : adj[v])
        if(!hide[u])
            solve(u);
}
int main(){
    fast_io;
    cin >> n >> m;
    if(m==1) return cout << n*(n-1) << '\n', 0;
    init();
    ll g=pow(10,phi,m);
    PO[0]=1;
    for(ll i=1; i<N; i++) PO[i]=PO[i-1]*g%m;
    for(ll i=1; i < n; i++){
        ll a , b,w;
        cin >> a >> b >> w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }
    solve(0);
    cout << ans << '\n';
}