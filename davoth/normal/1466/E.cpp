#include <bits/stdc++.h>
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=60,SQ=550,M=5e4+10;
const ll INF=2e18;
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
ll t;
int main(){
    fast_io;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n],bt[LN],ans=0;
        memset(bt,0,sizeof bt);
        for(ll i=0; i<n; i++) cin >> a[i];
        for(ll i=0; i<n; i++){
            for(ll j=0,p=1; j<LN; j++,p*=2){
                if(a[i]&p) bt[j]++;
            }
        }
        for(ll i=0; i<n; i++){
            ll t1=0,t2=0;
            for(ll j=0,p=1; j<LN; j++,p*=2){
                if(a[i]&p){
                    t1=(t1+p%MOD*n)%MOD;
                    t2=(t2+p%MOD*bt[j])%MOD;
                }else t1=(t1+p%MOD*bt[j])%MOD;
            }
            ans=(ans+t1*t2)%MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}