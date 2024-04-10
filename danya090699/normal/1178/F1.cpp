#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    int dp[n+1][n+1], dp2[n+1][n+1];
    for(int a=0; a<=n; a++) dp[a][a]=1, dp2[a][a]=1;
    for(int a=1; a<=n; a++)
    {
        for(int l=0; l+a<=n; l++)
        {
            int r=l+a, mi=1e9, ll, rr;
            for(int b=l; b<r; b++)
            {
                if(ar[b]<mi) mi=ar[b], ll=b, rr=b+1;
            }
            dp[l][r]=(1ll*dp2[l][ll]*dp2[rr][r])%mod;

            dp2[l][r]=0;
            for(int b=l; b<=r; b++) dp2[l][r]=(dp2[l][r]+1ll*dp[l][b]*dp[b][r])%mod;
        }
    }
    cout<<dp[0][n];
}