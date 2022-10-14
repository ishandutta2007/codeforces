#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

void setmin(int& a, int b) { a = min(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int M;
        cin >> M;
        vector<vector<int>> arr(2, vector<int>(M + 1));
        for (int r = 0; r < 2; r++) {
            for (int c = 0; c < M; c++) {
                cin >> arr[r][c];
            }
        }
        const int inf = 1.05e9, ninf = -inf;

        vector<vector<int>> add(2, vector<int>(M + 1, ninf));
        vector<vector<int>> sub(2, vector<int>(M + 1, ninf));
        for (int c = M - 1; c >= 0; c--) {
            add[0][c] = max(add[0][c + 1], arr[0][c] + c);
            add[1][c] = max(add[1][c + 1], arr[1][c] + c);
            sub[0][c] = max(sub[0][c + 1], arr[0][c] - c);
            sub[1][c] = max(sub[1][c + 1], arr[1][c] - c);
        }
        debug(add[1]);

        auto calc = [&](int s, int c, int t) {
            int dist = M - 1 - c;
            t = t + dist + max(0, sub[s][c + 1] - t + c + 1);
            t = max(t, arr[!s][M - 1]) + 1;
            if (c < M - 1) {
                t = t + dist + max(0, add[!s][c] - t - (M - 1) + 1);
            }
            return t;
        };

        int t = 0, ans = inf;
        for (int c = 0; c < M; c++) {
            int s = c % 2;
            debug(c, t, calc(s, c, t));
            setmin(ans, calc(s, c, t));
            t = max(t, arr[!s][c]) + 1;
            t = max(t, arr[!s][c + 1]) + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}