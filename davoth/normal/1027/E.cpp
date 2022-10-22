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
const int N=5e2+10,LN=20,M=5e1+1,SQ=450,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=/*1000000007*/ 998244353;
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
ll n,dp[2][N][N],pd[N][N],ans,k;
int main(){
    fast_io;
    cin >> n >> k;
    dp[0][0][0]=pd[0][0]=1;
    for(ll i=1; i<n; i++){
        for(ll j=0; j<=i; j++){
            pd[i][j]=dp[1][j][0]=pd[i-1][j];
            for(ll k=1; k<=j; k++){
                dp[1][j][k]=dp[0][j][k-1];
                pd[i][j]=(pd[i][j]+dp[1][j][k])%MOD;
            }
            if(j){
                dp[1][j][j]=(dp[1][j][j]+dp[0][j-1][j-1])%MOD;
                pd[i][j]=(pd[i][j]+dp[0][j-1][j-1])%MOD;
            }
        }
        for(ll j=0; j<=i; j++){
            for(ll k=0; k<=j; k++){
                dp[0][j][k]=dp[1][j][k];
            }
        }
    }
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if((i+1)*(j+1)<k) ans=(ans+pd[n-1][i]*pd[n-1][j])%MOD;
        }
    }
    cout << ans*2%MOD << '\n';
    return 0;
}