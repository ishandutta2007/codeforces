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
const int N=3e4+10,LN=20,SQ=550,M=1e1+10;
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
ll n,q,c[N],d[N],dp[N];
pll a[N],b[N];
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=1; i<=n; i++){
        cin >> a[i].F;
        a[i].S=i;
    }
    for(ll i=1; i<=n; i++){
        cin >> b[i].F;
        b[i].S=i;
    }
    sort(b+1,b+n+1,greater<pll>());
    sort(a+1,a+n+1,greater<pll>());
    for(ll i=1; i<=n; i++) d[a[i].S]=i;
    while(q--){
        ll x,y;
        cin >> x >> y;
        swap(a[d[x]].S,a[d[y]].S);
        for(ll i=1; i<=n; i++){
            dp[i]=0;
            if(a[i].S!=b[i].S) dp[i]=a[i].F*b[i].F+dp[i-1];
            if(i>1 && a[i].S!=b[i-1].S && a[i-1].S!=b[i].S) dp[i]=max(dp[i],a[i].F*b[i-1].F+a[i-1].F*b[i].F+dp[i-2]);
            if(i>2){
                if(a[i].S!=b[i-2].S){
                    if(a[i-1].S!=b[i-1].S && a[i-2].S!=b[i].S) dp[i]=max(dp[i],a[i].F*b[i-2].F+a[i-1].F*b[i-1].F+a[i-2].F*b[i].F+dp[i-3]);
                    if(a[i-1].S!=b[i].S && a[i-2].S!=b[i-1].S) dp[i]=max(dp[i],a[i].F*b[i-2].F+a[i-1].F*b[i].F+a[i-2].F*b[i-1].F+dp[i-3]);
                }
                if(a[i].S!=b[i-1].S && a[i-1].S!=b[i-2].S && a[i-2].S!=b[i].S) dp[i]=max(dp[i],a[i].F*b[i-1].F+a[i-1].F*b[i-2].F+a[i-2].F*b[i].F+dp[i-3]);
            }
        }
        cout << dp[n] << '\n';
    }
    return 0;
}