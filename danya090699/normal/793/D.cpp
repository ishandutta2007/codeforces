#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m, inf=1e9;
    cin>>n>>k>>m;
    vector <int*> sv[n+2];
    for(int a=0; a<m; a++)
    {
        int u, v, pri;
        cin>>u>>v>>pri;
        sv[u].push_back(new int[2]);
        sv[u].back()[0]=v, sv[u].back()[1]=pri;
    }
    n+=2;
    int dp[n][n][n], dp2[n][n][n];
    for(int a=0; a<n; a++)
    {
        for(int b=a-1; b>=0; b--)
        {
            for(int c=a+1; c<n; c++)
            {
                dp[a][b][c]=0, dp2[a][b][c]=inf;
            }
        }
    }
    for(int i=1; i<k; i++)
    {
        for(int a=0; a<n; a++)
        {
            for(int b=a-1; b>=0; b--)
            {
                for(int c=a+1; c<n; c++)
                {
                    if(dp[a][b][c]!=inf)
                    {
                        for(int d=0; d<sv[a].size(); d++)
                        {
                            int ne=sv[a][d][0], pri=sv[a][d][1];
                            if(ne<a and ne>b) dp2[ne][b][a]=min(dp2[ne][b][a], dp[a][b][c]+pri);
                            if(ne>a and ne<c) dp2[ne][a][c]=min(dp2[ne][a][c], dp[a][b][c]+pri);
                        }
                    }
                }
            }
        }
        for(int a=0; a<n; a++)
        {
            for(int b=a-1; b>=0; b--)
            {
                for(int c=a+1; c<n; c++)
                {
                    dp[a][b][c]=dp2[a][b][c], dp2[a][b][c]=inf;
                }
            }
        }
        //if(i==0) cout<<dp[6][1][8];
    }
    int an=inf;
    for(int a=0; a<n; a++)
        {
            for(int b=a-1; b>=0; b--)
            {
                for(int c=a+1; c<n; c++)
                {
                    an=min(an, dp[a][b][c]);
                }
            }
        }
    if(an==inf) cout<<-1;
    else cout<<an;
}