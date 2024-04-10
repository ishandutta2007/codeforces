#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=20,M=1e5+10,SQ=250,inf=1e9;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,f[N*4],lz[N*4],q,ans[N],h[N],fn[N];
vector<pll> adj[N];
vector<pair<ll,pll>> qu[N];
void shift(ll v, ll l, ll r){
    f[v]+=lz[v];
    if(r-l>1){
        lz[lc]+=lz[v];
        lz[rc]+=lz[v];
    }
    lz[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr) return;
    if(l==tl && r==tr){
        lz[v]+=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,min(tr,m),x);
    upd(rc,m,r,max(m,tl),tr,x);
    f[v]=min(f[lc],f[rc]);
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=tr) return INF;
    if(l==tl && r==tr) return f[v];
    ll m=(l+r)>>1;
    return min(get(lc,l,m,tl,min(m,tr)),get(rc,m,r,max(m,tl),tr));
}
void predfs(ll v){
    fn[v]=v;
    for(auto [u,w] : adj[v]){
        h[u]=h[v]+w;
        predfs(u);
        fn[v]=max(fn[v],fn[u]);
    }
}
void dfs(ll v){
    for(auto [i,g] : qu[v]){
        ans[i]=get(1,1,n+1,g.F,g.S+1);
    }
    for(auto [u,w] : adj[v]){
        upd(1,1,n+1,1,n+1,w);
        upd(1,1,n+1,u,fn[u]+1,-2*w);
        dfs(u);
        upd(1,1,n+1,1,n+1,-w);
        upd(1,1,n+1,u,fn[u]+1,2*w);
    }
}
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=2; i<=n; i++){
        ll u,w;
        cin >> u >> w;
        adj[u].pb({i,w});
    }
    predfs(1);
    for(ll i=1; i<=n; i++){
        upd(1,1,n+1,i,i+1,h[i]);
        if(!adj[i].empty()) upd(1,1,n+1,i,i+1,INF);
    }
    for(ll i=1; i<=q; i++){
        ll v,l,r;
        cin >> v >> l >> r;
        qu[v].pb({i,{l,r}});
    }
    dfs(1);
    for(ll i=1; i<=q; i++) cout << ans[i] << '\n';
    return 0;
}