#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=30,SQ=550,M=3e5+10;
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
ll n,m,h,f[4*N],a[N],b[N],c[N],k,lz[4*N],ans;
map<ll,ll> mp;
void shift(ll v){
    lz[v*2]+=lz[v];
    lz[v*2+1]+=lz[v];
    f[v*2]+=lz[v];
    f[v*2+1]+=lz[v];
    lz[v]=0;
}
void update(ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(tl>=tr) return;
    if(l==tl && r==tr){
        f[v]+=x;
        lz[v]+=x;
        return;
    }
    shift(v);
    ll m=(l+r)/2;
    update(v*2,l,m,tl,min(m,tr),x);
    update(v*2+1,m,r,max(m,tl),tr,x);
    f[v]=min(f[v*2],f[v*2+1]);
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=tr) return INF;
    if(tl==l && tr==r) return f[v];
    shift(v);
    ll m=(l+r)/2;
    return min(get(v*2,l,m,tl,min(m,tr)),get(v*2+1,m,r,max(m,tl),tr));
}
int main(){
    fast_io;
    cin >> n >> m >> h;;
    for(ll i=1; i<=m; i++) cin >> b[i];
    for(ll i=1; i<=n; i++) cin >> a[i];
    for(ll i=1; i<=n; i++) c[i]=a[i];
    sort(b+1,b+m+1);
    sort(c+1,c+n+1);
    for(ll i=1; i<=n; i++){
        while(k!=m && c[i]+b[m-k]>=h) k++;
        mp[c[i]]=k;
    }
    for(ll i=1; i<=n; i++) a[i]=mp[a[i]];
    //for(ll i=1; i<=n; i++) cout << a[i] << '\n';
    for(ll i=1; i<=m; i++) update(1,1,m+1,i,i+1,i-m-1);
    for(ll i=1; i<=m; i++){
        if(!a[i]) continue;
        update(1,1,m+1,1,a[i]+1,1);
    }
    if(get(1,1,m+1,1,m+1)==0) ans++;
    for(ll i=m+1; i<=n; i++){
        if(a[i]) update(1,1,m+1,1,a[i]+1,1);
        //cout << get(1,1,m+1,1,m+1) << '\n';
        if(a[i-m]) update(1,1,m+1,1,a[i-m]+1,-1);
        if(get(1,1,m+1,1,m+1)==0) ans++;
        //cout << get(1,1,m+1,1,m+1) << '\n';
    }
    cout << ans << '\n';
    return 0;
}