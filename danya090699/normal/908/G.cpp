#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7, sz=800;
int dp[sz][sz][2];
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), an=0;
    for(int a=1; a<=9; a++)
    {
        for(int b=0; b<=n; b++) for(int c=0; c<=n; c++) for(int d=0; d<2; d++) dp[b][c][d]=0;
        dp[0][0][1]=1;
        for(int b=0; b<n; b++)
        {
            for(int c=0; c<=b; c++)
            {
                for(int d=0; d<2; d++)
                {
                    if(d==0)
                    {
                        dp[b+1][c][d]=(dp[b+1][c][d]+1ll*a*dp[b][c][d])%mod;
                        dp[b+1][c+1][d]=(dp[b+1][c+1][d]+1ll*(10-a)*dp[b][c][d])%mod;
                    }
                    else
                    {
                        int cu=s[b]-'0';
                        dp[b+1][c+(cu>=a)][d]=(dp[b+1][c+(cu>=a)][d]+dp[b][c][d])%mod;
                        dp[b+1][c][0]=(dp[b+1][c][0]+1ll*min(cu, a)*dp[b][c][d])%mod;
                        if(a<cu) dp[b+1][c+1][0]=(dp[b+1][c+1][0]+1ll*(cu-a)*dp[b][c][d])%mod;
                    }
                }
            }
        }
        int cu=1;
        for(int b=1; b<=n; b++)
        {
            an=(an+1ll*cu*(dp[n][b][0]+dp[n][b][1]))%mod;
            cu=(1ll*10*cu+1)%mod;
        }
    }
    cout<<an;
}