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

const long long max_n = 111111, inf = 1000000007;

long long l, r, n, k, dp[max_n][2], sum[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    dp[1][0] = 1;
    dp[1][1] = 0;
    if (k == 1) {
        dp[1][1] = 1;
    }
    for (int i = 2; i < max_n; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % inf;
        dp[i][1] = 0;
        if (i == k) {
            dp[i][1] = 1;
        }
        if (i > k) {
            dp[i][1] = dp[i - k][0] + dp[i - k][1];
        }
        //cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    for (int i = 1; i < max_n; ++i) {
        sum[i] = (sum[i - 1] + dp[i][0] + dp[i][1]) % inf;
    }
    while (n--) {
        cin >> l >> r;
        long long x = sum[r] - sum[l - 1];
        while (x < 0) {
            x += inf;
        }
        cout << x << endl;
    }
    return 0;
}