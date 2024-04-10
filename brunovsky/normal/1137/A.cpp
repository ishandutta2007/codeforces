#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int a[1001][1001], ans[1001][1001];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<array<int, 3>> pos;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            pos.push_back({a[i][j], i, j});
        }
    }

    auto compute = [&]() {
        int S = N * M;
        vector<int> row(N), col(M), rowin(N), colin(M);

        for (int L = 0, R = 1; L < S; L = R++) {
            while (R < S && pos[L][0] == pos[R][0])
                R++;
            for (int i = L; i < R; i++) {
                auto [x, r, c] = pos[i];
                row[r] += !rowin[r];
                col[c] += !colin[c];
                rowin[r] = colin[c] = 1;
            }
            for (int i = L; i < R; i++) {
                auto [x, r, c] = pos[i];
                ans[r][c] += max(row[r], col[c]);
                rowin[r] = colin[c] = 0;
            }
        }
    };

    sort(begin(pos), end(pos));
    compute();
    reverse(begin(pos), end(pos));
    compute();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j] - 1 << " \n"[j + 1 == M];
        }
    }

    return 0;
}