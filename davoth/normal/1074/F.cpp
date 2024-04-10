#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=19,M=1.1e7+10,SQ=350,B=737,inf=1e9;
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
ll n,q,st[N],fn[N],t,P[LN][N],f[N*4],g[N*4],lz[N*4],H[N];
vector<ll> adj[N];
map<pll,ll> pm;
void dfs(ll v, ll p){
    P[0][v]=p;
    H[v]=H[p]+1;
    for(ll i=1; i<LN; i++) P[i][v]=P[i-1][P[i-1][v]];
    st[v]=++t;
    for(ll u : adj[v]){
        if(u!=p) dfs(u,v);
    }
    fn[v]=t;
}
ll pr(ll v, ll t){
    for(ll i=LN; i--;){
        if(t&(1<<i)) v=P[i][v];
    }
    return v;
}
void build(ll v, ll l, ll r){
    g[v]=r-l;
    if(r-l>1){
        ll m=(l+r)>>1;
        build(lc,l,m);
        build(rc,m,r);
    }
}
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
    if(tl==l && tr==r){
        lz[v]+=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,min(m,tr),x);
    upd(rc,m,r,max(m,tl),tr,x);
    f[v]=min(f[lc],f[rc]);
    g[v]=0;
    if(f[v]==f[lc]) g[v]+=g[lc];
    if(f[v]==f[rc]) g[v]+=g[rc];
}
pll get(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=tr) return {INF,INF};
    if(tl==l && tr==r) return {f[v],g[v]};
    ll m=(l+r)>>1;
    pll p=get(lc,l,m,tl,min(m,tr)),q=get(rc,m,r,max(m,tl),tr);
    if(q.F<p.F) swap(p,q);
    if(p.F==q.F) p.S+=q.S;
    return p;
}
int main(){
    fast_io;
    cin >> n >> q;
    build(1,1,n+1);
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1,0);
    while(q--){
        ll v,u,x;
        cin >> v >> u;
        if(st[v]>st[u]) swap(v,u);
        pll k={v,u};
        pm[k]^=1;
        if(pm[k]) x=1;
        else x=-1;
        if(st[u]<=fn[v]){
            ll y=pr(u,H[u]-H[v]-1);
            upd(1,1,n+1,st[y],fn[y]+1,x);
            upd(1,1,n+1,st[u],fn[u]+1,-x);
        }else{
            upd(1,1,n+1,st[v],fn[v]+1,-x);
            upd(1,1,n+1,st[u],fn[u]+1,-x);
            upd(1,1,n+1,1,n+1,x);
        }
        pll p=get(1,1,n+1,1,n+1);
        if(p.F) p.S=0;
        cout << p.S << '\n';
    }
    return 0;
}