#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

bool same(int x, int y, int z, int w) {
    if (x == 0) {
        if (y != 0) {
            swap(x, y);
        } else if (z != 0) {
            swap(x, z);
        } else if (w != 0) {
            swap(x, w);
        } else {
            return false;
        }
    }
    if (y != 0 && x != y) {
        return false;
    }
    if (z != 0 && x != z) {
        return false;
    }
    if (w != 0 && x != w) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    const int ANY = 0;
    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    set<array<int, 2>> corners;

    auto add_refresh = [&](int i, int j) {
        if (0 <= i && i + 1 < N && 0 <= j && j + 1 < M) {
            int x = a[i][j];
            int y = a[i][j + 1];
            int z = a[i + 1][j];
            int w = a[i + 1][j + 1];
            if (same(x, y, z, w)) {
                corners.insert({i, j});
            }
        }
    };
    auto rem_refresh = [&](int i, int j) {
        for (int x : {i - 1, i, i + 1}) {
            for (int y : {j - 1, j, j + 1}) {
                corners.erase({x, y});
            }
        }
        for (int x : {i, i + 1}) {
            for (int y : {j, j + 1}) {
                a[x][y] = 0;
            }
        }
        for (int x : {i - 1, i, i + 1}) {
            for (int y : {j - 1, j, j + 1}) {
                add_refresh(x, y);
            }
        }
    };
    auto get_color = [&](int i, int j) {
        int color = 0;
        for (int x : {i, i + 1}) {
            for (int y : {j, j + 1}) {
                if (a[x][y]) {
                    color = a[x][y];
                }
            }
        }
        assert(color != 0);
        return color;
    };

    for (int i = 0; i + 1 < N; i++) {
        for (int j = 0; j + 1 < M; j++) {
            add_refresh(i, j);
        }
    }

    vector<array<int, 3>> paints;
    while (!corners.empty()) {
        auto [i, j] = *corners.begin();
        int color = get_color(i, j);
        rem_refresh(i, j);
        paints.push_back({i, j, color});
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] != 0) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    reverse(begin(paints), end(paints));
    cout << paints.size() << '\n';
    for (auto [x, y, c] : paints) {
        cout << x + 1 << ' ' << y + 1 << ' ' << c << '\n';
    }

    return 0;
}