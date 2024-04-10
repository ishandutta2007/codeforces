#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;

int n, k, a[max_n], dp[max_n], cnt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    int mn = inf, cur = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++dp[a[i]];
        mn = min(mn, a[i]);
        cur = max(cur, a[i]);
    }
    for (int i = max_n - 2; i >= 0; --i) {
        dp[i] += dp[i + 1];
    }
    int ans = 0;
    while (cur > mn) {
        ++ans;
        int cnt = 0;
        while (cur > mn && cnt + dp[cur] <= k) {
            cnt += dp[cur];
            --cur;
        }
    }
    printf("%d\n", ans);
    return 0;
}