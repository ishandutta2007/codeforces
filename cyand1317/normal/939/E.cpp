#include <cstdio>
#include <algorithm>
#include <utility>

typedef long long int64;
static const int MAXN = 5e5 + 4;

static int q, n;
static int a[MAXN];
static int64 s[MAXN] = { 0 };

static inline double get(int i)
{
    return (double)(s[i] + a[n - 1]) / (i + 1);
}

int main()
{
    scanf("%d", &q);
    n = 0;

    for (int i = 0, op; i < q; ++i) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &a[n++]);
            s[n] = s[n - 1] + a[n - 1];
        } else if (op == 2) {
            int lo = 0, hi = n, mid;
            while (lo < hi - 1) {
                mid = (lo + hi) >> 1;
                if (get(mid) > get(mid + 1)) lo = mid; else hi = mid;
            }
            printf("%.8lf\n", a[n - 1] - get(hi));
        } else puts("> <");
    }

    return 0;
}