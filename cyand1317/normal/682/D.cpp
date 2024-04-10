#include <cstdio>
static const int MAXN = 1024;
static const int MAXK = 12;

int n, m, max_k;
char s[MAXN], t[MAXN];
short f[4][MAXK][MAXN][MAXN] = {{{{ 0 }}}};

template <typename T>
inline void upd_max(T &var, const T val) { if (var < val) var = val; }

int main()
{
    scanf("%d%d%d", &n, &m, &max_k); getchar();
    for (int i = 0; i <= n; ++i) s[i] = getchar();
    for (int i = 0; i <= m; ++i) t[i] = getchar();
    for (int k = 0; k <= max_k; ++k) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (i) {
                    upd_max(f[0][k][i][j], f[0][k][i - 1][j]);
                    upd_max(f[0][k][i][j], f[1][k][i - 1][j]);
                }
                if (j) {
                    upd_max(f[0][k][i][j], f[0][k][i][j - 1]);
                    upd_max(f[0][k][i][j], f[2][k][i][j - 1]);
                }
                if (j) {
                    upd_max(f[1][k][i][j], f[1][k][i][j - 1]);
                    upd_max(f[1][k][i][j], f[3][k][i][j - 1]);
                }
                if (i) {
                    upd_max(f[2][k][i][j], f[2][k][i - 1][j]);
                    upd_max(f[2][k][i][j], f[3][k][i - 1][j]);
                }
                if (k && s[i] == t[j]) {
                    if (i && j) {
                        for (int x = 0; x < 4; ++x)
                            upd_max(f[3][k][i][j], (short)(f[x][k - 1][i - 1][j - 1] + 1));
                        upd_max(f[3][k][i][j], (short)(f[3][k][i - 1][j - 1] + 1));
                    }
                    upd_max(f[3][k][i][j], (short)1);
                }
            }
    }
    short ans = 0;
    for (int p = 0; p < 4; ++p)
        for (int k = 0; k <= max_k; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    upd_max(ans, f[p][k][i][j]);
    printf("%d\n", ans);
    return 0;
}