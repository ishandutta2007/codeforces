#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

using namespace std;

int a[200], b[200], dp[(int)2e5 + 1020][200]; 

int main()
{
    int q = (int)1e5;
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int c;
        scanf("%d", &c);
        b[i] = a[i] - k * c;
    }
    for (int i = -q; i <= q + 10; i++)
        for (int j = 0; j <= n; j++)
            dp[i + q][j] = (int)-3e6;
    dp[q][0] = 0;
    for (int j = 1; j <= n; j++)
        for (int i = -q; i <= q + 10; i++)
        {
            if (i - b[j] + q >= 0)
                dp[i + q][j] = dp[i + q - b[j]][j - 1] + a[j];
            dp[i + q][j] = max(dp[i + q][j], dp[i + q][j - 1]);
        }
    if (dp[q][n] == 0)
        printf("-1");
    else
        printf("%d", dp[q][n]);

    return 0;
}