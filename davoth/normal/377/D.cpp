#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=30,SQ=550,M=3e5+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
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
ll n,lz[M*4],mx,ml,mr;
pll f[M*4];
pair<ll,pll> a[N];
vector<pll> c[2][M];
void ps(ll v){
    f[v*2].F+=lz[v];
    f[v*2+1].F+=lz[v];
    lz[v*2]+=lz[v];
    lz[v*2+1]+=lz[v];
    lz[v]=0;
}
void build(ll v, ll l, ll r){
    if(r-l<=1){
        f[v].S=l;
        return;
    }
    ll m=(l+r)/2;
    build(v*2,l,m);
    build(v*2+1,m,r);
    f[v]=max(f[v*2],f[v*2+1]);
}
void update(ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(tl>=tr) return;
    if(r==tr && l==tl){
        lz[v]+=x;
        f[v].F+=x;
        return;
    }
    ll m=(l+r)/2;
    ps(v);
    update(v*2,l,m,tl,min(m,tr),x);
    update(v*2+1,m,r,max(tl,m),tr,x);
    f[v]=max(f[v*2],f[v*2+1]);
}
pll get(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=tr) return {0,0};
    if(l==tl && r==tr) return f[v];
    ll m=(l+r)/2;
    ps(v);
    return max(get(v*2,l,m,tl,min(m,tr)),get(v*2+1,m,r,max(m,tl),tr));
}
int main(){
    fast_io;
    cin >> n;
    build(1,1,M);
    for(ll i=0; i<n; i++){
        cin >> a[i].S.F >> a[i].F >> a[i].S.S;
        c[1][a[i].S.F].emplace_back(a[i].F,a[i].S.S);
        c[0][a[i].F+1].emplace_back(a[i].F,a[i].S.S);
    }
    for(ll i=1; i<M; i++){
        for(pll p : c[0][i]){
            update(1,1,M,p.F,p.S+1,-1);
        }
        for(pll p : c[1][i]){
            update(1,1,M,p.F,p.S+1,1);
        }
        pll p=get(1,1,M,1,M);
        if(p.F>mx) mx=p.F,mr=p.S,ml=i;
    }
    cout << mx << '\n';
    for(ll i=0; i<n; i++){
        if(ml>=a[i].S.F && ml<=a[i].F && mr>=a[i].F && mr<=a[i].S.S) cout << i+1 << ' ';
    }
    cout << '\n';
    return 0;
}