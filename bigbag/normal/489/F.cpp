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

const int max_n = 505, inf = 1111111111;

int n, m, mod, f[5555], q1 = 0, q2 = 1, a[max_n], b[5];
int dp[2][max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 5555; ++i) {
        f[i] = (i * (i - 1)) / 2;
    }
    cin >> n >> m >> mod;
    for (int i = 1; i <= m; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            a[j] += s[j] - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        ++b[2 - a[i]];
    }
    dp[q1][b[2]] = 1;
    //cout << b[1] << " " << b[2] << endl;
    for (int i = m; i < n; ++i) {
        int x = 2 * (n - i);
        for (int b = 0; b <= n && 2 * b <= x; ++b) {
            dp[q2][b] = 0;
        }
        for (int b = 0; b <= n && 2 * b <= x; ++b) {
            int a = x - b * 2;
            if (a <= n) {
                if (a >= 2) {
                    dp[q2][b] = (dp[q2][b] + f[a] * ((long long) dp[q1][b])) % mod;
                }
                if (a > 0 && b > 0) {
                    dp[q2][b - 1] = (dp[q2][b - 1] + a * b * ((long long) dp[q1][b])) % mod;
                }
                if (b >= 2) {
                    dp[q2][b - 2] = (dp[q2][b - 2] + f[b] * ((long long) dp[q1][b])) % mod;
                }
            }
        }
        swap(q1, q2);
    }
    cout << dp[q1][0] << endl;
    return 0;
}