#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=30,SQ=550,M=1e6+10;
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
ll n,m,a[N],lz[4*N],f[4*N];
vector<pll> v[N];
void shift(ll v){
    lz[v*2]+=lz[v];
    lz[v*2+1]+=lz[v];
    f[v*2]+=lz[v];
    f[v*2+1]+=lz[v];
    lz[v]=0;
}
void update(ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(tl>=tr) return;
    if(tr==r && tl==l){
        f[v]+=x;
        lz[v]+=x;
        return;
    }
    shift(v);
    ll m=(l+r)/2;
    update(v*2,l,m,tl,min(m,tr),x);
    update(v*2+1,m,r,max(m,tl),tr,x);
    f[v]=max(f[v*2],f[v*2+1]);
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=tr) return 0;
    if(l==tl && r==tr){
        return f[v];
    }
    shift(v);
    ll m=(l+r)/2;
    return max(get(v*2,l,m,tl,min(m,tr)),get(v*2+1,m,r,max(m,tl),tr));
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=n; i++) cin >> a[i];
    for(ll i=0; i<m; i++){
        ll l,r,p;
        cin >> l >> r >> p;
        v[r].emplace_back(l,p);
    }
    for(ll i=1; i<=n; i++){
        update(1,1,n+2,i+1,i+2,get(1,1,n+2,1,i+1));
        update(1,1,n+2,1,i+1,-a[i]);
        for(pll p : v[i]){
            update(1,1,n+2,1,p.F+1,p.S);
        }
    }
    cout << get(1,1,n+2,1,n+2) << '\n';
    return 0;
}