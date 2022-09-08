#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 52, max_t = 5011, inf = 1011111111;

int n, r, f[max_n], s[max_n], sum[max_n];
long double dp[max_n][max_t], p[max_n];

bool check(long double tm) {
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= r; ++j) {
            long double d1 = f[i] + tm;
            long double d2 = s[i] + tm;
            if (j + f[i] <= r) {
                d1 = min(d1, f[i] + dp[i + 1][j + f[i]]);
            }
            if (j + s[i] <= r) {
                d2 = min(d2, s[i] + dp[i + 1][j + s[i]]);
            }
            dp[i][j] = min(tm, p[i] * d1 + (1 - p[i]) * d2);
            if (i == 0 && j == 0) {
                dp[i][j] = p[i] * d1 + (1 - p[i]) * d2;
            }
        }
    }
    return dp[0][0] <= tm;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        int P;
        cin >> f[i] >> s[i] >> P;
        p[i] = P;
        p[i] /= 100;
        //cout << f[i] << " " << s[i] << " " << p[i] << endl;
        sum[i + 1] = s[i];
        if (i) {
            sum[i] += sum[i - 1];
        }
    }
    sum[n] = r;
    for (int i = 0; i < n; ++i) {
        sum[i] = min(sum[i], r);
    }
    long double left = 0, right = inf;
    for (int it = 0; it < 80; ++it) {
        long double mid = (left + right) / 2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout.precision(15);
    cout << fixed << left << endl;
    return 0;
}