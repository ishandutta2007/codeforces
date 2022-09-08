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

const int max_n = 2002, inf = 1000000007;

int n, k, dp[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 1; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int q = 1; j * q <= n; ++q) {
                dp[i + 1][j * q] = (dp[i + 1][j * q] + dp[i][j]) % inf;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + dp[k][i]) % inf;
    }
    cout << ans << endl;
    return 0;
}