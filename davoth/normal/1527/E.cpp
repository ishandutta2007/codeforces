#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
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
const int N=3.5e4+10,LN=18,M=1.1e7+10,SQ=350,B=737,inf=1e9+10;
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
ll n,k,a[N],dp[N],f[N*4],lz[N*4],b[N];
void shift(ll v, ll l, ll r){
    f[v]+=lz[v];
    if(r-l>1){
        lz[lc]+=lz[v];
        lz[rc]+=lz[v];
    }
    lz[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr) return;
    if(tl==l && tr==r){
        lz[v]+=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,min(m,tr),x);
    upd(rc,m,r,max(m,tl),tr,x);
    f[v]=min(f[lc],f[rc]);
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=tr) return INF;
    if(tl==l && tr==r) return f[v];
    ll m=(l+r)>>1;
    return min(get(lc,l,m,tl,min(m,tr)),get(rc,m,r,max(m,tl),tr));
}
int main(){
    fast_io;
    cin >> n >> k;
    for(ll i=1; i<=n; i++) cin >> a[i];
    memset(dp,63,sizeof dp);
    for(ll t=1; t<=k; t++){
        memset(b,0,sizeof b);
        memset(lz,0,sizeof lz);
        memset(f,0,sizeof f);
        for(ll i=1; i<=n; i++){
            if(b[a[i]]){
                upd(1,0,n+1,0,b[a[i]],i-b[a[i]]);
            }
            b[a[i]]=i;
            upd(1,0,n+1,i,i+1,dp[i]);
            dp[i]=get(1,0,n+1,0,i+1);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}