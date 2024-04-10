#include <stdio.h>
#include <stdlib.h>

#define maxn 101010
int n, l, r, q1, q2;
int a[maxn];

int sum(int l, int r) {
    return a[r] - (l > 0 ? a[l - 1] : 0);
}

#define min(u,v) ((u) < (v) ? u : v)

int cal(int x) {
    int t = sum(0, x - 1) * l + sum(n - x, n - 1) * r;
    int s = sum(x, n - x - 1);
    int len = n - 1 - 2 * x;
    if (len < 0) len = 0;
    // fprintf(stderr, "%d %d %d\n", t, s, len);
    return t + min(s * l + q1 * len, s * r + q2 * len);
}

int main() {
    scanf("%d%d%d%d%d", &n, &l, &r, &q1, &q2);
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%d", a + i);
        if (i) a[i] += a[i - 1];
    }
    int ans = 1 << 30;
    for (i = 0; i + i <= n; ++i) {
        ans = min(ans, cal(i));
        // fprintf(stderr, "%d %d\n", ans, i);
    }
    printf("%d", ans);
    return 0;
}