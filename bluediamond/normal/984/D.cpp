#include <bits/stdc++.h>

using namespace std;

const int N=5000;

int n,dp[N+5][N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>dp[1][i];
    for(int l=2;l<=n;l++)
        for(int j=1;j+l-1<=n;j++)
            dp[l][j]=dp[l-1][j]^dp[l-1][j+1];
    for(int l=2;l<=n;l++)
        for(int j=1;j+l-1<=n;j++)
        {
            dp[l][j]=max(dp[l][j],dp[l-1][j]);
            dp[l][j]=max(dp[l][j],dp[l-1][j+1]);
        }
    int test;
    cin>>test;
    while(test--)
    {
        int st,dr;
        cin>>st>>dr;
        cout<<dp[dr-st+1][st]<<"\n";
    }
    return 0;
}