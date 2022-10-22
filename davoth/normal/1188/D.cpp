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
const int N=1e5+10,LN=60,M=4e6+10,SQ=500,BS=737,inf=1.05e9,NSQ=N/SQ+1;
const ll INF=1e18;
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
ll n,a[N],p[LN][N],dp[LN][N],ps[N],ans=inf;
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(ll i=1; i<=n; i++) a[i]=a[n]-a[i];
    memset(dp,63,sizeof dp);
    for(ll t=0; t<LN; t++){
        for(ll i=1; i<=n; i++) p[t][i]=i;
        sort(p[t]+1,p[t]+n+1,[&](ll &x, ll &y){return (a[x]&((1ll<<(t+1))-1))<(a[y]&((1ll<<(t+1))-1));});
        ll z=n;
        for(ll i=1; i<=n; i++){
            if((a[i]>>t)&1) z--;
        }
        if(t==0){
            dp[0][n+1]=n-z;
            dp[0][z+1]=min(dp[0][z+1],z);
            continue;
        }
        for(ll i=n; i>=1; i--){
            ps[i]=ps[i+1]+((a[p[t-1][i]]>>t)&1);
        }
        for(ll i=1; i<=n+1; i++){
            if(dp[t-1][i]>inf) continue;
            dp[t][n+1-ps[i]]=min(dp[t][n+1-ps[i]],dp[t-1][i]+n-(ps[i]*2+i-1-ps[1]));
            dp[t][z+i+ps[i]-n]=min(dp[t][z+i+ps[i]-n],dp[t-1][i]+ps[i]*2+i-1-ps[1]);
        }
    }
    for(ll i=1; i<=n+1; i++) ans=min(ans,dp[LN-1][i]+n+1-i);
    cout << ans << '\n';
    return 0;
}