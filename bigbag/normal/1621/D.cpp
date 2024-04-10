/**
 *  created: 03/01/2022, 17:12:02
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 505, inf = 1000111222;

int t, n, a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < 2 * n; ++j) {
                cin >> a[i][j];
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += a[i][j];
                ans += a[n + i][n + j];
            }
        }
        int add = inf;
        if (n == 1) {
            add = min(a[0][1], a[1][0]);
        } else {
            for (int i = 0; i < n; i += n - 1) {
                for (int j = 0; j < n; j += n - 1) {
                    for (int x = 0; x <= n; x += n) {
                        int y = x ^ n;
                        add = min(add, a[x + i][y + j]);
                    }
                }
            }
        }
        ans += add;
        cout << ans << "\n";
    }
    return 0;
}