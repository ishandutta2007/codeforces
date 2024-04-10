#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=998244353;
const int MN=2e5+1;
ll arr[MN],tp[MN];
int active[MN];
ll psa[MN];
ll dp[MN][2];//0 is start from 0 get to portal, 1 is start from tp location, get back to portal everything active
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i]>>tp[i]>>active[i];
    }
    dp[1][0]=arr[1];
    dp[1][1]=arr[1]-tp[1];
    psa[1]=dp[1][1];
    for(int i=2;i<=n;i++){
        dp[i][0]=(dp[i-1][0]+(active[i-1]?dp[i-1][1]:0)+arr[i]-arr[i-1])%mod;
        int loc=lower_bound(arr+1,arr+1+n,tp[i])-arr;
        dp[i][1]=(arr[i]-tp[i]+psa[i-1]-psa[loc-1]+mod)%mod;
        psa[i]=(psa[i-1]+dp[i][1])%mod;
    }
    printf("%lli\n",(dp[n][0]+(active[n]?dp[n][1]:0)+1)%mod);
    return 0;
}