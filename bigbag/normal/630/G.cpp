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

const int max_n = 555;

long long n, ans, dp[max_n][7][7];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 5; ++j) {
            for (int k = 0; k <= 3; ++k) {
                for (int q = 0; q <= j; ++q) {
                    for (int w = 0; w <= k; ++w) {
                        dp[i][j][k] += dp[i - 1][j - q][k - w];
                    }
                }
            }
        }
    }
    ans = dp[n][5][3];
    cout << ans << endl;
    return 0;
}