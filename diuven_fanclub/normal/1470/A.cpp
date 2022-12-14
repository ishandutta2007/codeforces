#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, K[300005], C[300005];

int main() {
    int t;
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", &K[i]);
        for (int i = 1; i <= m; i++) scanf("%d", &C[i]);
        sort(K + 1, K + n + 1);
        ll sum = 0;
        for (int i = 1; i <= n; i++) sum += C[K[i]];
        ll ans = sum;
        for (int i = 1; i <= min(n, m); i++) {
            int add = C[i] - C[K[n - i + 1]];
            sum += add;
            if (add > 0) break;
            ans = min(ans, sum);
        }
        printf("%lld\n", ans);
    }
}