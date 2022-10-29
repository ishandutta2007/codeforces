#include<stdio.h>
typedef long long ll;
ll dp[800][8];
int main()
{
    int n;
    scanf("%d",&n);
    dp[0][0]=1;
    for(int i=1;i<800;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<8;j++)dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    }
    printf("%I64d\n",dp[n][5]+dp[n][6]+dp[n][7]);
}