/**
 *  created: 12/09/2021, 17:51:29
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 333, inf = 1000111222;

int t, n, m, ans[max_n][max_n];
pair<int, int> a[max_n * max_n];

void nxt(int &x, int &y) {
    ++y;
    if (y == m) {
        ++x;
        y = 0;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n * m; ++i) {
            cin >> a[i].first;
            a[i].second = -i;
        }
        sort(a, a + n * m);
        int x = 0, y = 0;
        for (int i = 0; i < n * m; ) {
            int pos = i;
            int sx = x, sy = y;
            while (i + 1 < n * m && a[pos].first == a[i + 1].first) {
                ++i;
                nxt(x, y);
            }
            ++i;
            if (sx == x) {
            } else {
                reverse(a + pos, a + i);
                reverse(a + pos, a + pos + m - sy);
                reverse(a + pos + m - sy, a + i - y - 1);
                reverse(a + i - y - 1, a + i);
            }
            nxt(x, y);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = -a[i * m + j].second;
                //cout << ans[i][j] << " ";
            }
            //cout << endl;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int x = 0; x < m; ++x) {
                for (int y = x + 1; y < m; ++y) {
                    res += ans[i][x] < ans[i][y];
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}