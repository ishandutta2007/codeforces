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

const int max_n = 111;
const long long inf = 1111111111111111111LL;

int n, m, k, a[max_n], cost[max_n][max_n];
long long dp[max_n][max_n][max_n];

void update(int i, int j, int k, long long x) {
    if (dp[i][j][k] == -1) {
        dp[i][j][k] = x;
    } else {
        dp[i][j][k] = min(dp[i][j][k], x);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cost[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    if (a[0] == 0) {
        for (int i = 0; i < m; ++i) {
            dp[0][i][1] = cost[0][i];
        }
    } else {
        --a[0];
        dp[0][a[0]][1] = 0;
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int last = 0; last < m; ++last) {
            for (int cnt = 1; cnt <= k; ++cnt) {
                if (dp[i][last][cnt] == -1) {
                    continue;
                }
                for (int col = 0; col < m; ++col) {
                    if (a[i + 1] == 0 || a[i + 1] == col + 1) {
                        update(i + 1, col, cnt + (last != col), dp[i][last][cnt] + (a[i + 1] == 0) * cost[i + 1][col]);
                    }
                }
            }
        }
    }
    long long ans = inf;
    for (int i = 0; i < m; ++i) {
        if (dp[n - 1][i][k] != -1) {
            ans = min(ans, dp[n - 1][i][k]);
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}