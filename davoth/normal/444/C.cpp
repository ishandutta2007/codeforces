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
ll n,q,f[N*4],c[N*4],l1[N*4],l2[N*4];
void ps(ll v, ll l, ll r){
    if(l1[v]==0) return;
    ll m=(l+r)/2;
    f[v*2]+=l2[v]*(m-l);
    f[v*2+1]+=l2[v]*(r-m);
    l1[v*2+1]=l1[v*2]=l1[v];
    l2[v*2]+=l2[v];
    l2[v*2+1]+=l2[v];
    c[v*2]=l1[v];
    c[v*2+1]=l1[v];
    l1[v]=l2[v]=0;
}
void build(ll v, ll l, ll r){
    if(r-l<=1){
        c[v]=l;
        return;
    }
    ll m=(l+r)/2;
    build(v*2,l,m);
    build(v*2+1,m,r);
}
void update(ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(tl>=tr) return;
    if(r==tr && l==tl && c[v]){
        if(l1[v]){
            l2[v]+=abs(l1[v]-x);
        }else l2[v]+=abs(x-c[v]);
        l1[v]=x;
        f[v]+=abs(x-c[v])*(r-l);
        c[v]=x;
        return;
    }
    ll m=(l+r)/2;
    ps(v,l,r);
    update(v*2,l,m,tl,min(m,tr),x);
    update(v*2+1,m,r,max(tl,m),tr,x);
    f[v]=f[v*2]+f[v*2+1];
    if(c[v*2]==c[v*2+1]) c[v]=c[v*2];
    else c[v]=0;
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=tr) return 0;
    if(l==tl && r==tr) return f[v];
    ll m=(l+r)/2;
    ps(v,l,r);
    return get(v*2,l,m,tl,min(m,tr))+get(v*2+1,m,r,max(m,tl),tr);
}
int main(){
    fast_io;
    cin >> n >> q;
    build(1,1,n+1);
    while(q--){
        ll t;
        cin >> t;
        if(t==2){
            ll l,r;
            cin >> l >> r;
            cout << get(1,1,n+1,l,r+1) << '\n';
        }else{
            ll l,r,x;
            cin >> l >> r >> x;
            update(1,1,n+1,l,r+1,x);
        }
    }
    return 0;
}