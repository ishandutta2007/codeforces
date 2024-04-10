#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10,LN=50,M=1e5+10,SQ=350,inf=1e9;
const ll INF=1e14;
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
ll n,m,st[N],fn[N],t,f[N*4],lz[N*4],dp[N],V[N],U[N],C[N],lb[N],ub[N];
vector<ll> adj[N],T[N],S[N];
vector<pair<pll,ll>> kr;
void dfs(ll v, ll p=0){
    st[v]=++t;
    for(ll u : adj[v]){
        if(u==p) continue;
        dfs(u,v);
    }
    fn[v]=t;
}
void build(ll v, ll l, ll r){
    f[v]=INF;
    if(r-l==1) return;
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
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
    if(tl>=tr || tl>=r) return;
    if(tl==l && tr==r){
        lz[v]+=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,min(m,tr),x);
    upd(rc,m,r,max(m,tl),tr,x);
    f[v]=min(f[lc],f[rc]);
}
void up(ll v, ll l, ll r, ll p, ll x){
    shift(v,l,r);
    if(r-l==1){
        f[v]=x;
        return;
    }
    ll m=(l+r)>>1;
    if(p<m) up(lc,l,m,p,x);
    else up(rc,m,r,p,x);
    shift(lc,l,m);
    shift(rc,m,r);
    f[v]=min(f[lc],f[rc]);
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=tr || tl>=r) return INF;
    if(tl==l && tr==r) return f[v];
    ll m=(l+r)>>1;
    return min(get(lc,l,m,tl,min(tr,m)),get(rc,m,r,max(m,tl),tr));
}
bool cmp(pair<pll,ll> a, pair<pll,ll> b){
    return st[a.F.F]<st[b.F.F];
}
void solve(ll v, ll p=0){
    ll x=0;
    for(ll u : adj[v]){
        if(u==p) continue;
        solve(u,v),x+=dp[u];
    }
    for(ll i : S[v]){
        up(1,1,m+1,i,C[i]);
    }
    for(ll i : T[v]){
        up(1,1,m+1,i,INF);
    }
    upd(1,1,m+1,lb[st[v]],ub[fn[v]]+1,x);
    dp[v]=get(1,1,m+1,lb[st[v]],ub[fn[v]]+1);
    upd(1,1,m+1,lb[st[v]],ub[fn[v]]+1,-dp[v]);
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=2; i<=n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1);
    for(ll i=1; i<=m; i++){
        ll v,u,c;
        cin >> v >> u >> c;
        kr.pb({{v,u},c});
    }
    sort(kr.begin(),kr.end(),cmp);
    ll j=1;
    for(ll i=1; i<=t; i++){
        while(j<m && st[kr[j-1].F.F]<i) j++;
        lb[i]=j;
    }
    j=0;
    for(ll i=1; i<=t; i++){
        while(j<m && st[kr[j].F.F]<=i) j++;
        ub[i]=j;
    }
    for(ll i=1; i<=m; i++){
        V[i]=kr[i-1].F.F;
        U[i]=kr[i-1].F.S;
        C[i]=kr[i-1].S;
        S[V[i]].pb(i);
        T[U[i]].pb(i);
    }
    for(ll i=1; i<=n; i++){
        if(ub[fn[i]]<lb[st[i]]) return cout << -1, 0;
    }
    build(1,1,m+1);
    solve(1);
    ll ans=0;
    for(ll i : adj[1]) ans+=dp[i];
    if(ans>=INF) ans=-1;
    cout << ans << '\n';
    return 0;
}