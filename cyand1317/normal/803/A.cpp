#include <cstdio>
#include <algorithm>
static const int MAXN = 104;

int n, k;
int a[MAXN][MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    if (k > n * n) { puts("-1"); return 0; }

    for (int r = 0; r < n && k > 0; ++r) {
        int c = std::min(k, (n - r) * 2 - 1);
        for (int i = 0; i < (c - 1) / 2 + 1; ++i)
            a[r + i][r] = a[r][r + i] = 1;
        if (c % 2 == 0) {
            if (r + 1 >= n) { puts("-1"); return 0; }
            else a[r + 1][r + 1] = true;
        }
        k -= c;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) printf("%d%c", a[i][j], j == n - 1 ? '\n' : ' ');

    return 0;
}