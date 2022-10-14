#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> cost(N, vector<int>(M));
    vector<array<int, 2>> paths;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cost[i][j];
            paths.push_back({i, j});
        }
    }
    sort(begin(paths), end(paths), [&](const array<int, 2>& a, const array<int, 2>& b) {
        return cost[a[0]][a[1]] < cost[b[0]][b[1]];
    });
    vector<vector<int>> runner(N, vector<int>(M, -1));
    vector<vector<int>> pathof(N, vector<int>(M));
    vector<int> checkpoint(M);
    for (int r = 0; r < M; r++) {
        auto [i, j] = paths[r];
        runner[i][j] = r, checkpoint[r] = i, pathof[i][r] = j;
    }
    for (int i = 0; i < N; i++) {
        for (int r = 0, j = 0; r < M; r++) {
            if (checkpoint[r] != i) {
                while (runner[i][j] != -1)
                    j++;
                runner[i][j] = r, pathof[i][r] = j++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int r = 0; r < M; r++) {
            cout << (r ? " " : "") << cost[i][pathof[i][r]];
        }
        cout << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}