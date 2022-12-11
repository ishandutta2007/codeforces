#include <stdio.h>
#define MAXN 200018

int main() {
    long long n, a, d[MAXN], sum = 0, i;
    scanf("%I64d%I64d", &n, &a);
    for (i = 0; i < n; ++i) {
        scanf("%I64d", &d[i]);
        sum += d[i];
    }
    for (i = 0; i < n; ++i) {
        long long min_val = a - (sum - d[i]);
        if (min_val < 1) min_val = 1;
        long long max_val = a - (n - 1);
        if (max_val > d[i]) max_val = d[i];
        printf(i ? " %I64d" : "%I64d", d[i] - (max_val - min_val + 1));
    }
    return 0;
}