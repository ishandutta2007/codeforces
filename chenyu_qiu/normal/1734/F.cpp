#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    // int n;
    // cin >> n;
    
    i64 n, m;
    cin >> n >> m;
    swap(n, m);

    i64 f[2][2][2] = {};
    f[0][0][0] = 1;

    for (int i = 0; i <= 61; ++i) {
        i64 g[2][2][2] = {};
        for (int x = 0; x < 2; ++x) {
            for (int y = 0; y < 2; ++y) {
                for (int c = 0; c < 2; ++c) {
                    for (int z = 0; z < 2; ++z) {
                        int x1 = (n >> i & 1) ? (z == 0 ? 1 : x) : (z == 1 ? 0 : x);
                        int y1 = ((m >> i & 1) + z + y) >= 2;
                        int c1 = c ^ y1;
                        g[x1][y1][c1] += f[x][y][c];
                    }
                }
            }
        }
        memcpy(f, g, sizeof f);
    }
    
    cout << f[1][0][__builtin_parityll(m) ^ 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}