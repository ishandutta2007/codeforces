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
const int N=1e5+10,LN=20,M=5e6,SQ=350,B=737,inf=1e9+10;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MOD=998244353,MD=1000000007;
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
ll n,m,l[60],r[60],dp[N],pd[N];
void solve(ll x){
    ll k=m/x;
    for(ll i=0; i<=k; i++) dp[i]=i+1;
    for(ll i=1; i<=n; i++){
        ll L=(l[i]+x-1)/x,R=r[i]/x;
        if(L>R) return;
        for(ll j=k; j>R; j--){
            dp[j]=dp[j-L]-dp[j-R-1];
            if(dp[j]<0) dp[j]+=MOD;
        }
        for(ll j=R; j>=L; j--) dp[j]=dp[j-L];
        for(ll j=0; j<L; j++) dp[j]=0;
        for(ll j=1; j<=k; j++){
            dp[j]+=dp[j-1];
            if(dp[j]>MOD) dp[j]-=MOD;
        }
    }
    pd[x]=dp[k]-dp[k-1];
    if(pd[x]<0) pd[x]+=MOD;
    for(ll i=x+x; i<=m; i+=x){
        pd[x]-=pd[i];
        if(pd[x]<0) pd[x]+=MOD;
    }
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=n; i++){
        cin >> l[i] >> r[i];
    }
    for(ll i=m; i; i--) solve(i);
    cout << pd[1] << '\n';
    return 0;
}