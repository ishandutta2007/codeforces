#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> color(N, vector<int>(M));
    int C = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> color[i][j], color[i][j]--;
            C = max(C, color[i][j] + 1);
        }
    }
    vector<vector<array<int, 2>>> pos(C);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pos[color[i][j]].push_back({i, j});
        }
    }
    int64_t ans = 0;
    for (int c = 0; c < C; c++) {
        int S = pos[c].size();

        sort(begin(pos[c]), end(pos[c]), [&](auto a, auto b) { return a[0] < b[0]; });
        int64_t rows = 0;
        for (int i = 0; i < S; i++) {
            ans += 1LL * i * pos[c][i][0] - rows;
            rows += pos[c][i][0];
        }

        sort(begin(pos[c]), end(pos[c]), [&](auto a, auto b) { return a[1] < b[1]; });
        int64_t cols = 0;
        for (int i = 0; i < S; i++) {
            ans += 1LL * i * pos[c][i][1] - cols;
            cols += pos[c][i][1];
        }
    }
    cout << ans << '\n';
    return 0;
}