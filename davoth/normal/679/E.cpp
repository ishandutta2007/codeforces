#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,SQ=550,M=5e4+10;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
struct Node{
    ll x,y;
    Node operator+(Node b){
        Node ans;
        ans.y=0;
        if(y==b.y) ans.y=b.y;
        ans.x=min(x,b.x);
        return ans;
    }
};
ll nx(ll x){
    ll p=1;
    while(p<x) p*=42;
    return p-x;
}
ll n,q,a[N],lz[N*4][2];
Node f[4*N];
void build(ll v, ll l, ll r){
    if(r-l==1){
        f[v].x=nx(a[l]);
        f[v].y=a[l];
        return;
    }
    ll m=(l+r)/2;
    build(v*2,l,m);
    build(v*2+1,m,r);
    f[v]=f[v*2]+f[v*2+1];
}
void shift(ll v, ll l, ll r){
    if(lz[v][0]){
        f[v].y=lz[v][1];
        f[v].x=nx(lz[v][1]);
    }else{
        if(f[v].y){
            f[v].y+=lz[v][1];
            f[v].x=nx(f[v].y);
        }else f[v].x-=lz[v][1];
    }
    if(r-l>1){
        if(lz[v][0]){
            lz[v*2][0]=lz[v*2+1][0]=lz[v][0];
            lz[v*2][1]=lz[v*2+1][1]=lz[v][1];
        }else{
            lz[v*2][1]+=lz[v][1];
            lz[v*2+1][1]+=lz[v][1];
        }
    }
    lz[v][0]=lz[v][1]=0;
}
void up1(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr) return;
    if(tl==l && tr==r){
        lz[v][0]=1;
        lz[v][1]=x;
        shift(v,l,r);
        return;
    }
    ll m=(l+r)/2;
    up1(v*2,l,m,tl,min(m,tr),x);
    up1(v*2+1,m,r,max(m,tl),tr,x);
    f[v]=f[v*2]+f[v*2+1];
}
void up2(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr) return;
    if(tl==l && tr==r && (f[v].y || f[v].x>=x)){
        lz[v][1]+=x;
        shift(v,l,r);
        return;
    }
    ll m=(l+r)/2;
    up2(v*2,l,m,tl,min(m,tr),x);
    up2(v*2+1,m,r,max(m,tl),tr,x);
    f[v]=f[v*2]+f[v*2+1];
}
ll get(ll v, ll l, ll r, ll p){
    shift(v,l,r);
    if(r-l==1) return f[v].y;
    ll m=(l+r)/2;
    if(p<m) return get(v*2,l,m,p);
    return get(v*2+1,m,r,p);
}
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=1; i<=n; i++) cin >> a[i];
    build(1,1,n+1);
    while(q--){
        ll t,l,r,x;
        cin >> t >> l;
        if(t==1){
            cout << get(1,1,n+1,l) << '\n';
        }else if(t==2){
            cin >> r >> x;
            up1(1,1,n+1,l,r+1,x);
        }else{
            cin >> r >> x;
            up2(1,1,n+1,l,r+1,x);
            while(!f[1].x) up2(1,1,n+1,l,r+1,x);
        }
    }
    return 0;
}