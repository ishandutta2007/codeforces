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

const int max_n = 111, mod = 1000000007;

int n, k, d, dp[max_n][2], f[max_n];

void get_dp(int n) {
    if (f[n]) {
        return;
    }
    f[n] = 1;
    if (n == 0) {
        dp[n][0] = 1;
    }
    for (int i = 1; i <= min(n, k); ++i) {
        get_dp(n - i);
        if (i < d) {
            dp[n][0] += dp[n - i][0];
        }
        if (i >= d) {
            dp[n][1] += dp[n - i][0];
            dp[n][1] %= mod;
        }
        dp[n][1] += dp[n - i][1];
        dp[n][0] %= mod;
        dp[n][1] %= mod;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> d;
    get_dp(n);
    cout << dp[n][1] << endl;
    return 0;
}