#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=32,M=1e5+4,SQ=350,B=737,inf=1e9;
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
int n,q,p[N],a[N],b[N],g[N*4],L[N],R[N];
ll ans[N],f[N*4];
vector<pii> ql[N],qr[N];
vector<int> x[N],y[N];
void upd(ll v, ll l, ll r, ll p, ll x){
    if(r-l==1){
        g[v]=1;
        f[v]=x;
        return;
    }
    ll m=(l+r)>>1;
    if(p<m) upd(lc,l,m,p,x);
    else upd(rc,m,r,p,x);
    f[v]=f[lc]+f[rc];
    g[v]=g[lc]+g[rc];
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=tr) return 0;
    if(tl==l && tr==r) return f[v];
    ll m=(l+r)>>1;
    return get(lc,l,m,tl,min(m,tr))+get(rc,m,r,max(m,tl),tr);
}
ll gt(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=tr) return 0;
    if(tl==l && tr==r) return g[v];
    ll m=(l+r)>>1;
    return gt(lc,l,m,tl,min(m,tr))+gt(rc,m,r,max(m,tl),tr);
}
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=1; i<=n; i++){
        cin >> p[i];
        for(a[i]=i-1; a[i] && p[a[i]]<p[i]; a[i]=a[a[i]]);
        x[a[i]].pb(i);
    }
    for(ll i=n; i>0; i--){
        for(b[i]=i+1; b[i]<=n && p[b[i]]<p[i]; b[i]=b[b[i]]);
        y[b[i]].pb(i);
    }
    for(ll i=1; i<=q; i++) cin >> L[i];
    for(ll i=1; i<=q; i++){
        cin >> R[i];
        ll l=L[i],r=R[i];
        ans[i]=-r+l-1;
        ql[l].pb({r,i});
        qr[r].pb({l,i});
    }
    for(ll r=1; r<=n; r++){
        for(ll i : y[r]){
            upd(1,1,n+1,i,r);
        }
        for(auto [l,i] : qr[r]){
            ans[i]+=get(1,1,n+1,l,r+1)+(r-l+1-gt(1,1,n+1,l,r+1))*(r+1);
        }
    }
    memset(f,0,sizeof f);
    memset(g,0,sizeof g);
    for(ll l=n; l>0; l--){
        for(ll i : x[l]){
            upd(1,1,n+1,i,l);
        }
        for(auto [r,i] : ql[l]){
            ans[i]-=get(1,1,n+1,l,r+1)+(r-l+1-gt(1,1,n+1,l,r+1))*(l-1);
        }
    }
    for(ll i=1; i<=q; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}