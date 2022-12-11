#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 500006;

int n, k;
int c[MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    int64 sum_c = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
        sum_c += c[i];
    }
    std::sort(c, c + n);

    int64 s = 0, t;
    int i, poorest, richest;
    for (i = 0; i < n - 1; ++i) {
        t = s + (int64)(i + 1) * (c[i + 1] - c[i]);
        if (t > k) break; else s = t;
    }
    poorest = c[i] + (k - s) / (i + 1);
    s = 0;
    for (i = n - 1; i > 0; --i) {
        t = s + (n - i) * (c[i] - c[i - 1]);
        if (t > k) break; else s = t;
    }
    richest = c[i] - (k - s) / (n - i);
    printf("%d\n", std::max(sum_c % n == 0 ? 0 : 1, richest - poorest));
    return 0;
}