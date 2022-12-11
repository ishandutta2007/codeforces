#include <cstdio>
#include <algorithm>
static const int N = 5;

int g[N][N];
int p[N], cur, ans;

int main()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) scanf("%d", &g[i][j]);

    ans = 0;
    for (int i = 0; i < N; ++i) p[i] = i;
    do {
        cur = 0;
        cur += (g[p[0]][p[1]] + g[p[1]][p[0]]) * 1;
        cur += (g[p[1]][p[2]] + g[p[2]][p[1]]) * 1;
        cur += (g[p[2]][p[3]] + g[p[3]][p[2]]) * 2;
        cur += (g[p[3]][p[4]] + g[p[4]][p[3]]) * 2;
        ans = std::max(ans, cur);
    } while (std::next_permutation(p, p + N));

    printf("%d\n", ans);
    return 0;
}