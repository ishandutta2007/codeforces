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
        int N;
        cin >> N;
        vector<int> P(N + 1);
        vector<int> where(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> P[i];
            where[P[i]] = i;
        }

        bool busted = false;
        for (int i = 1; i <= N; i++) {
            if ((where[i] % 2) != (i % 2)) {
                busted = true;
                break;
            }
        }
        if (busted) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> reversals;

        auto rev = [&](int j) {
            assert(j >= 1 && (j % 2) == 1);
            if (j == 1) {
                return;
            }
            reversals.push_back(j);
            for (int x = 1, y = j; x < y; x++, y--) {
                where[P[x]] = y, where[P[y]] = x;
                swap(P[x], P[y]);
            }
        };

        for (int v = N; v >= 3; v -= 2) {
            int u = v - 1;
            if (where[u] != u || where[v] != v) {
                rev(where[v]), rev(where[u] - 1), rev(where[u] + 1), rev(3), rev(v);
            }
        }

        for (int i = 1; i <= N; i++) {
            if (where[i] != i) {
                busted = true;
                break;
            }
        }
        if (busted) {
            cout << -1 << '\n';
            continue;
        }

        int R = reversals.size();
        cout << R << '\n';
        for (int i = 0; i < R; i++) {
            cout << reversals[i] << " \n"[i + 1 == R];
        }
    }
    return 0;
}