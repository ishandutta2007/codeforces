#include <cstdio>
static const int INF = 0x7fffffff;
static const int MAXN = 200006;

int n;
char d[MAXN];
int p[MAXN];

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) d[i] = getchar();
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);

    int ans = INF;
    for (int i = 0; i < n - 1; ++i)
        if (d[i] == 'R' && d[i + 1] == 'L' && ans > p[i + 1] - p[i])
            ans = p[i + 1] - p[i];
    ans /= 2;
    printf("%d\n", ans == INF / 2 ? -1 : ans);
    return 0;
}