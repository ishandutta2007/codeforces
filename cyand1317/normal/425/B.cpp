#include <cstdio>
static const int INF = 0x7fffffff;
static const int MAXN = 102;
static const int MAXK = 12;

int n, m, k;
bool a[MAXN][MAXN], _a[MAXN][MAXN];

inline int check_cols(bool r[])
{
    int ans = 0, cur[2];
    for (int i = 0; i < n; ++i) {
        cur[0] = cur[1] = 0;
        for (int j = 0; j < m; ++j) ++cur[a[i][j] ^ r[j] ^ 1];
        ans += (cur[0] < cur[1] ? cur[0] : cur[1]);
    }
    return ans;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) a[i][j] = (getchar(), getchar() == '1');

    int ans = INF, cur;
    if (k >= n) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) _a[j][i] = a[i][j];
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) a[i][j] = _a[i][j];
        int t = m; m = n; n = t;
        for (int mask = 0; mask < (1 << m); ++mask) {
            static bool rw[MAXN];
            for (int i = 0; i < m; ++i) rw[i] = (mask >> i) & 1;
            if ((cur = check_cols(rw)) < ans) ans = cur;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if ((cur = check_cols(a[i])) < ans) ans = cur;
        }
    }

    printf("%d\n", ans > k ? -1 : ans);
    return 0;
}