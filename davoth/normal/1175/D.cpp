#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10;
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
ll n,k,a[N],sum[N],ans;
vector<ll> an;
int main() {
    fast_io;
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> a[i];
    sum[n-1]=a[n-1];
    for(int i=n-2; i>=0; i--) sum[i]=a[i]+sum[i+1],an.push_back(sum[i+1]);
    sort(an.begin(),an.end(),greater<ll>());
    ans=sum[0];
    for(int i=0; i<k-1; i++) ans+=an[i];
    cout << ans;
    return 0;
}