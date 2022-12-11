#include <stdio.h>
#define MAXN 102
#define min(__a, __b) ((__a) < (__b) ? (__a) : (__b))

char f[MAXN][MAXN];
int a[MAXN][MAXN] = {{0}};
int ans = 0;

int i, j;
void add(int n, int m, int delta)
{
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j) a[i][j] += delta;
}

void solve(int n, int m)
{
    if (!m || !n) return;
    int i, j, t = min(n, m);
    for (i = 0; i < t; ++i)
        for (j = 0; j <= i; ++j) {
            if (a[n - j - 1][m - i - 1] != f[n - j - 1][m - i - 1]) {
                ++ans;
                add(n - j, m - i, f[n - j - 1][m - i - 1] - a[n - j - 1][m - i - 1]);
            }
            if (a[n - i - 1][m - j - 1] != f[n - i - 1][m - j - 1]) {
                ++ans;
                add(n - i, m - j, f[n - i - 1][m - j - 1] - a[n - i - 1][m - j - 1]);
            }
        }
    if (t == n) solve(n, m - n);
    else solve(n - m, m);
}

int main()
{
    int n, m, i, j;
    scanf("%d%d\n", &n, &m);
    for (i = 0; i < n; ++i)
        for (j = 0; j <= m; ++j) f[i][j] = getchar() == 'W' ? 1 : -1;
    solve(n, m);
    printf("%d\n", ans);
    return 0;
}