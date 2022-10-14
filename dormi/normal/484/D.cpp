#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
ll dp[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    ll a;
    cin>>n;
    ll mibest=LLONG_MIN,mabest=LLONG_MIN;
    for(int i=1;i<=n;i++){
        cin>>a;
        mibest=max(mibest,dp[i-1]-a);
        mabest=max(mabest,dp[i-1]+a);
        dp[i]=max(mibest+a,mabest-a);
    }
    printf("%lli\n",dp[n]);
    return 0;
}