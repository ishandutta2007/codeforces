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
const int N=1e5+10,LN=20,M=1e5+4,SQ=350,B=737,inf=1e9;
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
int n,a[N],b[N],k;
ll dp[21][N],t;
void solve(int c, int l, int r, int tl, int tr){
    if(l>r) return;
    int m=(l+r)>>1,md=-1;
    for(int i=l; i<=m; i++){
        t+=b[a[i]];
        b[a[i]]++;
    }
    for(int i=tl; i<=min(m,tr); i++){
        b[a[i]]--;
        t-=b[a[i]];
        if(dp[c-1][i]+t<dp[c][m]){
            dp[c][m]=dp[c-1][i]+t;
            md=i;
        }
    }
    for(int i=min(tr,m); i>=md; i--){
        t+=b[a[i]];
        b[a[i]]++;
    }
    solve(c,m+1,r,md,tr);
    for(int i=l; i<=m; i++){
        b[a[i]]--;
        t-=b[a[i]];
    }
    for(int i=tl; i<md; i++){
        t+=b[a[i]];
        b[a[i]]++;
    }
    solve(c,l,m-1,tl,md);
}
int main(){
    fast_io;
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    memset(dp,63,sizeof dp);
    dp[0][0]=0;
    b[0]=1;
    for(int i=1; i<=k; i++) solve(i,1,n,0,n);
    cout << dp[k][n] << '\n';
    return 0;
}