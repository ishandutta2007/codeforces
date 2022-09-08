#include <bits/stdc++.h>

using namespace std;

const int max_n = 2222, inf = 1000111222;

int len, n, m, f[max_n], cost[max_n], dp[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> len >> n >> m;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j < r; ++j) {
            f[j] = 1;
        }
    }
    while (m--) {
        int x, c;
        cin >> x >> c;
        if (cost[x] == 0) {
            cost[x] = c;
        }
        cost[x] = min(cost[x], c);
    }
    for (int i = len - 1; i >= 0; --i) {
        dp[i] = inf;
        if (f[i] == 0) {
            dp[i] = dp[i + 1];
        }
        if (cost[i]) {
            for (int to = i + 1; to <= len; ++to) {
                dp[i] = min(dp[i], cost[i] * (to - i) + dp[to]);
            }
        }
    }
    if (dp[0] == inf) {
        cout << -1 << endl;
    } else {
        cout << dp[0] << endl;
    }
    return 0;
}