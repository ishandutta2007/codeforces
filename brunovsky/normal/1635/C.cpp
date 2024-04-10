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
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        bool ok = a[N - 2] <= a[N - 1];
        vector<array<int, 3>> ops;
        if (ok && a[N - 1] >= 0) {
            for (int i = 0; i + 2 < N; i++) {
                ops.push_back({i, N - 2, N - 1});
            }
        } else {
            ok = is_sorted(begin(a), end(a));
        }
        if (ok) {
            cout << ops.size() << '\n';
            for (auto [x, y, z] : ops) {
                cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
            }
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}