#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 502;
static const int MAXQ = 302;
static const int MODULUS = 1e9 + 7;

static const int inv[5] = { 0, 1, 3, 2, 4 };

int n, m, q;
int f[MAXN][MAXN + MAXQ];
char s[MAXN];

inline int gaussian_elimination()
{
    int rk = 0;
    for (int i = 0, p = 0; i < m && p < n; ++i, ++p) {
        if (f[i][p] == 0) {
            int k = -1;
            for (int j = p + 1; j < m; ++j)
                if (f[j][p] != 0) { k = j; break; }
            if (k == -1) {
                --i;
                continue;
            } else {
                for (int j = p; j < n + q; ++j)
                    std::swap(f[i][j], f[k][j]);
            }
        }
        for (int j = i + 1; j < m; ++j) {
            int mul = f[j][p] * inv[f[i][p]];
            for (int k = p; k < n + q; ++k)
                f[j][k] = (f[j][k] - mul * f[i][k] + 52525) % 5;
        }
        rk = i + 1;
    }
    for (int i = m; i >= 0; --i) if (i < n && f[i][i] != 0) {
        for (int j = i + 1; j < n + q; ++j)
            f[i][j] = f[i][j] * inv[f[i][i]] % 5;
        f[i][i] = 1;
        for (int k = i - 1; k >= 0; --k) {
            for (int j = i + 1; j < n + q; ++j)
                f[k][j] = (f[k][j] - f[i][j] * f[k][i] + 52525) % 5;
            f[k][i] = 0;
        }
    }
    return rk;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        for (int j = 0; j < m; ++j) f[j][i] = s[j] - 'a';
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%s", s);
        for (int j = 0; j < m; ++j) f[j][i + n] = s[j] - 'a';
    }

    int rk = gaussian_elimination();
    int ans = 1;
    for (int i = 0; i < n - rk; ++i) ans = (int64)ans * 5 % MODULUS;
    for (int i = 0; i < q; ++i) {
        bool valid = true;
        for (int j = rk; j < m; ++j)
            if (f[j][i + n] != 0) { valid = false; break; }
        printf("%d\n", valid ? ans : 0);
    }

    return 0;
}