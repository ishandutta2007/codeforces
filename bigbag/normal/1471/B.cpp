/**
 *  created: 06/01/2021, 14:51:09
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, x, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &x);
        pair<int, int> mn(inf, inf);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            int cnt = 1, cur = a[i];
            while (cur % x == 0) {
                cur /= x;
                ++cnt;
            }
            mn = min(mn, {cnt, i});
        }
        long long ans = mn.first * accumulate(a, a + n, 0LL) + accumulate(a, a + mn.second, 0LL);
        printf("%lld\n", ans);
    }
    return 0;
}