#include <bits/stdc++.h>
using namespace std;
const int sz=5e2+10, mod=1e9+7;
bool sm[sz][sz];
int dp[sz][sz], dp2[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        dp[1][a]=1, dp2[1][a]=1;
        for(int b=0; b<n; b++) cin>>sm[a][b];
    }
    for(int a=2; a<=n; a++)
    {
        for(int b=0; b+a<=n; b++)
        {
            for(int c=b+1; c<b+a; c++)
            {
                if(sm[b][c]) dp[a][b]=(dp[a][b]+1ll*dp[c-b][b]*dp[a+b-c][c])%mod;
                if(sm[a+b][c])
                {
                    dp[a][b]=(dp[a][b]+1ll*dp2[c-b][b]*dp[a+b-c][c])%mod;
                    dp2[a][b]=(dp2[a][b]+1ll*dp2[c-b][b]*dp[a+b-c][c])%mod;
                }
            }
        }
    }
    cout<<dp[n][0];
}