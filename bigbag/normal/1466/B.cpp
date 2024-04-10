/**
 *  created: 30/12/2020, 16:38:38
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

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
        int ans = 1;
        a[n] = inf;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] + 1 < a[i + 1]) {
                ++a[i];
            }
        }
        for (int i = 1; i < n; ++i) {
            ans += a[i] != a[i - 1];
        }
        printf("%d\n", ans);
    }
    return 0;
}