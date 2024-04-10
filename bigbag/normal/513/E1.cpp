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

const int max_n = 33333, max_k = 222, inf = 1000000000;

int n, k, a[max_n];
pair<int, int> dp[max_n][max_k][2];

int myabs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    dp[0][1][0] = make_pair(0, a[0]);
    dp[0][1][1] = make_pair(0, a[0]);
    for (int i = 2; i <= k; ++i) {
        dp[0][i][0] = make_pair(-inf, inf);
        dp[0][i][1] = make_pair(-inf, -inf);
    }
    int ans = -inf;
    for (int i = 1; i < n; ++i) {
        for (int j = 2; j < k; ++j) {
            dp[i][j][0] = dp[i - 1][j][0];
            int sum = 0;
            for (int x = 1; x <= i; ++x) {
                sum += a[i - x + 1];
                if (dp[i - x][j - 1][0].first > -inf) {
                    if (dp[i][j][0].first - dp[i][j][0].second < dp[i - x][j - 1][0].first + myabs(sum - dp[i - x][j - 1][0].second) - sum) {
                        //cout << "!" << i << " " << j << endl;
                        dp[i][j][0].first = dp[i - x][j - 1][0].first + myabs(sum - dp[i - x][j - 1][0].second);
                        dp[i][j][0].second = sum;
                    }
                }
                if (dp[i - x][j - 1][1].first > -inf) {
                    if (dp[i][j][0].first - dp[i][j][0].second < dp[i - x][j - 1][1].first + myabs(sum - dp[i - x][j - 1][1].second) - sum) {
                        //cout << "!" << i << " " << j << endl;
                        dp[i][j][0].first = dp[i - x][j - 1][1].first + myabs(sum - dp[i - x][j - 1][1].second);
                        dp[i][j][0].second = sum;
                    }
                }
            }
            dp[i][j][1] = dp[i - 1][j][1];
            sum = 0;
            for (int x = 1; x <= i; ++x) {
                sum += a[i - x + 1];
                if (dp[i - x][j - 1][1].first > -inf) {
                    if (dp[i][j][1].first + dp[i][j][1].second < dp[i - x][j - 1][1].first + myabs(sum - dp[i - x][j - 1][1].second) + sum) {
                        dp[i][j][1].first = dp[i - x][j - 1][1].first + myabs(sum - dp[i - x][j - 1][1].second);
                        dp[i][j][1].second = sum;
                    }
                }
                if (dp[i - x][j - 1][0].first > -inf) {
                    if (dp[i][j][1].first + dp[i][j][1].second < dp[i - x][j - 1][0].first + myabs(sum - dp[i - x][j - 1][0].second) + sum) {
                        dp[i][j][1].first = dp[i - x][j - 1][0].first + myabs(sum - dp[i - x][j - 1][0].second);
                        dp[i][j][1].second = sum;
                    }
                }
            }
        }
        dp[i][1][0] = dp[i - 1][1][0];
        int sum = 0;
        for (int x = 1; x <= i + 1; ++x) {
            sum += a[i - x + 1];
            dp[i][1][0] = min(dp[i][1][0], make_pair(0, sum));
        }
        dp[i][1][1] = dp[i - 1][1][1];
        sum = 0;
        for (int x = 1; x <= i + 1; ++x) {
            sum += a[i - x + 1];
            dp[i][1][1] = max(dp[i][1][1], make_pair(0, sum));
        }


        dp[i][k][0] = dp[i - 1][k][0];
        sum = 0;
        for (int x = 1; x <= i; ++x) {
            sum += a[i - x + 1];
            if (dp[i - x][k - 1][0].first > -inf) {
                if (dp[i][k][0].first < dp[i - x][k - 1][0].first + myabs(sum - dp[i - x][k - 1][0].second)) {
                    //cout << "!" << i << " " << k << endl;
                    dp[i][k][0].first = dp[i - x][k - 1][0].first + myabs(sum - dp[i - x][k - 1][0].second);
                    dp[i][k][0].second = sum;
                }
            }
            if (dp[i - x][k - 1][1].first > -inf) {
                if (dp[i][k][0].first < dp[i - x][k - 1][1].first + myabs(sum - dp[i - x][k - 1][1].second)) {
                    //cout << "!" << i << " " << k << endl;
                    dp[i][k][0].first = dp[i - x][k - 1][1].first + myabs(sum - dp[i - x][k - 1][1].second);
                    dp[i][k][0].second = sum;
                }
            }
        }
        dp[i][k][1] = dp[i - 1][k][1];
        sum = 0;
        for (int x = 1; x <= i; ++x) {
            sum += a[i - x + 1];
            if (dp[i - x][k - 1][1].first > -inf) {
                if (dp[i][k][1].first < dp[i - x][k - 1][1].first + myabs(sum - dp[i - x][k - 1][1].second)) {
                    dp[i][k][1].first = dp[i - x][k - 1][1].first + myabs(sum - dp[i - x][k - 1][1].second);
                    dp[i][k][1].second = sum;
                }
            }
            if (dp[i - x][k - 1][0].first > -inf) {
                if (dp[i][k][1].first < dp[i - x][k - 1][0].first + myabs(sum - dp[i - x][k - 1][0].second)) {
                    dp[i][k][1].first = dp[i - x][k - 1][0].first + myabs(sum - dp[i - x][k - 1][0].second);
                    dp[i][k][1].second = sum;
                }
            }
        }

        /*cout << endl;
        for (int j = 1; j <= k; ++j) {
            cout << i << " " << j << " (" << dp[i][j][0].first << " " << dp[i][j][0].second << ") " << "  (" << dp[i][j][1].first << " " << dp[i][j][1].second << ")\n";
        }
        cout << endl;*/
        ans = max(ans, dp[i][k][0].first);
        ans = max(ans, dp[i][k][1].first);
    }
    cout << ans << endl;
    return 0;
}