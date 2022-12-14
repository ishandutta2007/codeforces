#include <algorithm>
#include <cstdio>
#include <cstring>

int n, m;
long long dp[1 << 17][32];
int pne[1 << 17][5];
int pbo[1 << 17][5];
int lg[64];
int ok[64];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i + 1 < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &pne[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &pbo[i][j]);
        }
    }
    memset(ok, 0, sizeof(ok));
    for (int i = 0; i < n; ++i) {
        lg[1 << i] = i;
        ok[1 << i] = 1;
    }

    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i + 1 < m; ++i) {
        long long tr[32];
        tr[0] = 0;
        for (int k = 1; k < (1 << n); ++k) {
            int p = (k & (k - 1));
            tr[k] = tr[p] + pne[i][lg[k - p]];
        }

        for (int ma = 0; ma < (1 << n); ++ma) {
            for (int k = 0; k < n; ++k) {
                int f = ((1 << k) | (1 << ((k + 1) % n)));
                if (ok[ma & f]) {
                    dp[i][ma] += pbo[i][k];
                }
            }

            for (int ne = 0; ne < (1 << n); ++ne) {
                dp[i + 1][ne] = std::min(dp[i + 1][ne], tr[ne - (ne & ma)] + dp[i][ma]);
            }
        }
    }
    printf("%lld\n", dp[m - 1][(1 << n) - 1]);

    return 0;
}