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
const int N=5e3+10,LN=20,M=1e5+4,SQ=350,B=737,inf=1e9;
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
ll a[N],b[N],ans,n,an;
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++) cin >> a[i];
    for(ll i=1; i<=n; i++){
        cin >> b[i];
        ans+=b[i]*a[i];
    }
    an=ans;
    for(ll i=1; i<=n; i++){
        ll t=an;
        for(ll j=1; j+i<=n && j<i; j++){
            t-=a[j+i]*b[j+i]+a[i-j]*b[i-j];
            t+=a[j+i]*b[i-j]+a[i-j]*b[j+i];
            ans=max(ans,t);
        }
    }
    for(ll i=1; i<n; i++){
        ll t=an-a[i]*b[i]-a[i+1]*b[i+1]+(a[i]*b[i+1]+a[i+1]*b[i]);
        ans=max(ans,t);
        for(ll j=1; j<i && i+j+1<=n; j++){
            t-=a[i-j]*b[i-j]+a[i+j+1]*b[i+j+1];
            t+=a[i-j]*b[i+j+1]+a[i+j+1]*b[i-j];
            ans=max(ans,t);
        }
    }
    cout << ans << '\n';
    return 0;
}