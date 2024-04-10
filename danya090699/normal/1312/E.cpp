#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int dp[n+1][n+1];
    for(int a=0; a<=n; a++) for(int b=0; b<=n; b++) dp[a][b]=-1;
    for(int a=0; a<n; a++)
    {
        cin>>dp[a][a+1];
    }
    for(int l=2; l<=n; l++)
    {
        for(int a=0; a+l<=n; a++)
        {
            for(int b=a+1; b<a+l; b++)
            {
                if(dp[a][b]==dp[b][a+l] and dp[a][b]!=-1) dp[a][a+l]=dp[a][b]+1;
            }
        }
    }
    int dp2[n+1];
    for(int a=0; a<=n; a++) dp2[a]=1e9;
    dp2[0]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<=n; b++) if(dp[a][b]!=-1) dp2[b]=min(dp2[b], dp2[a]+1);
    }
    cout<<dp2[n];
}