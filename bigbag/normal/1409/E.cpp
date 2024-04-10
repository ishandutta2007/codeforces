#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, k, x[max_n], y, dp1[max_n], dp2[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &y);
        }
        sort(x, x + n);
        dp2[n] = 0;
        for (int i = 0; i < n; ++i) {
            dp1[i] = x + i - lower_bound(x, x + i + 1, x[i] - k) + 1;
            dp2[i] = upper_bound(x + i, x + n, x[i] + k) - x - i;
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp2[i] = max(dp2[i], dp2[i + 1]);
        }
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp1[i] + dp2[i + 1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}