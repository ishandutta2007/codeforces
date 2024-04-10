#include <bits/stdc++.h>
using namespace std;
const int md=1e9+7;
int n;
int dp[1000002][2];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-1][1];
        if (i&1) dp[i][0]=(dp[i-1][1]+dp[i][0]+1ll);
        else dp[i][1]=(dp[i-1][0]+dp[i][1]+1ll);
        if (dp[i][0]>=md) dp[i][0]-=md;
        if (dp[i][1]>=md) dp[i][1]-=md;
    }
    cout<<(dp[n][0]+dp[n][1])%md;
}