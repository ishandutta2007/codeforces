#include <bits/stdc++.h>

using namespace std;

const int max_n = 11, inf = 1000111222;

int t, n, m, a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        int zero = 0, neg = 0, ans = 0, mn = inf;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
                zero += a[i][j] == 0;
                neg += a[i][j] < 0;
                ans += abs(a[i][j]);
                mn = min(mn, abs(a[i][j]));
            }
        }
        if (!zero && neg % 2) {
            ans -= 2 * mn;
        }
        printf("%d\n", ans);
    }
    return 0;
}