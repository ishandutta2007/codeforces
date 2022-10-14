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
        int N, M, r, c;
        cin >> N >> M >> r >> c, r--, c--;

        vector<string> grid(N);
        int blacks = 0;
        for (int i = 0; i < N; i++) {
            cin >> grid[i];
            blacks += count(begin(grid[i]), end(grid[i]), 'B');
        }

        if (blacks == 0) {
            cout << -1 << '\n';
        } else if (grid[r][c] == 'B') {
            cout << 0 << '\n';
        } else {
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                cnt += grid[i][c] == 'B';
            }
            for (int j = 0; j < M; j++) {
                cnt += grid[r][j] == 'B';
            }
            cout << (cnt ? 1 : 2) << '\n';
        }
    }
    return 0;
}