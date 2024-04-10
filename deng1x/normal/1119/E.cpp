#include <bits/stdc++.h>

const int MAXN = 300010;
using ll = long long;

int n;
int a[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    ll ans = 0, rem = 0;
    for (int i = 1; i <= n; ++i) {
        ll now = std::min(rem, a[i] / 2ll);
        ans += now;
        a[i] -= now << 1;
        rem -= now;

        ans += a[i] / 3;
        rem += a[i] % 3;
    }
    printf("%lld\n", ans);
    return 0;
}