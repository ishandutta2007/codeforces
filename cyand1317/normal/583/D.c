#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 23333
#define MAXELEM 308

int n, t;
int a[MAXN];

// Calculate the longest non-decreasing sequence
// Time complexity: O(n log n)
int *lnds(int *a, int n)
{
    int *ret = (int *)malloc(n * sizeof(int));
    int a_with_f[MAXN], maxlen = 1;
    ret[0] = 1;
    a_with_f[0] = -1;
    a_with_f[1] = a[0];
    int lo, hi, mid, i;
    for (i = 1; i < n; ++i) {
        if (a[i] >= a_with_f[maxlen]) {
            a_with_f[++maxlen] = a[i];
        } else {
            lo = 0, hi = maxlen;
            while (lo < hi - 1) {
                mid = (lo + hi) / 2;
                if (a[i] >= a_with_f[mid]) lo = mid;
                else hi = mid;
            }
            a_with_f[lo + 1] = a[i];
        }
        ret[i] = maxlen;
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &t);
    int i;
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);
    if (t <= 233) {
        for (i = n; i < n * t; i += n)
            memcpy(a + i, a, n * sizeof(int));
        int *first_part = lnds(a, n * t);
        printf("%d\n", first_part[n * t - 1]);
    } else {
        for (i = n; i < n * 233; i += n)
            memcpy(a + i, a, n * sizeof(int));
        int *first_part = lnds(a, n * 233);
        int count[MAXELEM] = { 0 }, maxcount = 0;
        for (i = 0; i < n; ++i) ++count[a[i]];
        for (i = 0; i < MAXELEM; ++i) if (maxcount < count[i]) maxcount = count[i];
        for (i = 0; i < n * 233; i += n)
            if (first_part[i + n] - first_part[i] == maxcount) break;
        i /= n;
        // assert(i == 1)?
        printf("%d\n", first_part[i * n + n - 1] + (t - i - 1) * maxcount);
    }
    return 0;
}