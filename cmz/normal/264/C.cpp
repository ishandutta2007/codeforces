#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int v[maxn], c[maxn];
long long dp[maxn], lst;
int n, q, pos1, pos2;
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    for (int cas = 1, a, b; cas <= q; ++cas) {
        scanf("%d%d", &a, &b);
        memset(dp, -0x3f, sizeof(dp));
        dp[0] = 0;
        pos1 = pos2 = 0;
        for (int i = 1; i <= n; ++i) {
            lst = dp[c[i]];
            dp[c[i]] = max(dp[c[i]], dp[c[i]] + 1LL * v[i] * a);
            if (pos1 != c[i])
                dp[c[i]] = max(dp[c[i]], dp[pos1] + 1LL * v[i] * b);
            else
                dp[c[i]] = max(dp[c[i]], dp[pos2] + 1LL * v[i] * b);
            if (dp[c[i]] == lst)
                continue;
            if (pos1 == c[i])
                continue;
            if (dp[c[i]] > dp[pos1] && c[i] != pos1)
                pos2 = pos1, pos1 = c[i];
            else if (dp[c[i]] > dp[pos2] && c[i] != pos2)
                pos2 = c[i];
        }
        long long ans = 0;
        for (int i = 1; i <= n; ++i) ans = std::max(ans, dp[i]);
        printf("%lld\n", ans);
    }
    return 0;
}