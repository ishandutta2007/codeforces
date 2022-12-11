#include <cstdio>
#include <algorithm>
static const int MAXN = 102;

int n, a, b;
int x[MAXN], y[MAXN];

inline int calc(int r1, int c1, int r2, int c2)
{
    if (r1 > a || r2 > a || c1 > b || c2 > b) return 0;
    if (r1 + r2 > a && c1 + c2 > b) return 0;
    return r1 * c1 + r2 * c2;
}

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);

    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j) {
            ans = std::max(ans, calc(x[i], y[i], x[j], y[j]));
            ans = std::max(ans, calc(x[i], y[i], y[j], x[j]));
            ans = std::max(ans, calc(y[i], x[i], x[j], y[j]));
            ans = std::max(ans, calc(y[i], x[i], y[j], x[j]));
        }

    printf("%d\n", ans);
    return 0;
}