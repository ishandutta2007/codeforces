/**
 *  created: 25/01/2021, 17:03:34
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, c1, c2, n, a[max_n], b[max_n], cnt[2][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &c1, &c2, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            --a[i];
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
            --b[i];
        }
        fill(cnt[0], cnt[0] + c1, 0);
        fill(cnt[1], cnt[1] + c2, 0);
        for (int i = 0; i < n; ++i) {
            ++cnt[0][a[i]];
            ++cnt[1][b[i]];
        }
        long long ans = 1LL * n * (n - 1) / 2;
        for (int i = 0; i < c1; ++i) {
            ans -= 1LL * cnt[0][i] * (cnt[0][i] - 1) / 2;
        }
        for (int i = 0; i < c2; ++i) {
            ans -= 1LL * cnt[1][i] * (cnt[1][i] - 1) / 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}