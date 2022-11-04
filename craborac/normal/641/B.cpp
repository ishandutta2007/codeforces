#include <bits/stdc++.h>

using namespace std;

int n, m, q;
pair<int, int> a[10000];
int res[100][100];

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 3) {
            int x, y, val;
            cin >> x >> y >> val;
            a[i] = {x, -1};
            x--; y--;
            for (int j = i - 1; j >= 0; j--) {
                if (a[j].second == -1) {
                    continue;
                }
                if (a[j].second == 1 && x == a[j].first) {
                    y = (y + 1) % m;
                }
                if (a[j].second == 2 && y == a[j].first) {
                    x = (x + 1) % n;
                }
            }
            res[x][y] = val;
        } else {
            int x;
            cin >> x;
            a[i] = {x - 1, t};
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] << " \n"[j == m - 1];
        }
    }
}