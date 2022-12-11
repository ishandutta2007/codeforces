#include <stdio.h>
#include <math.h>
#define MAXN 200003
// In this program, if _a < 0, then it must be -1.
#define floor_intdiv(_a, _b) ((_a) < 0 ? -1 : (_a) / (_b))

int main()
{
    // ans is the prefix sum array of the answers for each k-ary heap.
    int n, i, j, k, a[MAXN], ans[MAXN] = {0};
// Increases the answers for k-ary heaps, for k in [_lb, _hb).
#define addans(_lb, _hb, _val) (ans[(_lb)] += (_val), ans[(_hb)] -= (_val))
    scanf("%d", &n);
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);

    for (i = 0; i < n; ++i) {
        // Calculate the answer for each number i in all heaps in O(sqrt(i)) time.
        for (j = 1; j < n; ++j)
            if (floor_intdiv(i - 1, j) == floor_intdiv(i - 1, j + 1)) break;
            else addans(j, j + 1, a[i] < a[(i - 1) / j]);
        int t = (int)floor_intdiv(i - 1, j);
        for (k = 1; k <= t; ++k) {
            addans(
                (int)floor_intdiv(i - 1, k + 1) + 1, (int)floor_intdiv(i - 1, k) + 1,
                a[i] < a[k]);
        }
        addans(i, n, a[i] < a[0]);
    }

    for (i = 1; i < n; ++i)
        printf("%d ", ans[i] += ans[i - 1]);
    return 0;
}