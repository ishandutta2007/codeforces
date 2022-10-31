#include <bits/stdc++.h>
using namespace std;
const long long inf=-1e15;
int n;
long long a[4][100005];
long long dp[4][100005];
long long dp2[4];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=3;++i){
        for (int j=1;j<=n;++j)
            cin>>a[i][j];
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=3;++j)
        dp[j][i]=inf;
    dp[1][1]=a[1][1];
    dp[2][1]=a[2][1]+dp[1][1];
    dp[3][1]=a[3][1]+dp[2][1];
    for (int i=1;i<=n;++i) {
            for (int k=1;k<=3;++k)
                dp2[k]=dp[k][i];
            if (i>1) {
            dp[1][i]=max(dp[1][i],max(dp2[2]+a[1][i],dp2[3]+a[1][i]+a[2][i]));
            dp[2][i]=max(dp[2][i],max(dp2[1]+a[2][i],dp2[3]+a[2][i]));
            dp[3][i]=max(dp[3][i],max(dp2[2]+a[3][i],dp2[1]+a[3][i]+a[2][i]));
            }
            if (i>=2) {
                    if (i>2) dp[1][i]=max(dp[1][i],a[1][i]+a[2][i]+a[3][i]+a[1][i-1]+a[2][i-1]+a[3][i-1]+dp[3][i-2]);
                    dp[3][i]=max(dp[3][i],a[1][i]+a[2][i]+a[3][i]+a[1][i-1]+a[2][i-1]+a[3][i-1]+dp[1][i-2]);
            }
            dp[1][i+1]=max(dp[1][i+1],dp[1][i]+a[1][i+1]);
            dp[2][i+1]=max(dp[2][i+1],dp[2][i]+a[2][i+1]);
            dp[3][i+1]=max(dp[3][i+1],dp[3][i]+a[3][i+1]);
    }
    cout<<dp[3][n];
}