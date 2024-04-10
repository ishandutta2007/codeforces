/**
 *  created: 29/08/2021, 17:40:14
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111;
const long long inf = 1000111222000111222LL;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            a[i] %= 2;
        }
        long long ans = inf;
        for (int it = 0; it < 2; ++it) {
            for (int i = 0; i < n; ++i) {
                a[i] ^= 1;
            }
            int need = (n + 1) / 2, cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += a[i] == 0;
            }
            if (cnt != need) {
                continue;
            }
            int cur = 0;
            long long res = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] == 0) {
                    res += abs(i - cur);
                    cur += 2;
                }
            }
            ans = min(ans, res);
        }
        if (ans == inf) {
            ans = -1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}