#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,SQ=550,M=5e4+10;
const ll INF=1e16;
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
ll n,a[N],px[N],ans=INF;
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++) cin >> a[i];
    //cout << (a[1]^0);
    ll p=1;
    for(ll i=0; i<=30; i++){
        for(ll i=1; i<=n-2; i++){
            if(a[i+2]<p*2 && a[i]>=p) return cout << 1 << '\n', 0;
        }
        p=p<<1;
    }
    px[0]=0;
    for(ll i=1; i<=n; i++) px[i]=(px[i-1]^a[i]);
    for(ll i=0; i<=n; i++){
        for(ll j=i+1; j<=n; j++){
            for(ll k=j+1; k<=n; k++){
                if((px[j]^px[i])>(px[k]^px[j])) ans=min(ans,k-i-2);
                //if(i==0 && j==1 && k==2) cout << (px[j]^px[i]) << ' ' << (px[k]^px[j]) << '\n';
            }
        }
    }
    if(ans==INF) ans=-1;
    cout << ans << '\n';
    return 0;
}