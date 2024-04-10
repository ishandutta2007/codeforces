#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = /*long long*/ int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=20,M=5e1+1,SQ=450,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
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
ll n,m,k,q,g[M][N],p[M][N],sz[M][N],col[N];
vector<pll> ud[M];
pll ed[N],qu[N];
vector<ll> ne[N];
vector<pll> f[4*N];
pll gp(ll c, ll x){
    if(!p[c][x]) return make_pair(x,g[c][x]);
    pll t=gp(c,p[c][x]);
    t.S^=g[c][x];
    return t;
}
void uni(ll c, ll v, ll u){
    auto [x,V]=gp(c,v);
    auto [y,U]=gp(c,u);
    if(sz[c][y]>sz[c][x]) swap(y,x);
    v=V;
    u=U;
    if(x!=y){
        p[c][y]=x;
        g[c][y]=v^u^1;
        ud[c].pb({x,y});
        sz[c][x]+=sz[c][y];
    }else ud[c].pb({-1,y});
}
void un(ll c){
    auto [v,u]=ud[c].back();
    ud[c].pop_back();
    if(v==-1) return;
    sz[c][v]-=sz[c][u];
    g[c][u]=0;
    p[c][u]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x, ll y){
    if(tl>=tr) return;
    if(tl==l && tr==r){
        f[v].pb({x,y});
        return;
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,min(m,tr),x,y);
    upd(rc,m,r,max(m,tl),tr,x,y);
}
void solve(ll v, ll l, ll r){
    for(auto [x,y] : f[v]){
        uni(y,ed[x].F,ed[x].S);
    }
    if(r-l==1 && l<q){
        //if(l==2) cout << gp(1,1) << ' ' << gp(1,2) << ' ' << gp(1,3) << '\n' << g[1][1] << ' ' << g[1][2] << ' ' << g[1][3] << '\n';
        auto [e,c]=qu[l+1];
        auto [x,X]=gp(c,ed[e].F);
        auto [y,Y]=gp(c,ed[e].S);
        if(x==y && X==Y){
            c=col[e];
            cout << "NO\n";
        }else cout << "YES\n";
        ne[e].pop_back();
        ll w=ne[e].back();
        col[e]=c;
        if(c) upd(1,0,q+1,l+1,w,e,c);
    }else if(r-l>1){
        ll m=(l+r)>>1;
        solve(lc,l,m);
        solve(rc,m,r);
    }
    for(auto [x,y] : f[v]) un(y);
}
int main(){
    fast_io;
    cin >> n >> m >> k >> q;
    for(ll i=1; i<=n; i++) for(ll j=1; j<=k; j++) sz[j][i]=1;
    for(ll i=1; i<=m; i++) cin >> ed[i].F >> ed[i].S;
    for(ll i=1; i<=q; i++){
        ll e,c;
        cin >> e >> c;
        qu[i]={e,c};
        ne[e].pb(i);
    }
    for(ll i=1; i<=m; i++) ne[i].pb(q+1),reverse(ne[i].begin(),ne[i].end());
    solve(1,0,q+1);
    return 0;
}