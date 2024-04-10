/**
 *  created: 24/08/2021, 17:43:35
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 4000111;

int n, mod, dp[max_n], sum[max_n];

void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

void dec(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> mod;
    dp[n] = 1;
    sum[n] = 1;
    for (int i = n - 1; i > 0; --i) {
        dp[i] = sum[i + 1];
        for (int x = 2; i * x <= n; ++x) {
            inc(dp[i], sum[i * x]);
            if (i * x + x <= n) {
                dec(dp[i], sum[i * x + x]);
            }
        }
        sum[i] = sum[i + 1];
        inc(sum[i], dp[i]);
    }
    cout << dp[1] << "\n";
    return 0;
}