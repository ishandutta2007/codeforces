#include <cstdio>
typedef long long int64;
static const int MAXN = 2e5 + 5;

int n, k, a[MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int64 pfx_wghted = 0;
    int counted = 0;
    for (int i = 0; i < n; ++i) {
        int64 rating_delta = pfx_wghted - (int64)(n - 1 - i) * a[i] * counted;
        if (rating_delta < k) {
            printf("%d\n", i + 1);
        } else {
            pfx_wghted += (int64)counted * a[i];
            ++counted;
        }
    }

    return 0;
}