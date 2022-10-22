#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
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
const int N=3e2+10,LN=24,M=1e7+10,SQ=500,B=737,inf=1e9;
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
ll n,k,dp[LN][N][N],x,pd[LN][N][N];
int main(){
    fast_io;
    cin >> n >> k;
    for(ll i=1; i<=n; i++){
        cin >> x;
        for(ll t=1; t<=x; t++) for(ll j=N-1; j>=x; j--) dp[0][t][j]=max(dp[0][t][j],dp[0][t][x]+1);
    }
    if(k&1) for(ll i=1; i<N; i++) for(ll j=1; j<N; j++) pd[0][i][j]=dp[0][i][j];
    for(ll i=1; i<LN; i++){
        for(x=1; x<N; x++){
            for(ll t=1; t<=x; t++){
                for(ll j=x; j<N; j++){
                    dp[i][t][j]=max(dp[i][t][j],dp[i-1][t][x]+dp[i-1][x][j]);
                }
            }
        }
        if((k>>i)&1){
            for(ll x=1; x<N; x++){
                for(ll t=1; t<=x; t++) for(ll j=x; j<N; j++) pd[i][t][j]=max(pd[i][t][j],pd[i-1][t][x]+dp[i][x][j]);
            }
        }else{
            for(ll t=1; t<N; t++) for(ll j=1; j<N; j++) pd[i][t][j]=pd[i-1][t][j];
        }
    }
    cout << pd[LN-1][1][N-1] << '\n';
    return 0;
}