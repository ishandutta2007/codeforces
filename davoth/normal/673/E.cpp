#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,M=1e5+4,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007  /*998244353*/;
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
ll a[N],n,k;
double dp[52][N],re[N],ps[N];
void solve(ll c, ll l, ll r, ll tl, ll tr){
    if(l>r) return;
    ll m=(l+r)>>1,md=tl;
    for(ll i=tl; i<=min(m,tr); i++){
        double t=dp[c-1][i-1]+dp[1][m]-dp[1][i-1]-ps[i-1]*(re[m]-re[i-1]);
        if(t<dp[c][m]){
            dp[c][m]=t;
            md=i;
        }
    }
    solve(c,l,m-1,tl,md);
    solve(c,m+1,r,md,tr);
}
int main(){
    fast_io;
    cin >> n >> k;
    for(ll i=0; i<=k; i++) for(ll j=0; j<=n; j++) dp[i][j]=INF;
    dp[1][0]=0;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        ps[i]=ps[i-1]+a[i];
        re[i]=re[i-1]+1.0/a[i];
        dp[1][i]=dp[1][i-1]+ps[i]/a[i];
    }
    for(ll i=2; i<=k; i++) solve(i,1,n,1,n);
    cout << dp[k][n] << '\n';
    return 0;
}