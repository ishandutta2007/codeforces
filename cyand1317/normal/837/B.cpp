#include <cstdio>
#include <cstring>
#include <algorithm>
static const int MAXN = 102;

int n, m;
char g[MAXN][MAXN];
char h[MAXN][MAXN];

inline bool check_hor()
{
    if (n % 3 != 0) return false;
    char c[4] = { 0 };
    c[0] = g[0][0];
    c[1] = g[n / 3][0];
    c[2] = g[n / 3 * 2][0];
    std::sort(c, c + 3);
    if (strcmp(c, "BGR") != 0) return false;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n / 3; ++j)
            for (int k = 0; k < m; ++k)
                if (g[n / 3 * i + j][k] != g[n / 3 * i][0]) return false;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", g[i]);

    if (check_hor()) { puts("YES"); return 0; }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) h[j][i] = g[i][j];
    std::swap(n, m);
    memcpy(g, h, sizeof g);
    if (check_hor()) { puts("YES"); return 0; }

    puts("NO"); return 0;
}