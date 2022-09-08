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

const int max_n = 111, inf = 1000000008;

long long n, dp[max_n][max_n][4][2], ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int N = n;
    n = 2 * n - 2;
    dp[1][1][0][0] = 1;
    dp[1][1][1][0] = 1;
    dp[1][1][2][0] = 1;
    dp[1][1][3][0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int c = 0; c < 4; ++c) {
                for (int f = 0; f < 2; ++f) {
                    //cout << i << " " << j << " " << c << " " << f << " : " << dp[i][j][c][f] << endl;
                    for (int nc = 0; nc < 4; ++nc) {
                        int nlen = 1;
                        if (c == nc) {
                            nlen += j;
                        }
                        int ff = f;
                        if (nlen > N) {
                            continue;
                        }
                        if (nlen == N) {
                            ff = 1;
                        }
                        dp[i + 1][nlen][nc][ff] += dp[i][j][c][f];
                    }
                }
            }
        }
    }
    for (int j = 1; j <= n; ++j) {
        ans += dp[n][j][0][1];
        ans += dp[n][j][1][1];
        ans += dp[n][j][2][1];
        ans += dp[n][j][3][1];
    }
    cout << ans << endl;
    return 0;
}