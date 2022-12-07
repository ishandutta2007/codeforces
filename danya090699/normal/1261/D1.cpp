#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    int dp[2*n+1], dp2[2*n+1];
    for(int a=0; a<=2*n; a++) dp[a]=0, dp2[a]=0;
    dp[n]=1;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<=2*n; b++)
        {
            if(dp[b])
            {
                if(ar[a]==ar[(a+1)%n]) dp2[b]=(dp2[b]+1ll*k*dp[b])%mod;
                else
                {
                    dp2[b-1]=(dp2[b-1]+dp[b])%mod;
                    dp2[b+1]=(dp2[b+1]+dp[b])%mod;
                    dp2[b]=(dp2[b]+1ll*(k-2)*dp[b])%mod;
                }
            }
        }
        for(int b=0; b<=2*n; b++) dp[b]=dp2[b], dp2[b]=0;
    }
    int an=0;
    for(int a=n+1; a<=n*2; a++) an=(an+dp[a])%mod;
    cout<<an;
}