// Automatic logout?? First time seen.
#include <cstdio>
static const int MAXN = 1004;

int n, m, k;
bool g[MAXN][MAXN] = {{ false }};

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        int row, col;
        scanf("%d%d", &row, &col);
        g[row][col] = true;
        if (g[row - 1][col] &&
            ((g[row - 1][col - 1] && g[row][col - 1]) ||
            (g[row - 1][col + 1] && g[row][col + 1])) ||
            g[row + 1][col] &&
            ((g[row + 1][col - 1] && g[row][col - 1]) ||
            (g[row + 1][col + 1] && g[row][col + 1])))
        {
            printf("%d\n", i + 1); return 0;
        }
    }

    puts("0");
    return 0;
}