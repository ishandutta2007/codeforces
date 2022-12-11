#include <stdio.h>
#define MAXN 200003
#define INF 0x100ffeea900dc0deL

int main()
{
    int n, k, i; long long a[MAXN];
    unsigned short q[MAXN];
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) (q[i] = !scanf("%I64d", &a[i])) ? getchar() : 0;
    unsigned short incorrect = 0;
    for (i = 0; i < k; i++) {
        // Process sequence a[i], a[i+k], a[i+2k], ...
        long long last1 = -INF, last2, j1 = i - k, j2, a1, a2, ii;
        // Check whether the sequence can be directly seen incorrect.
        while ((j1 += k) < n) if (!q[j1]) {
            last2 = last1; last1 = a[j1];
            if (last2 >= last1) { incorrect = 1; break; }
        }
        if (incorrect) break;
        // The real process.
        j1 = i;
        while (j1 < n - k) {
            while (j1 < n && !q[j1]) j1 += k;
            a1 = j1 < k ? -INF : a[j1 - k];
            j2 = j1;
            while (j2 < n && q[j2]) j2 += k;
            if (j2 <= j1) break;
            a2 = j2 >= n ? INF : a[j2];
            if (a2 - a1 - 1 < (j2 - j1) / k) { incorrect = 1; break; }
            // Now we have
            // [j1-k] [j1] ... [j2-k] [j2]
            //   a1    ?    ?    ?     a2
            if (a1 >= 0 && a2 >= 0) {
                a[j1] = a1 + 1;
                for (ii = j1 + k; ii < j2; ii += k) a[ii] = a[ii - k] + 1;
            } else if (a1 <= 0 && a2 <= 0) {
                a[j2 - k] = a2 - 1;
                for (ii = j2 - k - k; ii >= j1; ii -= k) a[ii] = a[ii + k] - 1;
            } else {    // a1 <= 0 && a2 >= 0
                long long len = (j2 - j1) / k, begin = -len / 2;
                if (begin <= a1) begin = a1 + 1;
                else if (begin > a2 - len) begin = a2 - len;
                a[j1] = begin;
                for (ii = j1 + k; ii < j2; ii += k) a[ii] = a[ii - k] + 1;
            }

            j1 = j2;
        }
        if (incorrect) break;
    }
    if (incorrect) printf("Incorrect sequence\n");
    else {
        for (i = 0; i < n; i++) printf("%I64d ", a[i]);
        putchar('\n');
    }
    return 0;
}