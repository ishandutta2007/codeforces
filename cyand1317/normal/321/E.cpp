#include <cstdio>
static const int INF32 = 0x1fffffff;
static const int MAXN = 4003;
static const int MAXK = 803;

template <typename T> inline bool tension(T &var, const T val) {
    if (var > val) { var = val; return true; } else return false;
}

int n, k;
short u[MAXN][MAXN];
int s[MAXN][MAXN] = {{ 0 }};
int f[2][MAXN], cur = 0;

void update_dp(int l, int r, int sel_l, int sel_r)
{
    if (l > r) return;
#define last (cur ^ 1)
    int m = (l + r) >> 1, sel_m = -1;
    f[cur][m] = INF32;
    for (int i = sel_l; i <= sel_r && i <= m; ++i)
        if (tension(f[cur][m], f[last][i] + s[i][i] - 2 * s[i][m] + s[m][m])) sel_m = i;
    if (l != r) {
        update_dp(l, m - 1, sel_l, sel_m);
        update_dp(m + 1, r, sel_m, sel_r);
    }
#undef last
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            u[i][j] = (getchar(), getchar()) - '0';
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + u[i][j];
        }

    f[cur][0] = 0;
    for (int i = 1; i <= n; ++i) f[cur][i] = INF32;
    for (int i = 0; i < k; ++i) {
        cur ^= 1;
        update_dp(1, n, 0, n);
    }

    printf("%d\n", f[cur][n] / 2);

    return 0;
}