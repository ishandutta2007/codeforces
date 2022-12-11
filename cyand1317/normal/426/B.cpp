#include <cstdio>
static const int MAXN = 104;

int n, m, a[MAXN][MAXN];
bool row_eq[MAXN][MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) {
            bool is_equal = true;
            for (int k = 0; k < m; ++k) if (a[i][k] != a[j][k]) { is_equal = false; break; }
            row_eq[i][j] = row_eq[j][i] = is_equal;
        }

    int ans;
    for (ans = n; ans % 2 == 0; ans >>= 1) {
        bool valid = true;
        for (int i = 0; i <= ans / 2; ++i) if (!row_eq[i][ans - i - 1]) { valid = false; break; }
        if (!valid) break;
    }

    printf("%d\n", ans);
    return 0;
}