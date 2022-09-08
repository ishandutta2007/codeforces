/**
 *  created: 22/01/2022, 17:16:19
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int t, n, a[max_n][max_n], f[max_n][max_n], val[max_n][max_n];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < n;
}

void proc(int x, int y) {
    if (f[x][y]) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is_in(nx, ny)) {
                a[nx][ny] ^= 1;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> val[i][j];
                a[i][j] = 0;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[i][j] = 1 - a[i - 1][j];
                proc(i, j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans ^= (f[i][j] * val[i][j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}