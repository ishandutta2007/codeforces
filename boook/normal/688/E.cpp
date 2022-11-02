#include<bits/stdc++.h>
using namespace std;
#define MAX 510
int dp[2][MAX][MAX],x[MAX];
int main()
{
    int n,t;
    while(scanf("%d%d",&n,&t)==2)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&x[i]);
        int pr=0,nx=1;
        memset(dp,0,sizeof dp);
        dp[0][0][0]=dp[0][x[0]][0]=1,dp[0][x[0]][x[0]]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=t;j++)
            {
                for(int k=0;k<=t;k++)
                {
                    int xx=dp[pr][j][k];
                    if(j>=x[i])
                    {
                        if(k>=x[i])xx=(dp[pr][j][k]|dp[pr][j-x[i]][k]|dp[pr][j-x[i]][k-x[i]]);
                        else xx=(dp[pr][j][k]|dp[pr][j-x[i]][k]);
                    }
                    dp[nx][j][k]=xx;
                }
            }
            swap(pr,nx);
        }
        vector<int> v;
        for(int k=0;k<=t;k++)
            if(dp[pr][t][k])v.push_back(k);
        printf("%d\n",v.size());
        if(v.size())printf("%d",v[0]);
        for(int i=1;i<v.size();i++)
        printf(" %d",v[i]);puts("");
    }
    return 0;
}