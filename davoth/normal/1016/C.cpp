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
const int N=3e5+10,LN=20,M=5e1+1,SQ=450,inf=1e9;
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
ll n,a[N],b[N],pa[N],pb[N],dp[2][N],c,d;
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        pa[i]=a[i]+pa[i-1];
    }
    for(ll i=1; i<=n; i++){
        cin >> b[i];
        pb[i]=b[i]+pb[i-1];
    }
    dp[0][n]=b[n];
    dp[1][n]=a[n];
    c=a[n]+2*b[n];
    d=a[n]*2+b[n];
    for(ll i=n-1; i>0; i--){
        dp[0][i]=b[i]+(pa[n]-pa[i]+pb[n]-pb[i])*2+dp[1][i+1];
        dp[1][i]=a[i]+(pa[n]-pa[i]+pb[n]-pb[i])*2+dp[0][i+1];
        dp[0][i]=max(dp[0][i],c+(2*(n-i)+1)*b[i]);
        dp[1][i]=max(dp[1][i],d+(2*(n-i)+1)*a[i]);
        c+=pa[n]-pa[i]+pb[n]-pb[i]+a[i]+2*(n-i+1)*b[i];
        d+=pa[n]-pa[i]+pb[n]-pb[i]+b[i]+2*(n-i+1)*a[i];
    }
    cout << dp[0][1] << '\n';
    return 0;
}