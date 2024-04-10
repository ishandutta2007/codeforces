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

const int max_n = 4444, inf = 1000000007;

int n, ans, dp[max_n], c[max_n][max_n];

void get_all_c() {
    for (int i = 0; i < max_n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % inf;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_c();
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i; ++j) {
            int x = (1LL * c[i - 1][j - 1] * dp[i - j]) % inf;
            dp[i] += x;
            dp[i] %= inf;
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans = (ans + (1LL * c[n][i] * dp[n - i]) % inf) % inf;
    }
    cout << ans << endl;
    return 0;
}