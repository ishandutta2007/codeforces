/**
 *  created: 18/03/2021, 17:01:12
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        long long ans = 1LL * inf * inf;
        vector<int> mn(2, inf);
        vector<int> cnt(2);
        vector<long long> sum(2);
        for (int i = 0; i < n; ++i) {
            mn[i % 2] = min(mn[i % 2], a[i]);
            sum[i % 2] += a[i];
            ++cnt[i % 2];
            if (i) {
                long long res = sum[0] + sum[1];
                res += 1LL * mn[0] * (n - cnt[0]);
                res += 1LL * mn[1] * (n - cnt[1]);
                ans = min(ans, res);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}