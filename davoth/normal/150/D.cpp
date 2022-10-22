#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1.5e2+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e15;
const ld ep=1e-7;
const int MH=1000696969,MOD=1000000007,MD=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
ll n,a[N],dp[N][N][N],pd[N][N];
string s;
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++) cin >> a[i];
    cin >> s;
    s='#'+s;
    memset(dp,-1,sizeof dp);
    for(ll i=1; i<=n; i++) dp[i][i-1][0]=0;
    for(ll sz=1; sz<=n; sz++){
        for(ll l=1; l+sz-1<=n; l++){
            ll r=l+sz-1;
            if(r==l){
                dp[l][r][0]=a[1];
                dp[l][r][1]=0;
            }else{
                for(ll i=2; i<=sz; i++){
                    for(ll j=1; j<=sz; j++){
                        if(dp[l][l+j-1][0]!=-1 && dp[l+j][r][i]!=-1) dp[l][r][i]=max(dp[l][r][i],dp[l][l+j-1][0]+dp[l+j][r][i]);
                        if(dp[r-j+1][r][0]!=-1 && dp[l][r-j][i]!=-1) dp[l][r][i]=max(dp[l][r][i],dp[r-j+1][r][0]+dp[l][r-j][i]);
                    }
                    if(s[l]==s[r]) dp[l][r][i]=max(dp[l][r][i],dp[l+1][r-1][i-2]);
                }
                for(ll i=l; i<=r; i++) if(dp[l][i-1][0]!=-1 && dp[i+1][r][0]!=-1) dp[l][r][1]=max(dp[l][r][1],dp[l][i-1][0]+dp[i+1][r][0]);
                for(ll i=1; i<=sz; i++) if(a[i]!=-1 && dp[l][r][i]!=-1) dp[l][r][0]=max(dp[l][r][0],dp[l][r][i]+a[i]);
            }
            pd[l][r]=pd[l+1][r];
            for(ll i=l; i<=r; i++) pd[l][r]=max(pd[l][r],dp[l][i][0]+pd[i+1][r]);
        }
    }
    cout << pd[1][n] << '\n';
    return 0;
}