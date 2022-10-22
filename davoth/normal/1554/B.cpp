#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=19,M=5e6,SQ=350,B=737,inf=1e9+10;
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
ll t,n,dp[N],k,ans,pd[N],g[4];
int main(){
    fast_io;
    cin >> t;
    while(t--){
        ans=-inf;
        cin >> n >> k;
        ll p=1,lg=0;
        while(p<=n) p*=2,lg++;
        fill(dp,dp+(1<<lg),0);
        fill(pd,pd+(1<<lg),0);
        for(ll i=1; i<=n; i++){
            ll x;
            cin >> x;
            pd[x]=dp[x];
            dp[x]=i;
        }
        for(ll i=0; i<lg; i++){
            for(ll j=0; j<(1<<lg); j++){
                if(j&(1<<i)){
                    g[0]=dp[j];
                    g[1]=pd[j];
                    g[2]=dp[j^(1<<i)];
                    g[3]=pd[j^(1<<i)];
                    sort(g,g+4);
                    dp[j]=g[3];
                    pd[j]=g[2];
                }
            }
        }
        for(ll j=0; j<(1<<lg); j++){
            if(pd[j]){
                ans=max(ans,dp[j]*pd[j]-j*k);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}