#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;

    auto QUERY = [&](int u) {
        cout << "? " << 1 + u << endl;
        vector<int> d(N);
        for (int v = 0; v < N; v++) {
            cin >> d[v];
        }
        return d;
    };

    auto core = QUERY(0);
    vector<int> odds, evens;
    for (int u = 1; u < N; u++) {
        if (core[u] & 1) {
            odds.push_back(u);
        } else {
            evens.push_back(u);
        }
    }

    if (odds.size() <= evens.size()) {
        swap(odds, evens);
    }

    vector<pair<int, int>> edges;
    for (int u = 1; u < N; u++) {
        if (core[u] == 1) {
            edges.push_back({0, u});
        }
    }

    for (int u : evens) {
        auto d = QUERY(u);
        for (int v = 1; v < N; v++) {
            if (d[v] == 1) {
                edges.push_back(minmax(u, v));
            }
        }
    }

    cout << "!" << endl;
    for (auto [u, v] : edges) {
        cout << u + 1 << ' ' << v + 1 << endl;
    }

    return 0;
}