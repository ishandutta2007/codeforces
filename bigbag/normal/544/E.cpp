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

const int max_n = 22, inf = 1111111111;

int n, m, dp[1 << max_n], a[max_n][max_n], nmask[max_n][max_n], res[max_n][max_n];
string s[max_n];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int poz = 0; poz < n; ++poz) {
        for (int i = 0; i < m; ++i) {
            int mx = 0;
            for (int j = 0; j < n; ++j) {
                if (s[poz][i] == s[j][i]) {
                    res[poz][i] += a[j][i];
                    mx = max(mx, a[j][i]);
                    nmask[poz][i] |= (1 << j);
                }
            }
            res[poz][i] -= mx;
        }
    }
    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int poz;
        for (int i = 0; i < n; ++i) {
            if (get_bit(mask, i)) {
                poz = i;
            }
        }
        dp[mask] = inf;
        for (int i = 0; i < m; ++i) {
            dp[mask] = min(dp[mask], a[poz][i] + dp[mask ^ (1 << poz)]);
            dp[mask] = min(dp[mask], res[poz][i] + dp[mask ^ (mask & nmask[poz][i])]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}