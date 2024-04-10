#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=4e6+2;
ll mod;
ll dp[MN],psa[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>mod;
    dp[1]=1;
    ll sum=1;
    for(int j=2;ll(j)*ll(1)<=n;j++){
        psa[j*1]=(psa[j*1]+dp[1])%mod;
        int end=min(n+1,j*1+(j));
        psa[end]=(psa[end]-dp[1]+mod)%mod;
    }
    for(int i=2;i<=n;i++){
        psa[i]=(psa[i]+psa[i-1])%mod;
        dp[i]=(psa[i]+sum)%mod;
        sum=(sum+dp[i])%mod;
        for(int j=2;ll(j)*ll(i)<=n;j++){
            psa[j*i]=(psa[j*i]+dp[i])%mod;
            int end=min(n+1,j*i+(j));
            psa[end]=(psa[end]-dp[i]+mod)%mod;
        }
    }
    printf("%lli\n",dp[n]);
    return 0;
}