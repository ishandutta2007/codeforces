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
        int N, M;
        cin >> N >> M;
        vector<vector<int>> a(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> a[i][j];
            }
        }
        int u = 0, v = 0;
        for (int i = 0; i < N; i++) {
            int m = a[i][M - 1];
            int k = -1;
            for (int j = M - 2; j >= 0; j--) {
                if (m < a[i][j]) {
                    k = j;
                }
                m = min(m, a[i][j]);
            }
            if (k == -1) {
                continue;
            }
            u = k;
            for (int j = u + 1; j < M; j++) {
                if (a[i][u] > a[i][j]) {
                    v = j;
                }
            }
            for (int x = 0; x < N; x++) {
                swap(a[x][u], a[x][v]);
            }
            break;
        }
        bool ok = true;
        for (int i = 0; i < N; i++) {
            ok &= is_sorted(begin(a[i]), end(a[i]));
        }
        if (ok) {
            cout << u + 1 << ' ' << v + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}