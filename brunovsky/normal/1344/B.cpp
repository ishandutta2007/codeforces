#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int N) { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return i == next[i] && size[i] == 1; }
    bool root(int i) { return find(i) == i; }
    void reroot(int u) {
        if (u != find(u)) {
            size[u] = size[find(u)];
            next[u] = next[find(u)] = u;
        }
    }

    int find(int i) {
        while (i != next[i]) {
            i = next[i] = next[next[i]];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            next[j] = i;
            size[i] += size[j];
            S--;
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    disjoint_set dsu(N + M);
    auto dsu_row = [&](int r) { return r; };
    auto dsu_col = [&](int c) { return c + N; };
    vector<vector<int>> by_row(N), by_col(M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '#') {
                dsu.join(dsu_row(i), dsu_col(j));
                by_row[i].push_back(j);
                by_col[j].push_back(i);
            }
        }
    }

    // No black cells
    if (dsu.S == N + M) {
        cout << 0 << endl;
        return 0;
    }

    int empty_rows = 0;
    int empty_cols = 0;

    for (int i = 0; i < N; i++) {
        empty_rows += by_row[i].empty();
        if (!by_row[i].empty()) {
            int j1 = by_row[i].front();
            int j2 = by_row[i].back();
            for (int j = j1; j <= j2; j++) {
                if ('#' != board[i][j]) {
                    goto busted;
                }
            }
        }
    }
    for (int j = 0; j < M; j++) {
        empty_cols += by_col[j].empty();
        if (!by_col[j].empty()) {
            int i1 = by_col[j].front();
            int i2 = by_col[j].back();
            debug(j, i1, i2);
            for (int i = i1; i <= i2; i++) {
                if ('#' != board[i][j]) {
                    goto busted;
                }
            }
        }
    }

    if (empty_rows && !empty_cols) {
        goto busted;
    }
    if (!empty_rows && empty_cols) {
        goto busted;
    }

    cout << dsu.S - empty_rows - empty_cols << endl;
    return 0;

busted:
    cout << -1 << endl;
    return 0;
}