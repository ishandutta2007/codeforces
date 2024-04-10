#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e2+10;
const int MOD=1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, int mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=1;
    if(y%2) b=x;
    return pow(x*x%mod,a,mod)*b%mod;
}
ll q;
int main() {
    fast_io;
    cin >> q;
    while(q--){
        ll n,m,k;
        cin >> n >> m >> k;
        bool c=1;
        ll H[n];
        for(int i=0; i<n; i++) cin >> H[i];
        for(int i=0; i<n-1; i++){
            if(H[i+1]-H[i]>k) m-=H[i+1]-H[i]-k;
            else if(H[i+1]<=k) m+=H[i];
            else m+=H[i]-H[i+1]+k;
            if(m<0) c=0;
        }
        if(c) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}