//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int mo(int x)
{
    if(x<0) return -x;
    else return x;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, p, inf=2e9+100;
    cin>>n>>k>>p;
    int pe[n], ke[k];
    for(int a=0; a<n; a++) cin>>pe[a];
    for(int a=0; a<k; a++) cin>>ke[a];
    int dp[k+1][n+1];
    sort(pe, pe+n), sort(ke, ke+k);
    for(int a=0; a<=k; a++) for(int b=0; b<=n; b++) dp[a][b]=inf;
    dp[0][0]=0;
    for(int a=0; a<k; a++)
    {
        for(int b=0; b<=n; b++)
        {
            if(dp[a][b]!=inf)
            {
                dp[a+1][b]=min(dp[a+1][b], dp[a][b]);
                if(b<n)
                {
                    int ti=mo(pe[b]-ke[a])+mo(ke[a]-p);
                    dp[a+1][b+1]=min(dp[a+1][b+1], max(dp[a][b], ti));
                }
            }
        }
    }
    cout<<dp[k][n];
}