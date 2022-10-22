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
const int N=1e3+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
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
ll n,m,a[50],nxt[50][2],f[50],dp[50][50],ans;
string s;
int main(){
    fast_io;
    cin >> n >> s;
    m=s.size();
    for(ll i=1; i<=m; i++) a[i]=s[i-1]-'0';
    nxt[0][a[1]]=1;
    for(ll i=1; i<m; i++){
        nxt[i][a[i+1]]=i+1;
        nxt[i][a[i+1]^1]=nxt[f[i]][a[i+1]^1];
        f[i+1]=nxt[f[i]][a[i+1]];
    }
    nxt[m][0]=nxt[f[m]][0];
    nxt[m][1]=nxt[f[m]][1];
    for(ll i=0; i<m; i++){
        memset(dp,0,sizeof dp);
        dp[0][i]=1;
        for(ll j=1; j<=n; j++){
            for(ll k=0; k<m; k++){
                dp[j][nxt[k][0]]+=dp[j-1][k];
                dp[j][nxt[k][1]]+=dp[j-1][k];
            }
        }
        ans+=dp[n][i];
    }
    cout << (1ll<<n)-ans << '\n';
    return 0;
}