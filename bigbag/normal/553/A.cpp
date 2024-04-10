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

const int max_n = 1111, inf = 1000000007;

int n, sum[max_n], a[max_n], dp[max_n][max_n], c[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < max_n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % inf;
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = a[i] + sum[i - 1];
    }
    dp[0][0] = 1;
    for (int i = 0; i < sum[n - 1]; ++i) {
        for (int j = 0; j <= i && j <= n; ++j) {
            //cout << i << " " << j << " - " << dp[i][j] << endl;
            int x = i;
            if (j > 0) {
                x = i - sum[j - 1];
            }
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % inf;
            if (x >= a[j] - 1) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + (1LL * dp[i][j] * c[x][a[j] - 1]) % inf) % inf;
            }
        }
    }
    cout << dp[sum[n - 1]][n] << endl;
    return 0;
}