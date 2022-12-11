#include <cstdio>
#include <cstdlib>
#include <algorithm>
static const int MAXN = 1e5 + 4;
static const int INF = 1e4 + 4;

int n, a[MAXN];
int sum = 0, best_rm = -INF;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > 0) sum += a[i];
        if (a[i] & 1) {
            best_rm = std::max(best_rm, -std::abs(a[i]));
        }
    }

    printf("%d\n", sum + ((sum & 1) ? 0 : best_rm));
    return 0;
}