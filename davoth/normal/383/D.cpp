#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
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
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e3+10,LN=20,M=1e4+0,SQ=350,B=737,inf=1e9;
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
ll n,a[N],*dp[N],ans;
void solve(ll l, ll r){
    if(r-l==1) return;
    ll m=(l+r)>>1;
    for(int i=-M; i<=M; i++) dp[m][i]=dp[m-1][i]=0;
    dp[m][a[m]]=dp[m][-a[m]]=1;
    for(int i=m+1; i<r; i++){
        for(int j=-M; j<=M; j++){
            dp[i][j]=0;
            if(j+a[i]<=M) dp[i][j]+=dp[i-1][j+a[i]];
            if(j-a[i]>=-M) dp[i][j]+=dp[i-1][j-a[i]];
            dp[i][j]%=MOD;
        }
    }
    for(int i=m+1; i<r; i++){
        for(int j=-M; j<=M; j++){
            dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
        }
    }
    dp[m-1][a[m-1]]=dp[m-1][-a[m-1]]=1;
    for(int i=m-2; i>=l; i--){
        for(int j=-M; j<=M; j++){
            dp[i][j]=0;
            if(j+a[i]<=M) dp[i][j]+=dp[i+1][j+a[i]];
            if(j-a[i]>=-M) dp[i][j]+=dp[i+1][j-a[i]];
            dp[i][j]%=MOD;
        }
    }
    for(int i=m-1; i>=l; i--){
        for(int j=-M; j<=M; j++){
            ans=(ans+dp[i][j]*dp[r-1][j])%MOD;
        }
    }
    solve(l,m);
    solve(m,r);
}
int main(){
    fast_io;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        dp[i]=new ll[20010]+10005;
    }
    solve(1,n+1);
    cout << ans << '\n';
    return 0;
}