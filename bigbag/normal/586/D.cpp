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

const int max_n = 111, inf = 1111111111;

int t, n, k, dp[max_n][3], a[max_n], l[max_n], r[max_n];
string s[3];

bool ok(int x, int y) {
    for (int i = 0; i < k; ++i) {
        if (y == a[i]) {
            if (l[i] <= x && x <= r[i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s[0] >> s[1] >> s[2];
        memset(dp, 0, sizeof(dp));
        int cnt = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == 's') {
                    dp[j][i] = 1;
                } else if (s[i][j] != '.') {
                    int ll = j;
                    while (j < n && s[i][j] == s[i][ll]) {
                        ++j;
                    }
                    --j;
                    int rr = j;
                    a[cnt] = i;
                    l[cnt] = ll;
                    r[cnt] = rr;
                    ++cnt;
                }
            }
        }
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (dp[i][j]) {
                    if (ok(i + 1, j) && ok(i + 2, j) && ok(i + 3, j)) {
                        dp[i + 1][j] = 1;
                    }
                    int q = j - 1;
                    if (q >= 0) {
                        if (ok(i + 1, j) && ok(i + 1, q) && ok(i + 2, q) && ok(i + 3, q)) {
                            dp[i + 1][q] = 1;
                        }
                    }
                    q = j + 1;
                    if (q < 3) {
                        if (ok(i + 1, j) && ok(i + 1, q) && ok(i + 2, q) && ok(i + 3, q)) {
                            dp[i + 1][q] = 1;
                        }
                    }
                }
            }
            for (int j = 0; j < k; ++j) {
                l[j] -= 2;
                r[j] -= 2;
            }
        }
        if (dp[n - 1][0] || dp[n - 1][1] || dp[n - 2][2]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}