//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, mod=1e9+7;
    cin>>n;
    int dp[n+1][n+1];
    for(int a=0; a<=n; a++) for(int b=0; b<=n; b++) dp[a][b]=0;
    dp[1][0]=1, dp[1][1]=1;
    for(int a=2; a<=n; a++)
    {
        for(int b=0; b<=(n-a+1); b++)
        {
            for(int ql=0; ql<=b; ql++)
            {
                int qr=b-ql;
                int qq=(1ll*dp[a-1][ql]*dp[a-1][qr])%mod;
                dp[a][b]=(dp[a][b]+qq)%mod;
                dp[a][b]=(dp[a][b]+2ll*qq*b)%mod;
            }
            for(int ql=0; ql<=b-1; ql++)
            {
                int qr=b-1-ql;
                int qq=(1ll*dp[a-1][ql]*dp[a-1][qr])%mod;
                dp[a][b]=(dp[a][b]+qq)%mod;
            }
            for(int ql=0; ql<=b+1; ql++)
            {
                int qr=b+1-ql;
                int qq=(1ll*dp[a-1][ql]*dp[a-1][qr])%mod;
                int q2=(b+1)*b;
                dp[a][b]=(dp[a][b]+1ll*qq*q2)%mod;
            }
        }
    }
    cout<<dp[n][1];
}