#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>

typedef std::pair<long double, int> angle_data;
#define angle  first
#define index  second

static const int MAXN = 100007;
int n;
angle_data a[MAXN];

int main()
{
    scanf("%d", &n);
    int x, y;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x, &y);
        a[i].index = i + 1;
        a[i].angle = atan2(y, x);
    }
    std::sort(a, a + n);
    long double min_delta = 31.4159, t;
    int min_idx1, min_idx2;
    for (int i = 0; i < n - 1; ++i) {
        if ((t = a[i + 1].angle - a[i].angle) < min_delta) {
            min_delta = t;
            min_idx1 = a[i + 1].index;
            min_idx2 = a[i].index;
        }
    }
    if ((t = M_PI * 2.0 - (a[n - 1].angle - a[0].angle)) < min_delta) {
        min_delta = t;
        min_idx1 = a[n - 1].index;
        min_idx2 = a[0].index;
    }
    printf("%d %d\n", min_idx1, min_idx2);
    return 0;
}