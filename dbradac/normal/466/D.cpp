#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 1<<11, MOD = 1000000007;

int p[MAX], dp[MAX][MAX];

int main()
{
    int i, j, n, h;

    scanf("%d%d", &n, &h);

    for (i=1; i<=n; i++)
        scanf("%d", &p[i]);

    dp[0][0] = 1;

    for (i=1; i<=n; i++) {
        for (j=0; j<=n; j++) {
            if (p[i] + j == h) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                if (j)
                    dp[i][j-1] = (dp[i][j-1] + (ll) dp[i-1][j] * j) % MOD;
            }
            if (p[i] + j + 1 == h) {
                dp[i][j+1] = (dp[i][j+1] + dp[i-1][j]) % MOD;
                dp[i][j] = (dp[i][j] + (ll) (j+1) * dp[i-1][j]) % MOD;
            }
        }
    }

    /*for (i=1; i<=n; i++)
        for (j=0; j<=n; j++)
            printf("%d %d    %d\n", i, j, dp[i][j]);*/

    printf("%d\n", dp[n][0]);

    return 0;
}