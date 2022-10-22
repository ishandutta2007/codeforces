#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = /*long long*/ int;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=4e3+10,LN=20,M=1e5+4,SQ=350,B=737,inf=1e9;
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
int n,k,a[N][N],p[N][N],P[N][N],dp[N],pd[N];
void solve(ll l, ll r, ll tl, ll tr){
    if(l==r) return;
    int m=(l+r)>>1,mt,y=inf;
    for(ll i=tl; i<min(m,tr); i++){
        int x=dp[i]+P[i+1][m];
        if(x<y) y=x,mt=i;
    }
    pd[m]=y;
    solve(l,m,tl,mt+1);
    solve(m+1,r,mt,tr);
}
int main(){
    fast_io;
    cin >> n >> k;
    //if(n==k) return cout << 0 << '\n', 0;
    cin.ignore();
    for(ll i=1; i<=n; i++){
        string s;
        getline(cin,s);
        for(ll j=1; j<=n; j++){
            a[i][j]=s[2*(j-1)]-'0';
            p[i][j]=a[i][j]+p[i][j-1];
        }
    }
    for(ll i=1; i<=n; i++){
        for(ll j=i+1; j<=n; j++){
            P[i][j]=P[i][j-1]+p[j][j]-p[j][i-1];
        }
    }
    for(ll i=0; i<=n; i++) dp[i]=P[1][i];
    for(ll i=2; i<=k; i++){
        solve(1,n+1,0,n);
        memcpy(dp,pd,sizeof dp);
    }
    cout << dp[n] << '\n';
    return 0;
}