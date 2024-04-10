#include <bits/stdc++.h>

using namespace std;

const int max_n = 222, inf = 1000111222;

string s, a, t;
int n, k, dp[max_n][max_n][max_n];

void upd(int &x, int val) {
    x = max(x, val);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> s >> t;
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int c0 = 0; c0 <= i; ++c0) {
            for (int cnt = 0; cnt <= i && cnt <= k; ++cnt) {
                if (dp[i][c0][cnt] == -1) {
                    continue;
                }
                upd(dp[i + 1][c0 + (s[i] == t[0])][cnt], dp[i][c0][cnt] + (s[i] == t[1]) * c0);
                upd(dp[i + 1][c0 + 1][cnt + 1], dp[i][c0][cnt] + (t[0] == t[1]) * c0);
                upd(dp[i + 1][c0 + (t[0] == t[1])][cnt + 1], dp[i][c0][cnt] + c0);
            }
        }
    }
    int ans = 0;
    for (int c0 = 0; c0 <= n; ++c0) {
        for (int cnt = 0; cnt <= k; ++cnt) {
            ans = max(ans, dp[n][c0][cnt]);
        }
    }
    cout << ans << "\n";
    return 0;
}