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
const int N=1e5+10,LN=20,M=1e5+10,SQ=250,inf=1e9;
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
ll n,f[N*4],lz[N*4],q,ans[N],p[LN][N],h[N],st[N],fn[N],t;
vector<ll> adj[N];
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
    f[v]=max(f[lc],f[rc]);
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=tr) return 0;
    if(l==tl && r==tr) return f[v];
    ll m=(l+r)>>1;
    return max(get(lc,l,m,tl,min(m,tr)),get(rc,m,r,max(m,tl),tr));
}
void predfs(ll v){
    st[v]=++t;
    for(ll u : adj[v]){
        if(p[0][v]==u) continue;
        h[u]=h[v]+1;
        p[0][u]=v;
        predfs(u);
    }
    fn[v]=t;
}
void dfs(ll v){
    for(auto [i,g] : qu[v]){
        ans[i]=max(ans[i],get(1,1,n+1,g.F,g.S+1));
    }
    for(ll u : adj[v]){
        if(u==p[0][v]) continue;
        upd(1,1,n+1,1,n+1,1);
        upd(1,1,n+1,st[u],fn[u]+1,-2);
        dfs(u);
        upd(1,1,n+1,1,n+1,-1);
        upd(1,1,n+1,st[u],fn[u]+1,2);
    }
}
ll lca(ll v, ll u){
    if(h[v]>h[u]) swap(v,u);
    for(ll i=LN; i--;){
        if(h[p[i][u]]>=h[v]) u=p[i][u];
    }
    if(v==u) return v;
    for(ll i=LN; i--;){
        if(p[i][u]!=p[i][v]) u=p[i][u],v=p[i][v];
    }
    return p[0][v];
}
ll pr(ll v, ll x){
    for(ll i=LN; i--;){
        if(x&(1<<i)) v=p[i][v];
    }
    return v;
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    h[1]=1;
    predfs(1);
    for(ll i=1; i<LN; i++){
        for(ll j=1; j<=n; j++){
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
    for(ll i=1; i<=n; i++) upd(1,1,n+1,st[i],st[i]+1,h[i]-1);
    cin >> q;
    for(ll i=1; i<=q; i++){
        ll v,u;
        cin >> v >> u;
        if(h[v]>h[u]) swap(v,u);
        ll x=lca(v,u),y=(h[v]+h[u]-2*h[x])>>1;
        if(x!=v && y*2==h[v]+h[u]-2*h[x]) y--;
        ll z=pr(u,y);
        qu[u].pb({i,{st[z],fn[z]}});
        qu[v].pb({i,{1,st[z]-1}});
        qu[v].pb({i,{fn[z]+1,n}});
    }
    dfs(1);
    for(ll i=1; i<=q; i++) cout << ans[i] << '\n';
    return 0;
}