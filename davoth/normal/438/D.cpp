#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,M=5e5+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
ll n,q,a[N],g[N*4];
pll f[N*4];
void build(ll v, ll l, ll r){
    if(r-l==1){
        g[v]=f[v].F=a[l];
        f[v].S=l;
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=max(f[lc],f[rc]);
    g[v]=g[lc]+g[rc];
}
void upd(ll v, ll l, ll r, ll p, ll x){
    if(r-l==1){
        g[v]=f[v].F=a[l]=x;
        return;
    }
    ll m=(l+r)>>1;
    if(p<m) upd(lc,l,m,p,x);
    else upd(rc,m,r,p,x);
    f[v]=max(f[lc],f[rc]);
    g[v]=g[lc]+g[rc];
}
pll get(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=r || tr<=l) return mp(-1,-1);
    if(l>=tl && r<=tr) return f[v];
    ll m=(l+r)>>1;
    return max(get(lc,l,m,tl,tr),get(rc,m,r,tl,tr));
}
ll gt(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=r || tr<=l) return 0;
    if(l>=tl && r<=tr) return g[v];
    ll m=(l+r)>>1;
    return gt(lc,l,m,tl,tr)+gt(rc,m,r,tl,tr);
}
int main(){
    fast_io;
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    build(1,1,n+1);
    while(q--){
        int t,l,r,x;
        cin >> t >> l >> r;
        if(t==1) cout << gt(1,1,n+1,l,r+1) << '\n';
        else if(t==3){
            upd(1,1,n+1,l,r);
        }else{
            cin >> x;
            pll p=get(1,1,n+1,l,r+1);
            while(p.F>=x){
                upd(1,1,n+1,p.S,p.F%x);
                p=get(1,1,n+1,l,r+1);
            }
        }
    }
    return 0;
}