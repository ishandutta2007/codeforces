#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int t, n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int pos = min_element(a, a + n) - a, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i != pos) {
                ans += (k - a[i]) / a[pos];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}