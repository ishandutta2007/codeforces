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
ll n,r,A[N],B[N];
vector<pair<ll,ll> > pos,neg;
int main() {
    fast_io;
    cin >> n >> r;
    for(int i=0; i<n; i++){
        cin >> A[i] >> B[i];
        if(B[i]>=0) pos.emplace_back(A[i],i);
        else{
            A[i]=max(A[i],-B[i]);
            neg.emplace_back(A[i]+B[i],i);
        }
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end(),greater<pll>());
    for(pll p : pos){
        if(p.F>r) return cout << "NO",0;
        r+=B[p.S];
    }
    for(pll p : neg){
        if(A[p.S]>r) return cout << "NO",0;
        r+=B[p.S];
    }
    cout << "YES";
    return 0;
}