#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

using namespace std;

int t[200], w[200], dp[20000][200];

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &t[i], &w[i]);
        sum += w[i];
    }
    for(int i = 0; i <= sum; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = -300000;
    dp[0][0] = 0;
    for(int j = 1; j <= n; j++)
    {
        for(int i = 0; i <= sum; i++)
        {
            //dp[i][j]      ,  ,      i 
            //   j 
            if(i >= t[j])
                dp[i][j] = dp[i - t[j]][j - 1] + w[j];
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }
    for(int i = 0; i <= sum; i++)
        if(i >= sum - dp[i][n])
        {
            printf("%d", i);

            return 0;
        }
    return 0;
}