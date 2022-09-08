#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111;
const long long inf = 1000111222000111222LL;

int n, a[max_n];
long long r1, r2, r3, d, dp[max_n];

long long cost1(int x) {
    return x * r1 + r3;
}

long long cost2(int x) {
    return r2 + r1;
}

long long cost3(int x) {
    return (x + 2) * r1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        dp[i] = inf;
    }
    dp[n] = inf;
    dp[0] = 0;
    long long ans = inf;
    for (int i = 0; i < n; ++i) {
        //cout << i << ": " << dp[i] << endl;
        dp[i + 1] = min(dp[i + 1], dp[i] + cost1(a[i]) + d);

        if (i + 1 == n) {
            long long res = dp[i] + 2 * d + min(cost2(a[i]), cost3(a[i]));
            ans = min(ans, res);
        } else {
            long long res = dp[i] + 4 * d + min(cost2(a[i]), cost3(a[i]));
            res += min({cost1(a[i + 1]), cost2(a[i + 1]), cost3(a[i + 1])});
            //cout << i << " -> " << i + 2 << ": " << res << "   " << min(cost2(a[i]), cost3(a[i])) << " " << min({cost1(a[i + 1]), cost2(a[i + 1]), cost3(a[i + 1])}) << endl;
            dp[i + 2] = min(dp[i + 2], res);
        }
        if (i + 2 == n) {
            long long res = dp[i] + 2 * d + min(cost2(a[i]), cost3(a[i])) + cost1(a[i + 1]);
            ans = min(ans, res);
        }
    }
    //cout << dp[n] << endl;
    ans = min(ans, dp[n] - d);
    cout << ans << "\n";
    return 0;
}