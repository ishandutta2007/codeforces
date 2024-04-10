#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 52;

int n, dp[max_n][max_n][max_n][max_n];
int sum[max_n][max_n];
string s[max_n];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < n; ++j) {
            sum[i][j] = s[i][j] == '#';
        }
    }
    for (int i = 1; i < n; ++i) {
        sum[0][i] += sum[0][i - 1];
        sum[i][0] += sum[i - 1][0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for (int len1 = 1; len1 <= n; ++len1) {
        for (int len2 = 1; len2 <= n; ++len2) {
            for (int i = 0; i + len1 <= n; ++i) {
                for (int j = 0; j + len2 <= n; ++j) {
                    int cnt = sum[i + len1 - 1][j + len2 - 1];
                    if (i) {
                        cnt -= sum[i - 1][j + len2 - 1];
                    }
                    if (j) {
                        cnt -= sum[i + len1 - 1][j - 1];
                    }
                    if (i && j) {
                        cnt += sum[i - 1][j - 1];
                    }
                    if (cnt == 0) {
                        continue;
                    }
                    int res = max(len1, len2);
                    if (len1 >= len2) {
                        for (int to = i; to < i + len1 - 1; ++to) {
                            res = min(res, dp[i][j][to][j + len2 - 1] + dp[to + 1][j][i + len1 - 1][j + len2 - 1]);
                        }
                    } else {
                        for (int to = j; to < j + len2 - 1; ++to) {
                            res = min(res, dp[i][j][i + len1 - 1][to] + dp[i][to + 1][i + len1 - 1][j + len2 - 1]);
                        }
                    }
                    dp[i][j][i + len1 - 1][j + len2 - 1] = res;
                }
            }
        }
    }
    cout << dp[0][0][n - 1][n - 1] << endl;
    return 0;
}