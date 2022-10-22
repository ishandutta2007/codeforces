#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e2+10,LN=20,SQ=550,M=5e4+10;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,a[N],b[N];
double dp[N][N*N],ans[N],s;
int main(){
    fast_io;
    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> a[i] >> b[i];
        s+=b[i];
    }
    for(ll k=0; k<=n; k++) for(ll i=0; i<N*N; i++) dp[k][i]=-1e5;
    dp[0][0]=0;
    for(ll i=0; i<n; i++){
        for(ll k=n; k>=1; k--){
            for(ll j=a[i]; j<N*N; j++){
                dp[k][j]=max(dp[k][j],dp[k-1][j-a[i]]+b[i]);
            }
        }
    }
    for(ll i=1; i<=n; i++) for(ll j=0; j<N*N; j++){
        ans[i]=max(ans[i],min(j*1.0,s/2+dp[i][j]/2));
    }
    cout << fixed << setprecision(10);
    for(ll i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}