#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e2+10,LN=20,SQ=547,M=1e6+10;
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
ll n,m,t,a[N][N];
map<ll,bool> c;
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cin >> a[i][j];
                if(a[i][j]%2!=(i+j)%2) a[i][j]++;
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}