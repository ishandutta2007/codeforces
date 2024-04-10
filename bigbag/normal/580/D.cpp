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

const int max_n = 18, inf = 1111111111;

int n, m, k;
long long ans, a[max_n + 11], b[max_n + 11][max_n + 11], dp[(1 << max_n) + 11][max_n + 11];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (k--) {
        int u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        b[u][v] = c;
    }
    for (int i = 0; i < (1 << n); ++i) {
        int res = 0, poz;
        for (int j = 0; j < n; ++j) {
            if (get_bit(i, j)) {
                ++res;
                poz = j;
            }
        }
        if (res == 1) {
            dp[i][poz] = a[poz];
        }
        for (int j = 0; j < n; ++j) {
            if (get_bit(i, j)) {
                if (res == m) {
                    ans = max(ans, dp[i][j]);
                }
                for (int k = 0; k < n; ++k) {
                    if (!get_bit(i, k)) {
                        dp[i | (1 << k)][k] = max(dp[i | (1 << k)][k], dp[i][j] + a[k] + b[j][k]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}