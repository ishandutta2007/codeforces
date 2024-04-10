#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 101111;
const long long inf = 1011111111000000000LL;

int a, b, h, w, n, x[max_n];

int solve() {
    long long dp[2][max_n];
    for (int j = 0; j < max_n; ++j) {
        dp[0][j] = inf;
        dp[1][j] = inf;
    }
    int q1 = 0, q2 = 1;
    dp[q1][1] = 1;
    long long p = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            dp[q2][j] = dp[q1][j];
        }
        for (int j = 0; j < max_n; ++j) {
            if (dp[q1][j] == inf) {
                continue;
            }
            if (1LL * h * j >= a && 1LL * w * (p / dp[q1][j]) >= b) {
                return i;
            }
            if (i == n) {
                continue;
            }
            int nxt = min(max_n - 10LL, dp[q1][j] * x[i]);
            dp[q2][nxt] = min(dp[q2][nxt], dp[q1][j] * x[i]);
        }
        p *= x[i];
        swap(q1, q2);
    }
    return max_n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    sort(x, x + n);
    reverse(x, x + n);
    int ans = solve();
    swap(a, b);
    ans = min(ans, solve());
    if (ans == max_n) {
        ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}