#include <stdio.h>
#define INF 0x1fffffff

int worked[32][32][64] = {{ 0 }};

int work(int n, int m, int k)
{
    if (n * m < k || k < 0 || k > 50) return INF;
    else if (n * m == k || k == 0) return 0;
    else if (worked[n][m][k]) return worked[n][m][k];
    int i, j, ans = INF, cur;
    for (i = 1; i < n; ++i)
        for (j = 0; j <= (n - i) * m; ++j)
            if ((cur = work(i, m, k - j) + work(n - i, m, j) + m * m) < ans) ans = cur;
    for (i = 1; i < m; ++i)
        for (j = 0; j <= (m - i) * n; ++j)
            if ((cur = work(n, i, k - j) + work(n, m - i, j) + n * n) < ans) ans = cur;
    return (worked[n][m][k] = ans);
}

int main()
{
    int n, m, t, k;
    scanf("%d", &t);
    do {
        scanf("%d%d%d", &n, &m, &k);
        printf("%d\n", work(n, m, k));
    } while (--t);
    return 0;
}