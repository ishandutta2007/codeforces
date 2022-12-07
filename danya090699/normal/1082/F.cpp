#include <bits/stdc++.h>
using namespace std;
const int sz=5e2+10, inf=1e9;
int n, k;
int go[sz][10], q[sz], h[sz], m=1;
int dp[sz][sz][11];
void dfs(int v)
{
    for(int a=0; a<10; a++)
    {
        int ne=go[v][a];
        if(ne!=-1) h[ne]=h[v]+1, dfs(ne);
    }
    int dp2[2][h[v]+1][k+1];
    for(int a=0; a<=h[v]; a++)
    {
        for(int b=0; b<=k; b++)
        {
            dp[v][a][b]=inf;
            int x=0;
            if(b==0) dp2[0][a][b]=0;
            else dp2[0][a][b]=inf;
            dp2[1][a][b]=inf;
        }
    }
    for(int a=0; a<10; a++)
    {
        int ne=go[v][a];
        if(ne!=-1)
        {
            for(int b=0; b<=h[v]; b++)
            {
                for(int c=0; c<=k; c++)
                {
                    if(dp2[0][b][c]!=inf)
                    {
                        for(int d=0; c+d<=k; d++)
                        {
                            if(dp[ne][b][d]!=inf) dp2[1][b][c+d]=min(dp2[1][b][c+d], dp2[0][b][c]+dp[ne][b][d]);
                        }
                    }
                }
            }
            for(int b=0; b<=h[v]; b++)
            {
                for(int c=0; c<=k; c++) dp2[0][b][c]=dp2[1][b][c], dp2[1][b][c]=inf;
            }
        }
    }
    for(int a=0; a<k; a++)
    {
        for(int b=0; b<=h[v]; b++) dp[v][b][a+1]=min(dp[v][b][a+1], dp2[0][h[v]][a]);
    }
    for(int a=0; a<=h[v]; a++)
    {
        for(int b=0; b<=k; b++)
        {
            dp[v][a][b]=min(dp[v][a][b], dp2[0][a][b]+q[v]*(h[v]-a));
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    for(int a=0; a<10; a++) go[0][a]=-1;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        int cu=0;
        for(int b=0; b<s.size(); b++)
        {
            int sy=s[b]-'0';
            if(go[cu][sy]==-1)
            {
                for(int c=0; c<10; c++) go[m][c]=-1;
                go[cu][sy]=m, m++;
            }
            cu=go[cu][sy];
        }
        int va;
        cin>>va;
        q[cu]+=va;
    }
    dfs(0);
    int an=inf;
    for(int a=0; a<=k; a++) an=min(an, dp[0][0][a]);
    cout<<an;
}