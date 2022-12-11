#include <cstdio>
#include <algorithm>
static const int MAXN = 103;

int n, s[MAXN];
int pfx[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &s[i]);

    pfx[0] = 0;
    for (int i = 0; i < n; ++i) pfx[i + 1] = pfx[i] + s[i];

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = std::max(ans, (i - pfx[i]) + (pfx[n] - pfx[i]));
    }
    printf("%d\n", ans);

    return 0;
}