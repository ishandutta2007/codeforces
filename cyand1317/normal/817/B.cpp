#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 1e5 + 3;

int n, a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    std::sort(a, a + n);
    if (a[0] == a[2]) {
        int ct = std::upper_bound(a, a + n, a[0]) - &a[0];
        printf("%I64d\n", (int64)ct * (ct - 1) * (ct - 2) / 6);
    } else if (a[0] == a[1]) {
        int ct = std::upper_bound(a, a + n, a[2]) - &a[2];
        printf("%d\n", ct);
    } else if (a[1] == a[2]) {
        int ct = std::upper_bound(a, a + n, a[1]) - &a[1];
        printf("%I64d\n", (int64)ct * (ct - 1) / 2);
    } else {
        int ct = std::upper_bound(a, a + n, a[2]) - &a[2];
        printf("%d\n", ct);
    }

    return 0;
}