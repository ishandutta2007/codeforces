#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, pr=0;
        scanf("%lld", &n);
        int dp[n+1][3];
        dp[0][0]=0, dp[0][1]=0, dp[0][2]=0;
        for(int a=0; a<n; a++)
        {
            int h, w;
            scanf("%lld%lld", &h, &w);
            dp[a+1][0]=inf, dp[a+1][1]=inf, dp[a+1][2]=inf;
            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    if(pr+i!=h+j) dp[a+1][j]=min(dp[a+1][j], dp[a][i]+j*w);
                }
            }
            pr=h;
        }
        printf("%lld\n", min(dp[n][2], min(dp[n][0], dp[n][1])));
    }
}