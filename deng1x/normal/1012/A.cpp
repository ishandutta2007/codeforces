//
// Created by Wu Junjie on 2019-06-11.
//

#include <bits/stdc++.h>

const int MAXN = 100010;
using ll = long long;

int n;
int a[MAXN << 1];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n + n; ++i) {
        scanf("%d", a + i);
    }
    if (n == 1) {
        puts("0");
        return 0;
    }
    std::sort(a + 1, n + n + a + 1);
    ll ans = 1ll * (a[n + n] - a[n + 1]) * (a[n] - a[1]);

    for (int i = 2; i + n - 1 <= n + n; ++i) {
        ans = std::min(ans, 1ll * (a[n + n] - a[1]) * (a[i + n - 1] - a[i]));
    }

    printf("%lld\n", ans);
    return 0;
}