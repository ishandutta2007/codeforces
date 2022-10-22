#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e3+10,LN=20,SQ=550,M=5e4+10;
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
ll n,q,k,a[3];
char c[N][N];
int main(){
    fast_io;
    cin >> q;
    while(q--){
        cin >> n;
        a[0]=a[1]=a[2]=0;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                cin >> c[i][j];
                if(c[i][j]=='X') a[(i+j)%3]++;
            }
        }
        ll t;
        if(a[0]<=a[1] && a[0]<=a[2]){
            t=0;
        }else if(a[1]<=a[0] && a[1]<=a[2]){
            t=1;
        }else{
            t=2;
        }
        for(ll i=0; i<n; i++) for(ll j=0; j<n; j++) if((i+j)%3==t && c[i][j]=='X') c[i][j]='O';
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++) cout << c[i][j];
            cout << '\n';
        }
    }
    return 0;
}