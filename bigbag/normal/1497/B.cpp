/**
 *  created: 17/03/2021, 16:39:43
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, m, a[max_n], cnt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            ++cnt[a[i] % m];
        }
        int ans = cnt[0] > 0;
        if (m % 2 == 0) {
            ans += cnt[m / 2] > 0;
        }
        for (int i = 1; i * 2 < m; ++i) {
            int x = min(cnt[i], cnt[m - i]);
            int y = max(cnt[i], cnt[m - i]);
            if (y) {
                ans += 1;
                if (y > x + 1) {
                    ans += y - x - 1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}