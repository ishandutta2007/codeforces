#include <cstdio>
#include <algorithm>
#include <utility>
static const int MAXN = 1e5 + 4;
static const int MAXM = 1e5 + 4;

int n, m;
int d[MAXN], a[MAXM];

inline bool check(int n)
{
    static int last[MAXM];
    for (int i = 0; i < m; ++i) last[i] = -1;
    for (int i = 0; i < n; ++i) if (d[i] != -1) last[d[i]] = i;
    static std::pair<int, int> p[MAXM];
    for (int i = 0; i < m; ++i) {
        if (last[i] == -1) return false;
        p[i] = std::make_pair(last[i], i);
    }
    std::sort(p, p + m);
    int ct = 0;
    for (int i = 0; i < m; ++i) {
        ct += a[p[i].second] + 1;
        if (ct > p[i].first + 1) return false;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) { scanf("%d", &d[i]); --d[i]; }
    for (int i = 0; i < m; ++i) scanf("%d", &a[i]);

    int lo = 0, hi = n + 2, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (!check(mid)) lo = mid; else hi = mid;
    }

    printf("%d\n", hi > n ? -1 : hi);
    return 0;
}