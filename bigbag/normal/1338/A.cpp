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
        int mx = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                mx = max(mx, a[i - 1] - a[i]);
                a[i] = a[i - 1];
            }
        }
        int ans = 0;
        while (mx > ((1LL << ans) - 1)) {
            ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}