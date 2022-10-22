#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=22,SQ=547,M=4.2e6+10;
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
ll n,k,a[N],ans;
vector<ll> lis;
bool b[N];
int main(){
    fast_io;
    cin >> n >> k;
    for(ll i=1; i<=n; i++) cin >> a[i];
    for(ll i=0; i<k; i++){
        ll t;
        cin >> t;
        b[t]=1;
    }
    a[0]=-INF;
    a[n+1]=INF;
    b[0]=b[n+1]=1;
    for(ll i=1; i<=n+1; i++) a[i]-=i;
    lis.pb(a[0]);
    for(ll i=1; i<=n+1; i++){
        ll l=-1,r=lis.size();
        while(r-l>1){
            ll m=(l+r)/2;
            if(lis[m]<=a[i]) l=m;
            else r=m;
        }
        if(b[i]){
            if(r==0) return cout << -1 << '\n', 0;
            ans+=r;
            lis={a[i]};
        }else{
            if(r==0) continue;
            if(r==lis.size()) lis.pb(a[i]);
            else lis[r]=a[i];
        }
    }
    cout << n-ans+1 << '\n';
    return 0;
}