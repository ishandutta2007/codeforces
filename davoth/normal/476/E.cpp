#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e3+10,LN=18,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e15;
const int MH=1000696969,MOD=1000000007,MD=998244353;
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
ll n,m,dp[N][N],ls[N];
string s,t;
int main(){
    fast_io;
    cin >> s >> t;
    n=s.size();
    s='#'+s;
    m=t.size();
    for(ll i=m; i<=n; i++){
        ll c=m;
        for(ll j=i; j>0; j--){
            if(s[j]==t[c-1]) c--;
            if(c==0){
                ls[i]=j;
                break;
            }
        }
    }
    memset(dp,-1,sizeof dp);
    dp[0][0]=0;
    for(ll i=1; i<=n; i++){
        for(ll j=0; j<=i; j++){
            if(j<i){
                dp[i][j]=dp[i-1][j];
            }
            if(j) dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            if(ls[i] && j>=i-ls[i]+1-m && j+m<=i) dp[i][j]=max(dp[i][j],dp[ls[i]-1][j-(i-ls[i]+1-m)]+1);
        }
    }
    for(ll i=0; i<=n; i++) cout << dp[n][i] << ' ';
    cout << '\n';
    return 0;
}