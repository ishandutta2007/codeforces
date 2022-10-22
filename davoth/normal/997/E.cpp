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
const int N=3e5+10,LN=20,M=5e4+10,SQ=250,inf=1e9;
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
ll n,q,a[N],f[N*4],lz[N*4],lz3[N*4],g[N*4],z[N*4],ans[N];
vector<pll> L[N];
void build(ll v, ll l, ll r){
    if(r-l==1){
        f[v]=n-l+1;
        z[v]=1;
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=min(f[lc],f[rc]);
    z[v]=0;
    if(f[v]==f[lc]) z[v]+=z[lc];
    if(f[v]==z[rc]) z[v]+=z[rc];
}
void shift(ll v, ll l, ll r){
    f[v]+=lz[v];
    g[v]+=lz3[v]*z[v];
    if(r-l>1){
        lz[lc]+=lz[v];
        lz[rc]+=lz[v];
        ll x=f[lc]+lz[lc],y=f[rc]+lz[rc];
        if(x==f[v]) lz3[lc]+=lz3[v];
        if(y==f[v]) lz3[rc]+=lz3[v];
    }
    lz3[v]=lz[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr) return;
    if(tl==l && tr==r){
        lz[v]+=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,min(tr,m),x);
    upd(rc,m,r,max(tl,m),tr,x);
    f[v]=min(f[lc],f[rc]);
    z[v]=0;
    if(f[v]==f[lc]) z[v]+=z[lc];
    if(f[v]==f[rc]) z[v]+=z[rc];
    g[v]=g[lc]+g[rc];
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=tr) return 0;
    if(tl==l && tr==r) return g[v];
    ll m=(l+r)>>1;
    return get(lc,l,m,tl,min(m,tr))+get(rc,m,r,max(m,tl),tr);
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++) cin >> a[i];
    build(1,1,n+1);
    cin >> q;
    for(ll i=0; i<q; i++){
        ll l,r;
        cin >> l >> r;
        L[l].pb({r,i});
    }
    stack<pll> st[2];
    for(ll i=n; i>=1; i--){
        ll t=i;
        while(!st[0].empty() && st[0].top().F<=a[i]){
            auto [x,y]=st[0].top();
            upd(1,1,n+1,t+1,y+1,a[i]-x);
            t=y;
            st[0].pop();
        }
        st[0].push({a[i],t});
        t=i;
        while(!st[1].empty() && st[1].top().F>=a[i]){
            auto [x,y]=st[1].top();
            upd(1,1,n+1,t+1,y+1,x-a[i]);
            t=y;
            st[1].pop();
        }
        st[1].push({a[i],t});
        upd(1,1,n+1,1,n+1,-1);
        if(f[1]==0) lz3[1]++;
        for(auto [r,j] : L[i]) ans[j]=get(1,1,n+1,i,r+1);
    }
    for(ll i=0; i<q; i++) cout << ans[i] << '\n';
    return 0;
}