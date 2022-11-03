#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

const long long MAX_DIST = 1e18;
const int MAX_DIST_LOG = 59;

const int MAX_N = 500;

using TMask = bitset<MAX_N>;

int n;

TMask g[2][MAX_DIST_LOG + 1][MAX_N];
TMask gr[2][MAX_DIST_LOG + 1][MAX_N];

void Solve() {
    for (int l = 1; l <= MAX_DIST_LOG; ++l) {
        for (int t = 0; t < 2; ++t) {
            for (int v = 0; v < n; ++v) {
                for (int u = 0; u < n; ++u) {
                    g[t][l][v][u] = (g[t][l - 1][v] & gr[1 - t][l - 1][u]).any();
                    gr[t][l][v][u] = (g[t][l - 1][u] & gr[1 - t][l - 1][v]).any();
                }
            }
        }
    }
    {
        TMask mask;
        long long length = 0;
        mask[0] = true;
        int t = 0;
        for (int l = MAX_DIST_LOG; l >= 0; --l) {
            TMask newMask;
            for (int v = 0; v < n; ++v) {
                if (mask[v]) {
                    newMask |= g[t][l][v];
                }
            }
            if (newMask.any()) {
                mask = newMask;
                length += (1LL << l);
                t = 1 - t;
            }
        }
        if (length > MAX_DIST) {
            cout << -1 << endl;
        } else {
            cout << length << endl;
        }
    }
}

bool Read() {
    int m;
    if (!(cin >> n >> m)) {
        return false;
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= MAX_DIST_LOG; ++j) {
            for (int v = 0; v < n; ++v) {
                g[i][j][v].reset();
                gr[i][j][v].reset();
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int v, u, t;
        cin >> v >> u >> t;
        --v;
        --u;
        g[t][0][v][u] = true;
        gr[t][0][u][v] = true;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}