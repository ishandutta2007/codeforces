/**
 *  created: 13/06/2021, 18:42:23
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 400444, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        a[n + 1] = 0;
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                ans += a[i] - max(a[i - 1], a[i + 1]);
                a[i] = max(a[i - 1], a[i + 1]);
            }
        }
        for (int i = 1; i <= n + 1; ++i) {
            ans += abs(a[i] - a[i - 1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}