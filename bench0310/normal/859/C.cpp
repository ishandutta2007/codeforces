#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int sum[n],dp[n][2];
    sum[n-1]=a[n-1];
    dp[n-1][0]=0;
    dp[n-1][1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        sum[i]=sum[i+1]+a[i];
        dp[i][1]=max(dp[i+1][0]+a[i],dp[i+1][1]);
        dp[i][0]=sum[i]-dp[i][1];
    }
    printf("%d %d\n",dp[0][0],dp[0][1]);
    return 0;
}