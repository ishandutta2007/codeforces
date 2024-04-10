#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
long long mod=1e9+7;
long long dp[2005][2005];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        m=n-m;
        long long iv2=qpow(2,mod-2);
        for(int i=0;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(i==0) dp[j][i]=(dp[j-1][i]+k)%mod;
                else dp[j][i]=(dp[j-1][i]+dp[j-1][i-1])*iv2%mod;
                //cout<<j<<" "<<i<<" "<<dp[j][i]<<endl;
            }
        printf("%lld\n",(dp[n][m]+mod)%mod);
    }
    return 0;
}
//unordered_map
//cf