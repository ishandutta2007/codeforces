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
const int N=1e5+10,LN=20,M=5e1+1,SQ=600,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
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
ll n,a[N],c[N],f[N*4],dp[N],ans,an[N];
pll t[N];
void upd(ll v, ll l, ll r, ll t, ll x){
    if(r-l==1){
        f[v]=x;
        return;
    }
    ll m=(l+r)>>1;
    if(t<m) upd(lc,l,m,t,x);
    else upd(rc,m,r,t,x);
    f[v]=min(f[lc],f[rc]);
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=tr) return INF;
    if(tl==l && tr==r) return f[v];
    ll m=(l+r)>>1;
    return min(get(lc,l,m,tl,min(m,tr)),get(rc,m,r,max(m,tl),tr));
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a[i] >> c[i];
        t[i]={a[i],i};
        ans+=c[i];
    }
    sort(t+1,t+1+n);
    an[n+1]=INF;
    an[n]=t[n].F;
    for(ll i=n; --i;){
        auto itr=upper_bound(t+1,t+n+1,make_pair(t[i].F+c[t[i].S],n+1));
        dp[i]=get(1,1,n+1,i+1,itr-t);
        dp[i]=min(dp[i],an[itr-t]-t[i].F-c[t[i].S]);
        upd(1,1,n+1,i,dp[i]);
        an[i]=min(an[i+1],t[i].F+dp[i]);
    }
    cout << ans+dp[1] << '\n';
    return 0;
}