#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=30;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll b[LN][4*N], a[LN][N], c[LN][4*N], n, m, p=1;
void push(ll v, ll f, ll l, ll r){
    if(c[f][v]==0) return;
    ll m=(l+r)/2;
    b[f][v*2]=m-l+1-b[f][v*2];
    c[f][v*2]^=c[f][v];
    b[f][v*2+1]=r-m-b[f][v*2+1];
    c[f][v*2+1]^=c[f][v];
    c[f][v]=0;
}
void update(ll v, ll tl, ll tr, ll l, ll r, ll x, ll f){
    if(l>r) return;
    if(tl==l && tr==r){
        if(x!=0){
            b[f][v]=tr-tl+1-b[f][v];
            c[f][v]^=x;
        }
    }
    else{
        push(v, f, tl, tr);
        ll tm=(tl+tr)/2;
        update(2*v, tl, tm, l, min(r,tm), x, f);
        update(2*v+1, tm+1, tr, max(l,tm+1), r, x, f);
        b[f][v]=b[f][v*2]+b[f][v*2+1];
    }
}
ll get(ll v, ll tl, ll tr, ll l, ll r, ll f){
    if(l>r) return 0;
    if(tl==l && tr==r) return b[f][v];
    push(v, f, tl, tr);
    ll tm=(tl+tr)/2;
    return get(v*2, tl, tm, l, min(tm,r), f)+get(v*2+1, tm+1, tr, max(l,tm+1), r, f);
}
void build(ll v, ll l, ll r, ll f){
    if(l==r) b[f][v]=a[f][l];
    else{
        ll m=(l+r)/2;
        build(v*2, l, m, f);
        build(v*2+1, m+1, r, f);
        b[f][v]=b[f][v*2]+b[f][v*2+1];
    }
}
int main() {
    cin >> n;
    for(ll i=0; i<n; i++) cin >> a[21][i];
    for(ll i=0; i<=20; i++){
        for(ll j=0; j<n; j++){
            a[i][j]=(a[21][j]&p)/p;
        }
        p*=2;
    }
    for(ll i=0; i<=20; i++) build(1, 0, n-1, i);
    cin >> m;
    for(ll i=0; i<m; i++){
        ll t;
        cin >> t;
        if(t==1){
            ll l, r, s=0;
            cin >> l >> r;
            p=1;
            for(ll i=0; i<=20; i++){
                s+=get(1, 0, n-1, l-1, r-1, i)*p;
                p*=2;
            }
            cout << s << '\n';
        }else{
            ll l, r, x;
            cin >> l >> r >> x;
            p=1;
            for(ll i=0; i<=20; i++){
                update(1, 0, n-1, l-1, r-1, (x&p)/p, i);
                p*=2;
            }
        }
    }
    return 0;
}