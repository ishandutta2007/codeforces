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
ll n,a,b,c,d,e,f;
vector<pair<ll,ll> > pos,neg;
int main() {
    fast_io;
    cin >> n;
    for(int i=0; i<n; i++){
        ll k;
        cin >> k;
        if(k==4) a++;
        if(k==8 && a) b++,a--;
        if(k==15 && b) c++,b--;
        if(k==16 && c) d++,c--;
        if(k==23 && d) e++,d--;
        if(k==42 && e) f++,e--;
    }
    cout << n-f*6;
    return 0;
}