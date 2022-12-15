#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
long long mod=1e9+7;
int dp[1000005][20][2],n;
int main() {
    int T = 1;
    //cin >> T;
    while (T--){
        cin>>n;
        int mx=log2(n),mx2=0;
        dp[1][mx][0]=1;
        if((1<<(mx-1))*3<=n) dp[1][mx-1][1]=1,mx2=1;
        for(int i=2;i<=n;i++)
            for(int j=0;j<=mx;j++)
                for(int k=0;k<=mx2;k++){
                    dp[i][j][k]+=1LL*dp[i-1][j][k]*(n/((1<<j)*(k>0?3:1))-i+1)%mod,dp[i][j][k]%=mod;
                    if(j<mx) dp[i][j][k]+=1LL*dp[i-1][j+1][k]*(n/((1<<j)*(k>0?3:1))-n/((1<<(j+1))*(k>0?3:1)))%mod,dp[i][j][k]%=mod;
                    if(k<mx2) dp[i][j][k]+=1LL*dp[i-1][j][k+1]*(n/((1<<j))-n/((1<<j)*3))%mod,dp[i][j][k]%=mod;
                    //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
                }
        cout<<dp[n][0][0]<<endl;
    }
    return 0;
}
//
/// 
//01
//
//!