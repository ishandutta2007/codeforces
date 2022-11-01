#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int inf=100000000;
    const int N=30;
    const int K=50;
    int dp[N+1][N+1][K+1];
    for(int o=0;o<=N;o++) for(int i=0;i<=N;i++) for(int j=0;j<=K;j++) dp[o][i][j]=inf*(j!=0);
    for(int o=1;o<=N;o++) for(int i=1;i<=N&&o*i<=K;i++) dp[o][i][o*i]=0;
    for(int o=1;o<=N;o++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=K;j++)
            {
                //horizontal
                for(int r=1;r<o;r++)
                {
                    for(int t=0;t<=j;t++)
                    {
                        dp[o][i][j]=min(dp[o][i][j],i*i+dp[r][i][t]+dp[o-r][i][j-t]);
                    }
                }
                //vertical
                for(int c=1;c<i;c++)
                {
                    for(int t=0;t<=j;t++)
                    {
                        dp[o][i][j]=min(dp[o][i][j],o*o+dp[o][c][t]+dp[o][i-c][j-t]);
                    }
                }
            }
        }
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",dp[n][m][k]);
    }
    return 0;
}