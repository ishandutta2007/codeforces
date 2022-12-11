#include <cstdio>
#include <algorithm>
typedef long long int64;

int q, n;

int main()
{
    scanf("%d", &q);

    for (int i = 0; i < q; ++i) {
        scanf("%d", &n);
        if (n <= 5) {
            printf("%d\n", n - 1); continue;
        }
        int lo = 3, hi = n, mid;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            int64 edges = (int64)mid * (mid - 1) / 2 + (n - mid);
            int64 bridges = n - mid;
            if (bridges * 2 >= edges) lo = mid; else hi = mid;
        }
        printf("%I64d\n", std::max(
            (int64)lo * (lo - 1) / 2 + (n - lo),
            (int64)(n - hi) * 2
        ));
    }

    return 0;
}