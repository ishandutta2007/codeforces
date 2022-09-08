/**
 *  created: 24/05/2021, 17:49:59
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, mod = 998244353;

int n, dp[max_n];
int all[max_n];

void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int x = 1; x < max_n; ++x) {
        for (int y = x; y < max_n; y += x) {
            ++all[y];
        }
    }
    cin >> n;
    dp[0] = 1;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = all[i];
        inc(dp[i], sum);
        inc(sum, dp[i]);
    }
    cout << dp[n] << endl;
    return 0;
}