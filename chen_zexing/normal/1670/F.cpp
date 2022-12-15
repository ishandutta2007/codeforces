#include <cstdio>
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
int n;
long long x;
long long c[1005][1005],dp[65][2005];
long long solve(long long tot){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<60;i++){
        for(int j=0;j<=n*2;j++){
            for(int k=0;k<=min(j,n);k++){
                if(k%2==(((1LL<<i)&x)>0)){
                    if(i) dp[i][j]+=dp[i-1][min((j-k)*2+(((1LL<<(i-1))&tot)>0),n*2)]*c[n][k]%mod,dp[i][j]%=mod;
                    else dp[i][j]+=c[n][k],dp[i][j]%=mod;
                }
            }
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    return dp[59][((1LL<<59)&x)>0];
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        long long l,r;
        cin>>n>>l>>r>>x;
        c[0][0]=c[1][0]=c[1][1]=1;
        for(int i=2;i<=n;i++){
            c[i][0]=1;
            for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
        //cout<<solve(r)<<" "<<solve(l-1)<<endl;
        printf("%lld\n",(solve(r)-solve(l-1)+mod)%mod);
    }
    return 0;
}
//unordered_map