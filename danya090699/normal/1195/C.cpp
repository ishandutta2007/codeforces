#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[2][n], dp[2][n+1];
    dp[0][0]=0, dp[1][0]=0;
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++)
        {
            scanf("%lld", &ar[i][a]);
            dp[i][a+1]=0;
        }
    }
    for(int a=0; a<n; a++)
    {
        for(int i=0; i<2; i++)
        {
            dp[i][a+1]=max(dp[i][a+1], dp[i][a]);
            dp[i^1][a+1]=max(dp[i^1][a+1], dp[i][a]+ar[i][a]);
        }
    }
    cout<<max(dp[0][n], dp[1][n]);
}