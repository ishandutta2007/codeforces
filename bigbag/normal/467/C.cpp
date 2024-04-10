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

const int max_n = 5111, inf = 1111111111;

int n, m, k;
long long a[max_n], sum[max_n], dp[max_n][max_n];

long long get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    if (m == 1) {
        dp[0][1] = a[0];
    }
    for (int i = 1; i < n; ++i) {
        dp[i][0] = 0;
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            int l = i + 1 - m;
            if (l > 0 && dp[l - 1][j - 1] != -1) {
                dp[i][j] = max(dp[i][j], dp[l - 1][j - 1] + get_sum(l, i));
            }
            if (l == 0 && j == 1) {
                dp[i][j] = max(dp[i][j], get_sum(l, i));
            }
        }
    }
    cout << dp[n - 1][k] << endl;
    return 0;
}