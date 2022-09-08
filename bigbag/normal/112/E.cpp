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

const int max_n = 6, max_m = 44, inf = 1011111111;

int n, m, dp[max_m][1 << max_n][1 << max_n];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int cnt_bit(int x) {
    int res = 0;
    while (x) {
        ++res;
        x = (x & (x - 1));
    }
    return res;
}

int get_mask(int x) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int ok = 0;
        if (i > 0 && get_bit(x, i - 1)) {
            ok = 1;
        }
        if (get_bit(x, i)) {
            ok = 1;
        }
        if (i + 1 < n && get_bit(x, i + 1)) {
            ok = 1;
        }
        if (ok) {
            res += (1 << i);
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            for (int k = 0; k < (1 << n); ++k) {
                dp[i][j][k] = inf;
            }
        }
    }
    int ok = (1 << n) - 1;
    for (int i = 0; i < (1 << n); ++i) {
        //cout << i << " " << get_mask(i) << "  " << cnt_bit(i) << endl;
        dp[0][i][get_mask(i)] = cnt_bit(i);
    }
    for (int i = 1; i < m; ++i) {
        for (int a = 0; a < (1 << n); ++a) {
            for (int b = 0; b < (1 << n); ++b) {
                for (int c = 0; c < (1 << n); ++c) {
                    int x = c | b;
                    if (x == ok) {
                        int y = get_mask(b) | a;
                        dp[i][b][y] = min(dp[i][b][y], dp[i - 1][a][c] + cnt_bit(b));
                        //cout << "(" << i << " " << b << " " << y << ") = " << dp[i][b][y] << endl;
                    }
                }
            }
        }
    }
    int ans = inf;
    for (int a = 0; a < (1 << n); ++a) {
        ans = min(ans, dp[m - 1][a][ok]);
    }
    cout << n * m - ans << endl;
    return 0;
}