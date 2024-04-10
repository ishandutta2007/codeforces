/**
 *  created: 25/01/2021, 17:25:16
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, cnt[max_n], dp[max_n];
vector<int> all[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 1; i < max_n; ++i) {
        for (int j = 2 * i; j < max_n; j += i) {
            all[j].push_back(i);
        }
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            ++cnt[x];
        }
        int ans = 0;
        for (int x = 1; x < max_n; ++x) {
            dp[x] = 0;
            for (int d : all[x]) {
                dp[x] = max(dp[x], dp[d]);
            }
            dp[x] += cnt[x];
            ans = max(ans, dp[x]);
        }
        printf("%d\n", n - ans);
    }
    return 0;
}