/**
 *  created: 16/02/2021, 16:35:32
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

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
        int ans = 0;
        for (int i = 0; i + 1 < n; ++i) {
            int x = min(a[i], a[i + 1]);
            int y = max(a[i], a[i + 1]);
            while (2 * x < y) {
                ++ans;
                x *= 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}