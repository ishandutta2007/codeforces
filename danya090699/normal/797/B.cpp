#include <bits/stdc++.h>
using namespace std;
int mo(int x)
{
    if(x>=0) return x;
    else return -x;
}
int main()
{
    int n, inf=-2e9;
    cin>>n;
    int dp[n+1][2];
    for(int a=0; a<=n; a++)
    {
        dp[a][0]=inf, dp[a][1]=inf;
    }
    dp[0][0]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        dp[a+1][0]=dp[a][0], dp[a+1][1]=dp[a][1];
        if(dp[a][0]!=inf)
        {
            if(mo(x)%2==0) dp[a+1][0]=max(dp[a+1][0], dp[a][0]+x);
            else dp[a+1][1]=max(dp[a+1][1], dp[a][0]+x);
        }
        if(dp[a][1]!=inf)
        {
            if(mo(x)%2==0) dp[a+1][1]=max(dp[a+1][1], dp[a][1]+x);
            else dp[a+1][0]=max(dp[a+1][0], dp[a][1]+x);
        }
    }
    if(dp[n][1]==inf) cout<<-1;
    else cout<<dp[n][1];
}