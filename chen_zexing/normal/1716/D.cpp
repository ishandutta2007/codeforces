#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long dp[200005],ans[200005],o[200005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        dp[0]=1;
        int st=0;
        for(int i=k;st<=n;i++){
            for(int j=st;j<=n;j++) o[j]=dp[j];
            for(int j=st;j<=n;j++) {
                if(j+i<=n) dp[j+i]+=dp[j],dp[j+i]%=mod;
                dp[j]-=o[j],ans[j]+=dp[j],ans[j]%=mod;
            }
            st+=i;
        }
        for(int i=1;i<=n;i++) printf("%lld ",(ans[i]%mod+mod)%mod);
    }
    return 0;
}