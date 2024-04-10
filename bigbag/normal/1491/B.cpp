/**
 *  created: 28/02/2021, 15:40:58
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, u, v, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &u, &v);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        bool ok = 1;
        for (int i = 1; i < n; ++i) {
            ok &= abs(a[i] - a[i - 1]) <= 1;
        }
        if (ok) {
            int ans = min(u, v);
            if (*min_element(a, a + n) == *max_element(a, a + n)) {
                ans += v;
            }
            printf("%d\n", ans);
        } else {
            puts("0");
        }
    }
    return 0;
}