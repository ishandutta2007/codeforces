#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int dp[n*2+1][n+1];
        for(int a=0; a<=n*2; a++) for(int b=0; b<=n; b++) dp[a][b]=inf;
        dp[0][0]=0;
        for(int a=0; a<2*n; a++)
        {
            int x;
            cin>>x;
            for(int b=0; b<=n; b++)
            {
                if(dp[a][b]!=inf)
                {
                    if(b+1<=n)
                    {
                        dp[a+1][b+1]=min(dp[a+1][b+1], max(dp[a][b], x));
                    }
                    if(a-b+1<=n and x>dp[a][b])
                    {
                        dp[a+1][a-b+1]=min(dp[a+1][a-b+1], x);
                    }
                }
            }
        }
        if(dp[n*2][n]!=inf) cout<<"YES\n";
        else cout<<"NO\n";
    }
}