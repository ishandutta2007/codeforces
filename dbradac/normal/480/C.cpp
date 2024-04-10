#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 5005, MOD = (int) 1e9 + 7;

int dp[MAX][MAX], pref[MAX];

int main()
{
    int n, k, poc, kraj, i, j, raz;

    scanf("%d%d%d%d", &n, &poc, &kraj, &k);

    for (i=1; i<=n; i++)
        dp[0][i] = 1;

    for (i=1; i<=k; i++) {
        for (j=1; j<=n; j++) {
            pref[j] = pref[j-1] + dp[i-1][j];
            if (pref[j] >= MOD)
                pref[j] -= MOD;
        }
        for (j=1; j<=n; j++) {
            raz = abs(j - kraj) - 1;
            if (!raz)
                dp[i][j] = 0;
            else {
                dp[i][j] = pref[min(n, j+raz)] - pref[max(0, j-raz-1)];
                if (dp[i][j] < 0)
                    dp[i][j] += MOD;
                else if (dp[i][j] >= MOD)
                    dp[i][j] -= MOD;
                dp[i][j] -= dp[i-1][j];
                if (dp[i][j] < 0)
                    dp[i][j] += MOD;
                else if (dp[i][j] >= MOD)
                    dp[i][j] -= MOD;
            }
        }
    }

    printf("%d\n", dp[k][poc]);

    return 0;
}