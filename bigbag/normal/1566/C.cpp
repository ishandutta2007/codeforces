/**
 *  created: 12/09/2021, 17:42:08
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, pr[max_n][2], dp[max_n];
string a[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> a[0] >> a[1];
        a[0] = " " + a[0];
        a[1] = " " + a[1];
        ++n;
        for (int i = 1; i < n; ++i) {
            pr[i][0] = pr[i - 1][0];
            pr[i][1] = pr[i - 1][1];
            pr[i][a[0][i] - '0'] = i;
            pr[i][a[1][i] - '0'] = i;
        }
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1];
            int pos = inf;
            for (int j = 0; j < 2; ++j) {
                pos = min(pos, pr[i][j]);
                if (pos) {
                    dp[i] = max(dp[i], j + 1 + dp[pos - 1]);
                }
            }
        }
        cout << dp[n - 1] << "\n";
    }
    return 0;
}