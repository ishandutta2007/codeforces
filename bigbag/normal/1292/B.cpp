#include <bits/stdc++.h>

using namespace std;

const int max_n = 111;
const long long inf = 100011122200011122LL;

int n;
long long x[max_n], y[max_n], dp[max_n][max_n][2];

void read() {
    cin >> x[0] >> y[0];
    long long ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    n = 1;
    while (true) {
        if (x[n - 1] > inf / ax || y[n - 1] > inf / ay) {
            break;
        }
        x[n] = 1LL * x[n - 1] * ax + bx;
        y[n] = 1LL * y[n - 1] * ay + by;
        //cout << n << ": " << x[n] << " " << y[n] << endl;
        ++n;
    }
}

long long dist(int a, int b) {
    return llabs(x[a] - x[b]) + llabs(y[a] - y[b]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    read();
    long long xs, ys, t;
    cin >> xs >> ys >> t;
    for (int i = 0; i < n; ++i) {
        dp[i][i][0] = llabs(xs - x[i]) + llabs(ys - y[i]);
        dp[i][i][1] = llabs(xs - x[i]) + llabs(ys - y[i]);
    }
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            const int r = l + len - 1;
            dp[l][r][0] = min({inf,
                            dp[l + 1][r][0] + dist(l, l + 1),
                            dp[l + 1][r][1] + dist(l, r)});
            dp[l][r][1] = min({inf,
                            dp[l][r - 1][1] + dist(r - 1, r),
                            dp[l][r - 1][0] + dist(l, r)});
        }
    }
    int ans = 0;
    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            const int r = l + len - 1;
            if (dp[l][r][0] <= t || dp[l][r][1] <= t) {
                //cout << l << " " << r << ": " << dp[l][r][0] << " " << dp[l][r][1] << endl;
                ans = len;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}