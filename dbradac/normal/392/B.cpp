#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll dp[41][4][4];
int p[4][4];

int main()
{
    int i, j, k, n;

    for (i=1; i<=3; i++)
        for (j=1; j<=3; j++)
            scanf("%d", &p[i][j]);

    scanf("%d", &n);

    for (i=1; i<=n; i++) {
        for (j=1; j<=3; j++)
            for (k=1; k<=3; k++)
                if (j != k)
                    dp[i][j][k] = min(dp[i-1][j][j^k] + p[j][k] + dp[i-1][j^k][k],
                    dp[i-1][j][k] + p[j][j^k] + dp[i-1][k][j] + p[j^k][k] + dp[i-1][j][k]);
        for (j=1; j<=3; j++)
            for (k=1; k<=3; k++)
                if (j != k)
                    dp[i][j][k] = min(dp[i][j][k], dp[i][j][j^k] + dp[i][j^k][k]);
    }

    printf("%I64d\n", dp[n][1][3]);

    return 0;
}