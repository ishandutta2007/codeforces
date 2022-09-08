/**
 *  created: 10/06/2022, 19:51:12
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int t, n, m;
string s[max_n];

int get_val(int x, int y, int mask) {
    if (mask % 2) {
        x *= -1;
    }
    mask /= 2;
    if (mask % 2) {
        y *= -1;
    }
    return x + y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        vector<int> mx(4, -inf);
        pair<int, pair<int, int>> ans(inf, {inf, inf});
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == 'B') {
                    for (int mask = 0; mask < 4; ++mask) {
                        mx[mask] = max(mx[mask], get_val(i, j, mask));
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int res = -inf;
                for (int mask = 0; mask < 4; ++mask) {
                    res = max(res, get_val(i, j, 3 ^ mask) + mx[mask]);
                }
                ans = min(ans, {res, {i, j}});
            }
        }
        cout << ans.second.first + 1 << " " << ans.second.second + 1 << "\n";
    }
    return 0;
}