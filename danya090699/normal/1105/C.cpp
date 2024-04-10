#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, l, r;
    cin>>n>>l>>r;
    int dp[n+1][3];
    for(int a=0; a<=n; a++) for(int b=0; b<3; b++) dp[a][b]=0;
    dp[0][0]=1;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<3; b++)
        {
            for(int c=0; c<3; c++)
            {
                int ll=l, rr=r+1;
                while(ll%3!=c) ll++;
                while(rr%3!=c) rr++;
                int q=(rr-ll)/3;
                dp[a+1][(b+c)%3]=(dp[a+1][(b+c)%3]+dp[a][b]*q)%mod;
            }
        }
    }
    cout<<dp[n][0];
}