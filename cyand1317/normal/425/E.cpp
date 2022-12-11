#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXN = 504;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS

int n, k;
// f[# of selected segments][R of last selected segment][R of last segment in set]
int f[2][MAXN][MAXN] = {{{ 0 }}}, cur = 0;
int pow2[MAXN];

int main()
{
    pow2[0] = 1;
    for (int i = 1; i < MAXN; ++i) pow2[i] = (pow2[i - 1] + pow2[i - 1])_;

    scanf("%d%d", &n, &k);
    if (k == 0) { puts("1"); return 0; }

    for (int p = 1; p <= n; ++p) f[cur][p][p] = pow2[p] - 1;
    for (int i = 1; i <= k; ++i) {
        memset(f[cur ^ 1], 0, sizeof f[cur ^ 1]);
        for (int p = 1; p <= n; ++p) {
            int sum = 0;
            for (int q = p; q <= n; ++q) {
                sum = (sum + f[cur][p][q])_;
                f[cur ^ 1][q + 1][q + 1] = ((int64)(pow2[q + 1] - pow2[p] + MODULUS)_ * sum + f[cur ^ 1][q + 1][q + 1])_;
                f[cur][p][q + 1] = ((int64)(pow2[p] - 1) * sum + f[cur][p][q + 1])_;
            }
        }
        cur ^= 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j) ans = (ans + f[cur ^ 1][i][j])_;
    printf("%d\n", ans);
    return 0;
}