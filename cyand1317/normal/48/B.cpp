#include <cstdio>
static const int MAXN = 64;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }

int n, m;
int g[MAXN][MAXN], s[MAXN][MAXN] = {{ 0 }};
int a, b;

int check(int w, int h)
{
    int ans = 0x7fffffff;
    for (int i = 1; i <= n - h + 1; ++i)
        for (int j = 1; j <= m - w + 1; ++j)
            ans = min(ans, s[i + h - 1][j + w - 1] -
                s[i - 1][j + w - 1] -
                s[i + h - 1][j - 1] +
                s[i - 1][j - 1]);
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &g[i][j]);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + g[i][j];
        }
    scanf("%d%d", &a, &b);

    printf("%d\n", min(check(a, b), check(b, a)));
    return 0;
}