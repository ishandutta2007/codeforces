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
const int N=1e4+10,LN=20,M=2e7+10,SQ=350,B=737,inf=1e9;
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
int n,a[N],dp[M],ans;
int main(){
    fast_io;
    cin >> n;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=0; j<3; j++){
            int x=s[j]-'a';
            a[i]|=(1<<x);
        }
        dp[a[i]]++;
    }
    for(int i=0; i<24; i++){
        for(int j=0; j<(1<<24); j++){
            if(j&(1<<i)) dp[j]+=dp[j^(1<<i)];
        }
    }
    for(int i=0; i<(1<<24); i++) ans^=(n-dp[(1<<24)-1-i])*(n-dp[(1<<24)-1-i]);
    cout << ans << '\n';
    return 0;
}