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

const int max_n = 2222, mod = 1000000007;

long long n, h, a[max_n], dp[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> h;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (a[0] == h) {
        dp[0][0] = 1;
    }
    if (a[0] == h - 1) {
        dp[0][0] = 1;
        dp[0][1] = 1;
    }
    for (int i = 1; i < n; ++i) {
        long long x = h - a[i];
        if (x >= 0) {
            dp[i][x] += dp[i - 1][x];
            if (x > 0) {
                dp[i][x] += dp[i - 1][x - 1];
                dp[i][x - 1] += dp[i - 1][x] * x;
                dp[i][x - 1] += dp[i - 1][x - 1] * x;
                dp[i][x - 1] %= mod;
            }
            dp[i][x] %= mod;
        }
    }
    cout << dp[n - 1][0] << endl;
    return 0;
}