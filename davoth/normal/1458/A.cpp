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
const int N=3e5+10,LN=20,SQ=550,M=5e4+10;
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
ll n,m,a[N],b[N],gc;
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    for(ll i=1; i<n; i++) a[i]=a[i]-a[0];
    for(ll i=0; i<m; i++) cin >> b[i];
    if(n==1){
        for(ll i=0; i<m; i++) cout << a[0]+b[i] << ' ';
    }else{
        gc=a[1];
        for(ll i=2; i<n; i++) gc=__gcd(a[i],gc);
        for(ll i=0; i<m; i++) cout << __gcd(a[0]+b[i],gc) << ' ';
    }
    cout << '\n';
    return 0;
}