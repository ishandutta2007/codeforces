#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    int be[n][m+1];
    for(int a=0; a<n; a++) for(int b=0; b<=m; b++) be[a][b]=inf;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        int lq=0;
        for(int b=0; b<=m; b++)
        {
            int rq=0;
            for(int c=m; c>=b; c--)
            {
                be[a][lq+rq]=min(be[a][lq+rq], c-b);
                if(c>0)
                {
                    if(s[c-1]=='1') rq++;
                }
            }
            if(b<m)
            {
                if(s[b]=='1') lq++;
            }
        }
    }
    int dp[n+1][k+1];
    for(int a=0; a<=n; a++) for(int b=0; b<=k; b++) dp[a][b]=inf;
    dp[0][0]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<=k; b++)
        {
            for(int c=0; c<=m; c++)
            {
                if(b+c<=k) dp[a+1][b+c]=min(dp[a+1][b+c], dp[a][b]+be[a][c]);
            }
        }
    }
    int an=inf;
    for(int a=0; a<=k; a++) an=min(an, dp[n][a]);
    cout<<an;
}