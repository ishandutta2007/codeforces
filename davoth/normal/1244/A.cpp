#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=4e3+10,LN=22;
const int MOD=1000000009;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=1;
    if(y%2) b=x;
    return pow(x*x%mod,a,mod)*b%mod;
}
ll t;
int main() {
    cin >> t;
    while(t--){
        ll a,b,c,d,k,a1,a2;
        cin >> a >> b >> c >> d >> k;
        a1=a/c;
        a2=b/d;
        if(a%c!=0) a1++;
        if(b%d!=0) a2++;
        if(a1+a2>k) cout << -1 << '\n';
        else cout << a1 << ' ' << a2 << '\n';
    }
}