#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int dp[4][n*2+1], dp2[4][n*2+1];
    for(int a=0; a<4; a++)
    {
        for(int b=1; b<=n*2; b++) dp[a][b]=0, dp2[a][b]=0;
    }
    dp[0][1]=1, dp[3][1]=1, dp[1][2]=1, dp[2][2]=1;
    for(int a=1; a<n; a++)
    {
        for(int b=0; b<4; b++)
        {
            for(int c=0; c<4; c++)
            {
                for(int d=1; d<=n*2; d++)
                {
                    if(dp[b][d])
                    {
                        int qpr=1, qne=1, add=0;
                        if(b==1 or b==2) qpr++;
                        if(c==1 or c==2) qne++;
                        if(qpr==1 and qne==1)
                        {
                            if(b!=c) add=1;
                        }
                        if(qpr==1 and qne==2) add=1;
                        if(qpr==2 and qne==1) add=0;
                        if(qpr==2 and qne==2)
                        {
                            if(b!=c) add=2;
                        }
                        dp2[c][d+add]=(dp2[c][d+add]+dp[b][d])%mod;
                    }
                }

            }
        }
        for(int b=0; b<4; b++)
        {
            for(int c=1; c<=n*2; c++)
            {
                dp[b][c]=dp2[b][c], dp2[b][c]=0;
            }
        }
    }
    int an=0;
    for(int a=0; a<4; a++) an=(an+dp[a][k])%mod;
    cout<<an;
}