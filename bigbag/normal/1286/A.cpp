#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, a[max_n], used[max_n], dp[max_n][max_n][2];

void upd(int i, int j, int last, int val) {
    dp[i][j][last] = min(dp[i][j][last], val);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        used[a[i]] = 1;
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            if (i % 2 == 0) {
                ++x;
            } else {
                ++y;
            }
        }
    }
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            dp[i][j][0] = inf;
            dp[i][j][1] = inf;
        }
    }
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    int zero = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= zero; ++j) {
            for (int last = 0; last < 2; ++last) {
                if (dp[i][j][last] == inf) {
                    continue;
                }
                //cout << i << " " << j << " " << last << ": " << dp[i][j][last] << endl;
                if (a[i]) {
                    upd(i + 1, j, a[i] % 2, dp[i][j][last] + (a[i] % 2 != last));
                } else {
                    if (j < x) {
                        upd(i + 1, j + 1, 0, dp[i][j][last] + (last != 0));
                    }
                    if (zero - j < y) {
                        upd(i + 1, j, 1, dp[i][j][last] + (last != 1));
                    }
                }
            }
        }
        zero += a[i] == 0;
    }
    int ans = min(dp[n][x][0], dp[n][x][1]);
    cout << ans << "\n";
    return 0;
}