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
        ll n,ans=0;
        cin >> n;
        while(n%2==0) n/=2,ans++;
        while(n%3==0) n/=3,ans+=2;
        while(n%5==0) n/=5,ans+=3;
        if(n==1) cout << ans;
        else cout << -1;
        cout << '\n';
    }
    return 0;
}