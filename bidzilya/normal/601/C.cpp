#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    int all = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        all += a[i];
    }

    if (m == 1) {
        cout << fixed << setprecision(15);
        cout << 1.0 << endl;
        return 0;
    }

    vector<double> dp[2];
    int cur = 0;
    int nxt = 1;
    dp[cur].assign(n * m + 1, 0.0);
    dp[nxt].resize(n * m + 1);
    dp[cur][0] = 1.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n * m; ++j) {
            dp[nxt][j] = 0.0;
        }
        for (int j = 0; j <= n * m; ++j) {
            if (j + 1 <= n * m) {
                dp[nxt][j + 1] += dp[cur][j];
            }
            if (j + m + 1 <= n * m) {
                dp[nxt][j + m + 1] -= dp[cur][j];
            }
        }
        for (int j = 1; j <= n * m; ++j) {
            dp[nxt][j] += dp[nxt][j - 1];
        }
        for (int j = 0; j <= n * m; ++j) {
            if (j + a[i] <= n * m) {
                dp[nxt][j + a[i]] -= dp[cur][j];
            }
        }
        for (int j = 0; j <= n * m; ++j) {
            dp[nxt][j] /= (m - 1);
        }
        swap(cur, nxt);
    }

    double ans = 0.0;
    for (int i = 0; i < all; ++i) {
        ans += dp[cur][i];
    }
    ans *= (m - 1);
    ans += 1.0;

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}