#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10,LN=22;
const int MOD=1000000007;
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
ll n,P[]={2,3,5,7,11,13,17,19,23},ans=1e18;
void f(ll k, ll x, ll it){
    if(k>n || it>8) return;
    if(n==k && x<ans) ans=x;
    for(ll i=1; i<=60; i++){
        if(x*P[it]>=ans) return;
        x*=P[it];
        f(k*(i+1),x,it+1);
    }
}
int main() {
    cin >> n;
    f(1,1,0);
    cout << ans;
}