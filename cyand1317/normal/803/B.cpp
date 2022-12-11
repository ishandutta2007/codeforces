#include <cstdio>
#include <algorithm>
static const int MAXN = 2e5 + 3;
static const int INF = 0x3fffffff;

int n, a[MAXN], s[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    std::fill(s, s + n, INF);

    for (int i = 0, cur = INF; i < n; ++i) {
        if (a[i] == 0) cur = 0;
        s[i] = std::min(s[i], cur++);
    }
    for (int i = n - 1, cur = INF; i >= 0; --i) {
        if (a[i] == 0) cur = 0;
        s[i] = std::min(s[i], cur++);
    }

    for (int i = 0; i < n; ++i) printf("%d%c", s[i], i == n - 1 ? '\n' : ' ');
    return 0;
}