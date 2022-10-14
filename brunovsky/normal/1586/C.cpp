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

    vector<string> G(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> G[i];
        G[i] = " " + G[i];
    }

    vector<vector<int>> block(N + 1, vector<int>(M + 1));
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            block[r][c] = r > 1 && c > 1 && G[r - 1][c] == 'X' && G[r][c - 1] == 'X';
        }
    }
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            block[r][c] += block[r - 1][c];
        }
    }
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            block[r][c] += block[r][c - 1];
        }
    }
    auto any = [&](int c1, int c2) {
        assert(c1 <= c2);
        return c1 < c2 && block[N][c2] - block[N][c1];
    };

    int Q;
    cin >> Q;
    while (Q--) {
        int c1, c2;
        cin >> c1 >> c2;
        if (any(c1, c2)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}