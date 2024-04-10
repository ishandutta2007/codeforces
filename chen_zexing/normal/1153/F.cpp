#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
long long dp[4005][2005],cnt[4005][2005],mod=998244353;
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
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k,l;
        cin>>n>>k>>l;
        dp[1][1]=1;
        long long ans=0;
        for(int i=2;i<=n*2;i++){
            for(int j=0;j<=n;j++){
                dp[i][j+1]+=dp[i-1][j],cnt[i][j+1]+=cnt[i-1][j];
                if(j>=k) cnt[i][j+1]+=dp[i-1][j],ans%=mod;
                if(j){
                    dp[i][j-1]+=dp[i-1][j]*j%mod,cnt[i][j-1]+=cnt[i-1][j]*j%mod;
                    if(j>=k) cnt[i][j-1]+=dp[i-1][j]*j%mod,ans%=mod;
                }
            }
            for(int j=0;j<=n;j++) dp[i][j]%=mod,cnt[i][j]%=mod;
        }
        ans=cnt[n*2][0];
        long long temp=1;
        for(int i=n*2-1;i>=1;i-=2) temp=temp*i%mod;
        //cout<<ans<<" "<<temp<<endl;
        ans*=qpow(temp,mod-2),ans%=mod;
        ans*=qpow(n*2+1,mod-2),ans%=mod;
        ans*=l,ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
//