#include <cstdio>
#include <cmath>

#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

const int max_n = 2e3 + 100;

int n;
int t[max_n];
ll c[max_n];
ll dp[max_n][2 * max_n];
int f[max_n][2 * max_n];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i] >> c[i];
    dp[0][n] = 0;
    f[0][n] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= 2 * n; ++j)
            if (f[i][j]) {
                int cc = min(2 * n, j + t[i + 1]);
                if (!f[i + 1][cc] || dp[i][j] + c[i + 1] < dp[i + 1][cc]) {
                    f[i + 1][cc] = 1;
                    dp[i + 1][cc] = dp[i][j] + c[i + 1];
                }
                if (!f[i + 1][j - 1] || dp[i][j] < dp[i + 1][j - 1]) {
                    f[i + 1][j - 1] = 1;
                    dp[i + 1][j - 1] = dp[i][j];
                }
            }
    ll ans = -1;
    for (int i = n; i <= 2 * n; ++i)
        if (f[n][i]) 
            if (ans == -1 || dp[n][i] < ans)
                ans = dp[n][i];
    cout << ans << endl;
    return 0;
}