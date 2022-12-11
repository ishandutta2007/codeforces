#include <cstdio>
typedef long long int64;
static const int MAXN = 104;

int n, m; int64 k; int x, y;
int64 count[MAXN][MAXN] = {{ 0 }};

int main()
{
    scanf("%d%d%I64d%d%d", &n, &m, &k, &x, &y); --x, --y;

    if (n == 1) {
        printf("%I64d %I64d %I64d\n", k / m + (k % m != 0), k / m, (k - 1) / m + ((k - 1 + m) % m >= y));
        return 0;
    }

    int64 cycles = k / (m * (n + n - 2));
    int64 remains = k % (m * (n + n - 2));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            count[i][j] += cycles * (i == 0 || i == n - 1 ? 1 : 2);

    for (int i = 0; i < n && remains > 0; ++i)
        for (int j = 0; j < m && remains > 0; ++j) ++count[i][j], --remains;
    for (int i = n - 2; i >= 0 && remains > 0; --i)
        for (int j = 0; j < m && remains > 0; ++j) ++count[i][j], --remains;

    int64 max = -1, min = 1LL << 61;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (max < count[i][j]) max = count[i][j];
            if (min > count[i][j]) min = count[i][j];
        }

    printf("%I64d %I64d %I64d\n", max, min, count[x][y]);
    return 0;
}