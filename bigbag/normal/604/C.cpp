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

const int max_n = 111111, inf = 1111111111;

int n, a[max_n], nxt[max_n][2], dp[max_n][2][3];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    dp[0][a[0]][0] = 1;
    dp[0][a[0] ^ 1][0] = 0;
    dp[0][a[0] ^ 1][1] = 1;
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        for (int x = 0; x < 2; ++x) {
            int to = x ^ 1;
            dp[i + 1][x][2] = max(dp[i + 1][x][2], dp[i][x][2]);
            if (to == a[i + 1]) {
                dp[i + 1][to][2] = max(dp[i + 1][to][2], dp[i][x][2] + 1);
            }
            dp[i + 1][x][2] = max(dp[i + 1][x][2], dp[i][x][1]);
            if (to == a[i + 1]) {
                dp[i + 1][to][2] = max(dp[i + 1][to][2], dp[i][x][1] + 1);
            }
            dp[i + 1][x][1] = max(dp[i + 1][x][1], dp[i][x][1]);
            if (to != a[i + 1]) {
                dp[i + 1][to][1] = max(dp[i + 1][to][1], dp[i][x][1] + 1);
            }

            dp[i + 1][x][0] = max(dp[i + 1][x][0], dp[i][x][0]);
            if (to == a[i + 1]) {
                dp[i + 1][to][0] = max(dp[i + 1][to][0], dp[i][x][0] + 1);
            }
            dp[i + 1][x][1] = max(dp[i + 1][x][1], dp[i][x][0]);
            if (to != a[i + 1]) {
                dp[i + 1][to][1] = max(dp[i + 1][to][1], dp[i][x][0] + 1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int x = 0; x < 2; ++x) {
            ans = max(ans, dp[i][x][0]);
            ans = max(ans, dp[i][x][1]);
            ans = max(ans, dp[i][x][2]);
            //cout << i << " " << x << " : " << dp[i][x][0] << " " << dp[i][x][1] << " " << dp[i][x][2] << endl;
        }
    }
    cout << ans << endl;
    return 0;
}