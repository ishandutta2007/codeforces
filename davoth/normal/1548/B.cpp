#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20,M=5e6,SQ=350,B=737,inf=1e9+10;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
ll t,n,a[N],g[N],ans;
void solve(ll l, ll r){
    if(r<=l) return;
    ll m=(l+r)>>1;
    if(r-l>1){
        solve(l,m);
        solve(m+1,r);
    }
    g[m]=abs(a[m]-a[m+1]);
    for(ll i=m-1; i>=l; i--){
        g[i]=__gcd(abs(a[i]-a[i+1]),g[i+1]);
    }
    for(ll i=m+1; i<r; i++){
        g[i]=__gcd(abs(a[i]-a[i+1]),g[i-1]);
    }
    ll tr=m;
    for(ll i=l; i<=m; i++){
        if(__gcd(g[i],g[tr])==1) continue;
        while(tr+1<r && __gcd(g[tr+1],g[i])!=1) tr++;
        ans=max(ans,tr-i+2);
    }
    /*cout << l << ' ' << r << ' ' << m << '\n';
    for(ll i=l; i<r; i++) cout << g[i] << ' ';*/
    //cout << '\n';
}
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n;
        for(ll i=1; i<=n; i++) cin >> a[i];
        ans=1;
        solve(1,n);
        cout << ans << '\n';
    }
    return 0;
}