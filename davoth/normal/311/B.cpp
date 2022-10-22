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
#define killshayan kill("done!\n")
#define killmashtali kill("Hello, World!")
const int N=1e5+10,LN=19,M=3e2+10,SQ=256,B=737,inf=1e9;
const ll INF=1e18;
const double pi=acos(-1);
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
ll n,m,p,d[N],a[N],ans,dp[101][N];
void solve(ll c, ll l, ll r, ll tl, ll tr){
    if(l>=r) return;
    ll t=tl,m=(l+r)>>1;
    for(ll i=tl; i<=min(m,tr); i++){
        if(dp[c][m]>dp[c-1][i-1]+a[m]*(m-i+1)){
            dp[c][m]=dp[c-1][i-1]+a[m]*(m-i+1);
            t=i;
        }
    }
    solve(c,l,m,tl,t);
    solve(c,m+1,r,t,tr);
}
int main(){
    fast_io;
    cin >> n >> m >> p;
    p=min(p,m);
    for(ll i=2; i<=n; i++){
        cin >> d[i];
        d[i]+=d[i-1];
    }
    for(ll i=1; i<=m; i++){
        ll x,y;
        cin >> x >> y;
        x=d[x];
        a[i]=y-x;
        ans-=a[i];
    }
    sort(a+1,a+m+1);
    memset(dp,63,sizeof dp);
    dp[0][0]=0;
    for(ll i=1; i<=p; i++) solve(i,1,m+1,1,m);
    cout << dp[p][m]+ans << '\n';
    return 0;
}