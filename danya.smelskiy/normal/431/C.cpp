#include <bits/stdc++.h>
using namespace std;
int n,k,d;
int dp[10000][2];
int main(){
    // dp: 1-not 2-yes
    cin>>n>>k>>d;
    dp[0][1]=1;
    for (int i=1;i<=n;++i){
        for (int j=i-1;j>=max(0,i-d);--j){
            if (j==i-d) break;
            dp[i][1]=(dp[i][1]+dp[j][1])%1000000007;
        }
        for (int j=i-1;j>=max(i-k,0);--j){
            dp[i][2]=(dp[i][2]+dp[j][2])%1000000007;
            if (j<=i-d) dp[i][2]=(dp[i][2]+dp[j][1])%1000000007;
        }
    }
    cout<<dp[n][2];
}