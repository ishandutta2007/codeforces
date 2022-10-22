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
const int N=1e6+10,LN=20,M=1e5+10,SQ=250,inf=1e9;
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
ll q,f[N*4+4],lz[N*4+4];
pll qu[N];
void shift(ll v, ll l, ll r){
    f[v]+=lz[v];
    if(r-l>1){
        lz[lc]+=lz[v];
        lz[rc]+=lz[v];
    }
    lz[v]=0;
}
void build(ll v, ll l, ll r){
    f[v]=r-1;
    if(r-l>1){
        ll m=(l+r)>>1;
        build(lc,l,m);
        build(rc,m,r);
    }
}
void update(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr) return;
    if(tl==l && tr==r){
        lz[v]+=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    update(lc,l,m,tl,min(tr,m),x);
    update(rc,m,r,max(m,tl),tr,x);
    f[v]=max(f[lc],f[rc]);
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=tr) return -INF;
    if(tl==l && tr==r) return f[v];
    ll m=(l+r)>>1;
    return max(get(lc,l,m,tl,min(tr,m)),get(rc,m,r,max(tl,m),tr));
}
int main(){
    fast_io;
    cin >> q;
    build(1,0,N);
    for(ll i=1; i<=q; i++){
        char c;
        cin >> c;
        if(c=='+'){
            cin >> qu[i].F >> qu[i].S;
            update(1,0,N,qu[i].F,N,-qu[i].S);
        }else if(c=='-'){
            ll j;
            cin >> j;
            update(1,0,N,qu[j].F,N,qu[j].S);
        }else{
            ll t;
            cin >> t;
            cout << get(1,0,N,0,t)-get(1,0,N,t,t+1)+1 << '\n';
        }
    }
    return 0;
}