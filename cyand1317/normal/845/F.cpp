#include <cstdio>
#include <cstring>
#include <algorithm>
static const int MAXN = 16;
static const int MAXM = 252;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

int n, m;
char g[MAXM][MAXM];

// f[row][bitmask of (is row guarded)][is col guarded][exists cell unguarded]
int f[MAXN][1 << MAXN][2][2] = {{{{ 0 }}}};
int h[MAXN][1 << MAXN][2][2] = {{{{ 0 }}}};

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", g[i]);
    if (n > m) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i && j < m; ++j)
                std::swap(g[i][j], g[j][i]);
        std::swap(n, m);
    }

    h[n - 1][0][0][0] = 1;
    for (int j = 0; j < m; ++j) {
        if (g[0][j] == '.') {
            for (int k = 0; k < (1 << n); ++k)
                for (int p = 0; p < 2; ++p) {
                    // Don't place
                    if (k & 1) {
                        (f[0][k][0][0] += h[n - 1][k][p][0])__;
                        (f[0][k][0][1] += h[n - 1][k][p][1])__;
                    } else {
                        (f[0][k][0][1] += h[n - 1][k][p][0])__;
                    }
                    // Place
                    (f[0][k | 1][1][0] += h[n - 1][k][p][0])__;
                    (f[0][k | 1][1][1] += h[n - 1][k][p][1])__;
                }
        } else {
            for (int k = 0; k < (1 << n); ++k)
                for (int p = 0; p < 2; ++p) {
                    // Only choice
                    (f[0][k ^ (k & 1)][0][0] += h[n - 1][k][p][0])__;
                    (f[0][k ^ (k & 1)][0][1] += h[n - 1][k][p][1])__;
                }
        }
        for (int i = 1; i < n; ++i) {
            if (g[i][j] == '.') {
                for (int k = 0; k < (1 << n); ++k)
                    for (int p = 0; p < 2; ++p) {
                        // Don't place
                        if ((k & (1 << i)) || p) {
                            (f[i][k][p][0] += f[i - 1][k][p][0])__;
                            (f[i][k][p][1] += f[i - 1][k][p][1])__;
                        } else {
                            (f[i][k][p][1] += f[i - 1][k][p][0])__;
                        }
                        // Place
                        (f[i][k | (1 << i)][1][0] += f[i - 1][k][p][0])__;
                        (f[i][k | (1 << i)][1][1] += f[i - 1][k][p][1])__;
                    }
            } else {
                for (int k = 0; k < (1 << n); ++k)
                    for (int p = 0; p < 2; ++p) {
                        // Only choice
                        (f[i][k ^ (k & (1 << i))][0][0] += f[i - 1][k][p][0])__;
                        (f[i][k ^ (k & (1 << i))][0][1] += f[i - 1][k][p][1])__;
                    }
            }
        }
        memcpy(h, f, sizeof f);
        memset(f, 0, sizeof f);
    }

    int ans = 0;
    for (int k = 0; k < (1 << n); ++k)
        for (int p = 0; p < 2; ++p)
            for (int q = 0; q < 2; ++q)
                (ans += h[n - 1][k][p][q])__;
    printf("%d\n", ans);

    return 0;
}