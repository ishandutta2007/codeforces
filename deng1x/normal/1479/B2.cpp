//
// Created by Junjie Wu on 2021/2/17.
//

#include <bits/stdc++.h>

/*
 * assume all a[i] != a[i - 1], b[i]=0/1 indicates the group
 * answer = min(f[i] + (n - i))   (b[i - 1] != b[i] = b[i + 1] = ... = b[n])
 * f[0] = 0, f[1] = 1, for i >= 2
 * f[i] = min(f[j] + (i - j - 1) + [a[j - 1] != a[i]]) 1 <= j < i
 * b[j - 1] != b[j] = ... = b[i - 1] != b[i]
 *
 * for a fixed i, let g[j] = f[j] + (i - j - 1) + [a[j - 1] != a[i]]
 * f[i] = min(g[i - 1], g[j*]) where j* = max(1 <= j < i, a[j - 1] = a[i])
 */

const int MAX_N = 1e5 + 10;

int n;
int a[MAX_N], f[MAX_N];
int last[MAX_N];

int main() {
    scanf("%d", &n);
    int m = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + (++m));
        if (a[m] == a[m - 1]) {
            --m;
        }
    }
    n = m;

    f[0] = 0;
    f[1] = 1; last[a[1]] = 1;

    int ans = std::min(f[0] + n, f[1] + n - 1);
    for (int i = 2; i <= n; ++i) {
        // f[i] = g[i - 1]
        f[i] = f[i - 1] + (a[i - 2] != a[i]);
        // update with g[j*]
        int j = last[a[i]];
        if (j) {
            ++j;
            f[i] = std::min(f[i], f[j] + (i - j - 1));
        }
        ans = std::min(ans, f[i] + n - i);
        last[a[i]] = i;
    }

    printf("%d\n", ans);
    return 0;
}