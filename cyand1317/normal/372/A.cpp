#include <cstdio>
#include <algorithm>
static const int MAXN = 5e5 + 4;

int n, s[MAXN];

inline bool check(int hides)
{
    int next = hides;
    for (int i = 0; i < hides; ++i) {
        while (next < n && s[next] < 2 * s[i]) ++next;
        if (next == n) return false;
        ++next;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
    std::sort(s, s + n);

    int lo = 0, hi = n, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (check(mid)) lo = mid; else hi = mid;
    }

    printf("%d\n", n - lo);
    return 0;
}