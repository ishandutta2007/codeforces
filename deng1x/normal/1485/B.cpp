//
// Created by Junjie Wu on 2021/2/20.
//

#include <bits/stdc++.h>

using ll = long long;

const int N = 1e5 + 10;

int n, q, k;
int a[N];
ll v[N];

int main() {
    scanf("%d%d%d", &n, &q, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 2; i < n; ++i) {
        v[i] = (a[i + 1] - a[i] - 1) + (a[i] - a[i - 1] - 1);
        v[i] += v[i - 1];
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        ll ans = 0;
        if (l + 1 <= r - 1) {
            ans += v[r - 1] - v[l];
        }
        if (l != r) {
            ans += a[l + 1] - a[l] - 1;
            ans += a[r] - a[r - 1] - 1;
        }
        ans += a[l] - 1;
        ans += k - a[r];
        printf("%lld\n", ans);
    }
    return 0;
}