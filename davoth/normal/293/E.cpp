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
const int N=3e6+10,LN=20,SQ=550,M=5e4+10;
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
vector<pll> adj[N],x,y;
bool hide[N];
ll sz[N],n,L,W,f[N],ans;
void upd(ll t, ll x){
    t++;
    while(t<N) f[t]+=x,t+=t&-t;
}
ll get(ll t, ll x=0){
    if(t<0) return 0;
    t++;
    while(t) x+=f[t],t-=t&-t;
    return x;
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
void dfs(ll v, ll h, ll H, ll p=-1){
    y.push_back({h,H});
    for(auto [u,w] : adj[v]){
        if(hide[u] || u==p) continue;
        dfs(u,h+w,H+1,v);
    }
}
void solve(ll v){
    plant(v);
    v = find_centroid(v , sz[v]);
    hide[v] = 1;
    x.push_back({0,0});
    for(auto [u,w] : adj[v]){
        if(hide[u]) continue;
        dfs(u,w,1,v);
        sort(y.begin(),y.end());
        ll pt=0;
        for(ll i=y.size()-1; i>=0; i--){
            while(pt<x.size() && x[pt].F+y[i].F<=W){
                upd(x[pt++].S,1);
                //cout << "#" << endl;
            }
            ans+=get(L-y[i].S);
        }
        while(pt) upd(x[--pt].S,-1);
        for(auto i : y) x.push_back(i);
        sort(x.begin(),x.end());
        y={};
    }
    x={};
    for(auto [u,w] : adj[v])
        if(!hide[u])
            solve(u);
}
int main(){
    fast_io;
    cin >> n >> L >> W;
    for(ll i=2; i<=n; i++){
        ll a=i,b,w;
        cin >> b >> w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }
    solve(1);
    cout << ans << '\n';
}