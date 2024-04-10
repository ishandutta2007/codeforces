#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

long long dp[N];
int a[N], c[N];

const long long inf = 1LL<<60;

int main() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        set<pair<long long, int> > S;
        for (int i = 1; i <= n; i++) dp[i] = -inf;
        long long ma1 = -inf, ma2 = -inf;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int u = c[i];
            long long other = (dp[u] == ma1 ? ma2 : ma1);
            long long cur = -inf;
            if (dp[u] > -inf) cur = max(cur, dp[u] + a[i] * 1LL * x);
            cur = max(cur, a[i] * 1LL * y + max(0LL, other));
            if (cur <= dp[u]) continue;
            dp[u] = cur;
            if (cur <= ma2) continue;
            if (cur >= ma1) {
                ma2 = other, ma1 = cur;
            } else {
                ma2 = cur;
            }
            ans = max(ans, cur);
        }
        printf("%lld\n", ans);
    }
    return 0;
}