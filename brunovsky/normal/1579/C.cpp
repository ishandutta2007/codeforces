#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        constexpr char STAR = '*';

        vector<vector<bool>> vis(n, vector<bool>(m));
        for (int i = n - 1; i >= k; i--) {
            for (int j = k; j + k < m; j++) {
                if (grid[i][j] == STAR) {
                    int largest = 0;
                    for (int s = 1; s <= min({i, j, m - j}); s++) {
                        if (grid[i - s][j - s] == STAR && grid[i - s][j + s] == STAR) {
                            largest++;
                        } else {
                            break;
                        }
                    }
                    if (largest >= k) {
                        vis[i][j] = true;
                        for (int s = 1; s <= largest; s++) {
                            vis[i - s][j - s] = true;
                            vis[i - s][j + s] = true;
                        }
                    }
                }
            }
        }

        bool busted = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                busted |= grid[i][j] == STAR && !vis[i][j];
            }
        }

        if (busted) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}