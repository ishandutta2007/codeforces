#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1e9;
const int MAX_N = 1e5 + 100;

int dp[MAX_N][2][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int t = 0; t < 3; ++t) {
                dp[i][j][t] = -1;
            }
        }
    }

    dp[0][0][0] = 0;
    dp[0][1][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int t = 0; t < 3; ++t) {
                dp[i + 1][j][t] = dp[i][j][t];
            }
        }
        int cur = s[i] - '0';
        for (int last = 0; last < 2; ++last) {
            if (dp[i][last][0] != -1) {
                if (cur != last) {
                    dp[i + 1][cur][0] = max(dp[i + 1][cur][0], dp[i][last][0] + 1);
                }
                if (1 - cur != last) {
                    dp[i + 1][1 - cur][1] = max(dp[i + 1][1 - cur][1], dp[i][last][0] + 1);
                }
            }
            if (dp[i][last][1] != -1) {
                if (cur != last) {
                    dp[i + 1][cur][2] = max(dp[i + 1][cur][2], dp[i][last][1] + 1);
                }
                if (1 - cur != last) {
                    dp[i + 1][1 - cur][1] = max(dp[i + 1][1 - cur][1], dp[i][last][1] + 1);
                }
            }
            if (dp[i][last][2] != -1) {
                if (cur != last) {
                    dp[i + 1][cur][2] = max(dp[i + 1][cur][2], dp[i][last][2] + 1);
                }
            }
        }
    }

    int ans = -1;
    for (int last = 0; last < 2; ++last) {
        for (int state = 1; state < 3; ++state) {
            ans = max(ans, dp[n][last][state]);
        }
    }
    cout << ans << endl;

    return 0;
}