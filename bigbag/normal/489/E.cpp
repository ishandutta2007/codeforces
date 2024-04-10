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

const int max_n = 1111, inf = 1111111111;
const double eps = 1e-9;

int n, l, x[max_n], y[max_n], p[max_n];
double dp[max_n], a[max_n][max_n];
vector<int> ans;

bool check(double v) {
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = inf;
        for (int j = 0; j < i; ++j) {
            if (dp[j] + a[j][i] - v * y[i] < dp[i]) {
                dp[i] = dp[j] + a[j][i] - v * y[i];
                p[i] = j;
            }
        }
    }
    if (dp[n] <= 0) {
        return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> l;
    x[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            a[i][j] = sqrt(abs(x[j] - x[i] - l));
        }
    }
    double l = 0, r = inf;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    check(l);
    while (n) {
        ans.push_back(n);
        n = p[n];
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
    return 0;
}