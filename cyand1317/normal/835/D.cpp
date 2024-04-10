#include <cstdio>
#include <cstring>
#include <algorithm>
static const int MAXN = 5004;

int n;
char s[MAXN];

int f[MAXN][MAXN];
int lcp[MAXN][MAXN];
int ans[MAXN] = { 0 };

int main()
{
    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; i < n; ++i) {
        lcp[i][i] = n - i;
        for (int j = i + 1; j < n; ++j) {
            int l = (i == 0 ? 0 : std::max(0, lcp[i - 1][j - 1] - 1));
            while (j + l < n && s[i + l] == s[j + l]) ++l;
            lcp[i][j] = lcp[j][i] = l;
        }
    }

    memset(f, -1, sizeof f);

    for (int i = 0; i < n; ++i) f[i][i] = 1;
    for (int i = 0; i < n - 1; ++i) f[i][i + 1] = (s[i] == s[i + 1] ? 2 : -1);
    for (int d = 2; d < n; ++d)
        for (int i = 0; i < n - d; ++i)
            f[i][i + d] = (s[i] == s[i + d] && f[i + 1][i + d - 1] > 0 ? 1 : -1);

    for (int d = 2; d < n; ++d)
        for (int i = 0; i < n - d; ++i) {
            int m = i + d + 1 - (d + 1) / 2;
            if (lcp[i][m] >= (d + 1) / 2 && f[i][i + (d + 1) / 2 - 1] > 0)
                f[i][i + d] = std::max(f[i][i + d], f[i][i + (d + 1) / 2 - 1] + 1);
        }

    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) ++ans[f[i][j]];
    for (int i = n - 1; i >= 0; --i) ans[i] += ans[i + 1];
    for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], i == n ? '\n' : ' ');

    return 0;
}