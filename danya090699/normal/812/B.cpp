#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, ma=1000, inf=1e9;
    cin>>n>>m;
    char ar[n][m+2];
    int l[n], r[n];
    for(int a=0; a<n; a++)
    {
        l[a]=m+1, r[a]=0;
        for(int b=0; b<m+2; b++)
        {
            cin>>ar[a][b];
            if(ar[a][b]=='1')
            {
                //cout<<ar[a][b]<<" ";
                if(l[a]==m+1) l[a]=b;
                r[a]=b;
                //cout<<a<<" "<<b<<"\n";
            }
        }
        if(l[a]!=m+1) ma=min(ma, a);
    }
    int dp[n][2];
    for(int a=0; a<n; a++)
    {
        dp[a][0]=inf, dp[a][1]=inf;
    }
    dp[n-1][0]=0;
    //cout<<ma;
    for(int a=n-1; a>ma; a--)
    {
        //cout<<dp[a][0]<<" "<<dp[a][1]<<"\n";
        if(dp[a][0]!=inf)
        {
            dp[a-1][0]=min(dp[a-1][0], dp[a][0]+r[a]*2+1);
            dp[a-1][1]=min(dp[a-1][1], dp[a][0]+m+2);
        }
        if(dp[a][1]!=inf)
        {
            dp[a-1][1]=min(dp[a-1][1], dp[a][1]+(m+1-l[a])*2+1);
            dp[a-1][0]=min(dp[a-1][0], dp[a][1]+m+2);
        }
    }
    //cout<<r[1];
    cout<<min(dp[ma][0]+r[ma], dp[ma][1]+(m+1-l[ma]));
}