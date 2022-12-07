#include <bits/stdc++.h>
using namespace std;
const int inf=1e9, sz=5e3+10;
int dp[sz][sz][2];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<=n; a++)
    {
        for(int b=0; b<=n; b++)
        {
            dp[a][b][0]=inf, dp[a][b][1]=inf;
        }
    }
    dp[0][0][0]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<=n; b++)
        {
            for(int c=0; c<2; c++)
            {
                if(dp[a][b][c]!=inf)
                {
                    //cout<<a<<" "<<b<<" "<<c<<"   "<<dp[a][b][c]<<"\n";
                    dp[a+1][b][0]=min(dp[a+1][b][0], dp[a][b][c]);
                    int ph=0, nh=0, na=a+1;
                    if(a>0)
                    {
                        ph=ar[a-1];
                        if(c) ph=min(ph, ar[a-2]-1);
                    }
                    if(a+1<n)
                    {
                        nh=ar[a+1], na++;
                    }
                    int add=max(0, ph-(ar[a]-1))+max(0, nh-(ar[a]-1));
                    dp[na][b+1][1]=min(dp[na][b+1][1], dp[a][b][c]+add);
                }
            }
        }
    }
    for(int a=1; a<=n; a++)
    {
        int an=min(dp[n][a][0], dp[n][a][1]);
        if(an!=inf) cout<<an<<" ";
    }
}