#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=30;
const int MOD=1000000007 /*998244353*/;
const ll INF=1e18;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,l[N],r[N],p[N],x[N],c[N],f[N],ans;
int main(){
    fast_io;
    cin >> n;
    for(ll i=0; i<n; i++) cin >> l[i];
    for(ll i=0; i<n; i++) cin >> r[i];
    c[0]=r[0]-l[0]+1;
    for(ll i=1; i<=n; i++){
        c[i]=r[i]-l[i]+1;
        x[i]=max(min(r[i],r[i-1])-max(l[i],l[i-1])+1,0ll);
        p[i]=(c[i]*c[i-1]-x[i])%MOD*pow(c[i]*c[i-1]%MOD,MOD-2,MOD)%MOD;
        ans=(ans+p[i])%MOD;
        f[i]=(f[i-1]+p[i])%MOD;
        if(n>1){
            ll y=max(min({r[i],r[i-1],r[i-2]})-max({l[i],l[i-1],l[i-2]})+1,0ll);
            ll k=(c[i]*c[i-1]%MOD*c[i-2]%MOD-x[i]%MOD*c[i-2]%MOD-x[i-1]%MOD*c[i]%MOD+y+3ll*MOD)%MOD*pow(c[i]*c[i-1]%MOD*c[i-2]%MOD,MOD-2,MOD)%MOD;
            ans=(ans+2*k)%MOD;
        }
        if(n>2){
            ans=(ans+2*p[i]*f[i-2])%MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}