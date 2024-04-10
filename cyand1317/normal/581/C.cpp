#include <cstdio>
#include <algorithm>
static const int MAXN = 100008;
int n, k;
int r[11] = { 0 };

int main()
{
    scanf("%d%d", &n, &k);
    int a;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ans += a / 10;
        if (a % 10) ++r[10 - a % 10];
        r[10] += (100 - a) / 10;
    }

    for (int i = 1; i <= 10; ++i) {
        if (k >= r[i] * i) {
            k -= r[i] * i;
            ans += r[i];
        } else {
            ans += k / i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}