#include <bits/stdc++.h>

using namespace std;

const int max_n = 555, inf = 1000111222;

int n, k, a[max_n], b[max_n];
int dp[2][max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long ans = 0, suma = 0, sumb = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        suma += a[i];
        sumb += b[i];
    }
    int q1 = 0, q2 = 1;
    dp[q1][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] + b[i] >= k) {
            int l = max(0, k - b[i]);
            int r = min(k, a[i]);
            if (l == 0 && r == k) {
                --r;
            }
            for (int j = 0; j <= i; ++j) {
                for (int q = 0; q < k; ++q) {
                    dp[q2][j][q] = dp[q1][j][q];
                }
            }
            for (int j = 1; j <= i + 1; ++j) {
                int tot = 0;
                for (int q = k - r; q <= k - l; ++q) {
                    tot += dp[q1][j - 1][q % k];
                }
                for (int q = 0; q < k; ++q) {
                    dp[q2][j][q] |= tot > 0;
                    tot -= dp[q1][j - 1][(q - r + k) % k];
                    tot += dp[q1][j - 1][(q - l + 1 + k) % k];
                }
            }
            swap(q1, q2);
        }
    }
    int l = 0, r = 0;
    for (int cnt = 0; cnt <= n; ++cnt) {
        for (int rem = 0; rem < k; ++rem) {
            if (!dp[q1][cnt][rem]) {
                continue;
            }
            //cout << cnt << ": " << rem << endl;
            long long res = cnt + (suma - rem) / k + (sumb - (k - rem) % k) / k;
            if (cnt) {
                if (rem == 0) {
                    res -= cnt;
                } else {
                    res -= cnt - 1;
                }
            }
            //cout << cnt << " " << x << ": " << res << " = " << cnt << " + " << (suma - x) / k << " + " << (sumb - (cnt * k - x)) / k << endl;
            ans = max(ans, res);
        }
    }
    cout << ans << "\n";
    //cout << suma / k + sumb / k<< "\n";
    return 0;
}