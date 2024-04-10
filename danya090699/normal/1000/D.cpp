#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, mod=998244353;
    cin>>n;
    int dp[n+1][n+1];
    for(int a=0; a<=n; a++) for(int b=0; b<=n; b++) dp[a][b]=0;
    dp[0][0]=1;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        dp[a+1][0]=(dp[a+1][0]+dp[a][0])%mod;
        if(x>0 and x<=n) dp[a+1][x]=(dp[a+1][x]+dp[a][0])%mod;
        for(int b=1; b<=n; b++)
        {
            dp[a+1][b]=(dp[a+1][b]+dp[a][b])%mod;
            dp[a+1][b-1]=(dp[a+1][b-1]+dp[a][b])%mod;
        }
        //for(int b=0; b<=n; b++) cout<<dp[a+1][b]<<" ";
        //cout<<"\n";
    }
    int an=dp[n][0]-1;
    if(an<0) an+=mod;
    cout<<an;
}