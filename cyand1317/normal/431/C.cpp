#include <cstdio>
static const int MAXN = 105;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int n, k, d;
// f[depth (edges passed)][sum][max]
int f[MAXN][MAXN * 2][MAXN] = {{{ 0 }}};

int main()
{
    scanf("%d%d%d", &n, &k, &d);

    f[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            for (int p = 0; p <= k; ++p) {
                for (int q = 1; q <= k; ++q)
                    (f[i + 1][j + q][max(p, q)] += f[i][j][p]) %= MODULUS;
            }
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i)
        for (int j = d; j <= k; ++j) (ans += f[i][n][j]) %= MODULUS;
    printf("%d\n", ans);
    return 0;
}