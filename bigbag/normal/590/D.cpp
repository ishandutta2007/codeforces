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

const int max_n = 155, inf = 2111111111;

int n, k, s, a[max_n], dp[2][max_n][max_n * max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q1 = 0, q2 = 1;
    dp[q1][0][0] = 0;
    dp[q1][1][0] = a[0];
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j <= i + 2; ++j) {
            for (int q = 0; q <= (i + 1) * (i + 1); ++q) {
                dp[q2][j][q] = inf;
            }
        }
        for (int j = 0; j <= i + 1; ++j) {
            for (int q = 0; q <= i * i; ++q) {
                dp[q2][j][q] = min(dp[q2][j][q], dp[q1][j][q]);
                dp[q2][j + 1][q + i + 1 - j] = min(dp[q2][j + 1][q + i + 1 - j], dp[q1][j][q] + a[i + 1]);
            }
        }
        swap(q1, q2);
    }
    int ans = inf;
    for (int i = 0; i <= s && i <= (n - 1) * (n - 1); ++i) {
        ans = min(ans, dp[q1][k][i]);
    }
    cout << ans << endl;
    return 0;
}