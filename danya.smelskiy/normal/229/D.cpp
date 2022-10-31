#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int dp[5005][5005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<=n;++i)
        for (int j=0;j<=n;++j)
            dp[i][j]=1e9;
    dp[0][0]=0;
    for (int i=0;i<n;++i) {
        for (int j=i-1;j>=0;--j)
            dp[i][j]=min(dp[i][j],dp[i][j+1]);
        int j=0;
        int sum=0;
        for (int k=i+1;k<=n;++k) {
            sum+=a[k];
            while (j<i && (dp[i][j]==1e9 || dp[i][j+1]<=sum)) ++j;
            if (dp[i][j]<=sum) dp[k][j+1]=min(dp[k][j+1],sum);
        }
    }
    for (int i=n;i>=0;--i)
    if (dp[n][i]!=1e9) {
        cout<<n-i;
        return 0;
    }
}