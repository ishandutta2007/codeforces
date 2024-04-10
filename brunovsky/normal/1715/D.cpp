#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    int full = (1 << 30) - 1;
    vector<int> a(N), lo(N), hi(N, full);
    vector<vector<array<int, 2>>> here(N);
    for (int q = 0; q < Q; q++) {
        int u, v, x;
        cin >> u >> v >> x, u--, v--;
        if (u > v) {
            swap(u, v);
        }
        if (u == v) {
            lo[u] = hi[u] = x;
        } else {
            hi[u] &= x;
            hi[v] &= x;
            here[u].push_back({v, x});
        }
    }
    for (int u = 0; u < N; u++) {
        int rem = 0;
        for (auto [v, x] : here[u]) {
            rem |= x ^ hi[v];
        }
        a[u] = lo[u] | rem;
        for (auto [v, x] : here[u]) {
            lo[v] |= x ^ a[u];
        }
    }
    for (int u = 0; u < N; u++) {
        cout << a[u] << " \n"[u + 1 == N];
    }
    return 0;
}