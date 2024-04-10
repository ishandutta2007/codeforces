#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc 1+(v<<1)
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,M=2e5+10,SQ=250,inf=1e9;
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
ll n,q,f[N*4],lz[N*4],ans;
vector<ll> vec={-1};
vector<pll> qu[N];
void shift(ll v, ll l, ll r){
    if(!lz[v]) return;
    f[v]=r-l-f[v];
    if(r-l>1){
        lz[lc]^=1;
        lz[rc]^=1;
    }
    lz[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=tr) return;
    if(tl==l && tr==r){
        lz[v]^=1;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,min(tr,m));
    upd(rc,m,r,max(tl,m),tr);
    f[v]=f[lc]+f[rc];
}
ll get(ll v, ll l , ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=tr) return 0;
    if(l==tl && r==tr) return f[v];
    ll m=(l+r)>>1;
    return get(lc,l,m,tl,min(tr,m))+get(rc,m,r,max(tl,m),tr);
}
int main(){
    fast_io;
    cin >> n >> q;
    ans=n*(n-1)*(n-2)/6;
    for(ll i=1; i<=n; i++){
        ll t;
        cin >> t;
        vec.pb(t);
    }
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    for(ll i=0; i<q; i++){
        ll a,b;
        cin >> a >> b;
        a=lower_bound(vec.begin(),vec.end(),a)-vec.begin();
        b=upper_bound(vec.begin(),vec.end(),b)-vec.begin()-1;
        if(b>a){
            qu[a].pb({a,b});
            qu[b+1].pb({a,b});
        }
    }
    for(ll i=1; i<=n; i++){
        for(auto [a,b] : qu[i]){
            upd(1,1,n+1,a,b+1);
        }
        ll t=i-1-get(1,1,n+1,1,i)+get(1,1,n+1,i+1,n+1);
        ans-=t*(t-1)/2;
    }
    cout << ans << '\n';
    return 0;
}