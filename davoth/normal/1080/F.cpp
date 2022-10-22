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
const int N=2e5+10,LN=20,M=1.1e7+10,SQ=350,B=737,inf=1e9;
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
ll n,q,k;
vector<pair<pll,ll>> f[N*4];
vector<pll> s[N];
void build(ll v, ll l, ll r){
    if(r-l==1){
        sort(s[l].begin(),s[l].end());
        for(ll i=1; i<s[l].size(); i++) s[l][i].S=max(s[l][i].S,s[l][i-1].S);
        for(pll p : s[l]){
            f[v].pb({p,v});
        }
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=vector<pair<pll,ll>>(f[lc].size()+f[rc].size());
    merge(f[lc].begin(),f[lc].end(),f[rc].begin(),f[rc].end(),f[v].begin());
    ll x=0,y=0;
    for(ll i=0; i<f[v].size(); i++){
        if(f[v][i].S==lc) x=f[v][i].F.S;
        else y=f[v][i].F.S;
        f[v][i].F.S=min(x,y);
        f[v][i].S=v;
    }
    /*cout << v << ' ' << l << ' ' << r << ":\n";
    for(pll p : f[v]) cout << p.F << ' ' << p.S << '\n';*/
}
bool get(ll v, ll l, ll r, ll tl, ll tr, ll x, ll y){
    if(tl>=tr) return 1;
    if(l==tl && r==tr){
        if(f[v].empty() || f[v][0].F.F>y) return 0;
        pair<pll,ll> p=*(upper_bound(f[v].begin(),f[v].end(),mp(mp(y,INF),INF))-1);
        if(p.F.S<x) return 0;
        return 1;
    }
    ll m=(l+r)>>1;
    return (get(lc,l,m,tl,min(m,tr),x,y)&get(rc,m,r,max(m,tl),tr,x,y));
}
int main(){
    fast_io;
    cin >> n >> q >> k;
    for(ll i=1; i<=k; i++){
        ll l,r,p;
        cin >> l >> r >> p;
        s[p].pb({r,l});
    }
    build(1,1,n+1);
    while(q--){
        ll l,r,x,y;
        cin >> l >> r >> x >> y;
        if(get(1,1,n+1,l,r+1,x,y)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}