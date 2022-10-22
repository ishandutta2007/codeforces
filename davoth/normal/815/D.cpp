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
const int N=1e6+10,LN=20,M=1.1e7+10,SQ=350,B=737,inf=1e9;
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
ll n,P,Q,R,ma[N],mb[N],ans,lz[N*4];
vector<pll> t[N];
struct node{
    ll mn,mx,s;
    node operator+(node x){
        node ans;
        ans.s=s+x.s;
        ans.mn=min(mn,x.mn);
        ans.mx=max(mx,x.mx);
        return ans;
    }
} f[N*4];
void shift(ll v, ll l, ll r){
    if(!lz[v]) return;
    f[v].mx=f[v].mn=lz[v];
    f[v].s=lz[v]*(r-l);
    if(r-l>1){
        lz[lc]=lz[v];
        lz[rc]=lz[v];
    }
    lz[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr || x<=f[v].mn) return;
    if(tl==l && tr==r && f[v].mx<=x){
        lz[v]=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,min(m,tr),x);
    upd(rc,m,r,max(m,tl),tr,x);
    f[v]=f[lc]+f[rc];
}
ll get(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr) return 0;
    if(x>=f[v].mx) return (tr-tl)*x;
    if(tl==l && tr==r && x<=f[v].mn) return f[v].s;
    ll m=(l+r)>>1;
    return get(lc,l,m,tl,min(m,tr),x)+get(rc,m,r,max(m,tl),tr,x);
}
int main(){
    fast_io;
    cin >> n >> P >> Q >> R;
    for(ll i=1; i<=n; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        t[c].pb({a,b});
    }
    for(ll i=R; i>0; i--){
        ma[i]=ma[i+1];
        mb[i]=mb[i+1];
        for(auto [a,b] : t[i]){
            ma[i]=max(ma[i],a);
            mb[i]=max(mb[i],b);
        }
    }
    for(ll c=1; c<=R; c++){
        ans+=(Q-mb[c])*P-get(1,1,Q+1,mb[c]+1,Q+1,ma[c]);
        for(auto [a,b] : t[c]){
            upd(1,1,Q+1,1,b+1,a);
        }
    }
    cout << ans << '\n';
    return 0;
}