/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=4e3+10,LN=60,M=6.32e7+10,SQ=350,BS=737,inf=1.05e9,NSQ=N/SQ+1;
//const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,m,dp[(1<<20)];
ld pd[(1<<20)],ans;
string s[60];
int main(){
    fast_io;
    cin >> n;
    for(ll i=0; i<n; i++) cin >> s[i];
    m=s[1].size();
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            ll x=0;
            for(ll k=0; k<m; k++){
                if(s[i][k]==s[j][k]) x+=(1<<k);
            }
            dp[x]|=(1ll<<i)|(1ll<<j);
        }
    }
    for(ll i=0; i<m; i++){
        for(ll j=0; j<(1<<m); j++){
            if(!(j>>i&1)) dp[j]|=dp[j^(1<<i)];
        }
    }
    cout << setprecision(10) << fixed;
    pd[0]=1;
    for(ll i=1; i<(1<<m); i++){
        ll x=m-__builtin_popcountll(i)+1,y;
        for(ll j=0; j<m; j++){
            if(i>>j&1){
                y=i^(1<<j);
                if(dp[y]) pd[i]+=pd[y]*__builtin_popcountll(dp[i])/x/__builtin_popcountll(dp[y]);
                ans+=pd[y]/x;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}