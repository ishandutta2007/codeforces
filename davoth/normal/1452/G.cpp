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
vector<ll> adj[N];
bool hide[N];
ll sz[N],n,dist[N],ans[N],k;
map<ll,ll> f;
queue<ll> q;
void plant(ll v , ll p = 0){
    sz[v] = 1;
    for(auto u : adj[v])
        if(u != p && !hide[u]){
            plant(u , v);
            sz[v] += sz[u];
        }
}
ll find_centroid(ll v , ll n , ll p = 0){
    bool found = 1;
    while(found){
        found = 0;
        for(auto u : adj[v])
            if(u != p && !hide[u] && sz[u] * 2 > n){
                found = 1;
                p = v;
                v = u;
                break;
            }
    }
    return v;
}
void upd(ll t, ll x){
    t=N-t-1;
    while(t<N) f[t]=max(x,f[t]),t+=t&-t;
}
ll get(ll t, ll x=0){
    t=N-t-1;
    while(t) x=max(f[t],x),t-=t&-t;
    return x;
}
void dfs(ll v, ll h, ll p=0){
    if(dist[v]-h>0) upd(dist[v]-h,dist[v]);
    for(ll u : adj[v]){
        if(!hide[u] && u!=p) dfs(u,h+1,v);
    }
}
void sfd(ll v, ll h, ll p=0){
    ans[v]=max(ans[v],get(h+1));
    for(ll u : adj[v]){
        if(!hide[u] && u!=p) sfd(u,h+1,v);
    }
}
void solve(ll v){
    plant(v);
    v = find_centroid(v , sz[v]);
    hide[v] = 1;
    dfs(v,0);
    sfd(v,0);
    f.clear();
    for(ll u : adj[v]){
        if(!hide[u]) solve(u);
    }
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i < n; i++){
        ll a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cin >> k;
    memset(dist,63,sizeof dist);
    for(ll i=0; i<k; i++){
        ll v;
        cin >> v;
        q.push(v);
        dist[v]=0;
    }
    while(!q.empty()){
        ll v=q.front();
        q.pop();
        for(ll u : adj[v]){
            if(dist[u]>dist[v]+1) dist[u]=dist[v]+1,q.push(u);
        }
    }
    solve(1);
    for(ll i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}