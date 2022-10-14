#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto digit_mask(uint64_t n) {
    string s = to_string(n);
    int mask = 0;
    for (char c : s) {
        mask |= 1 << (c - '0');
    }
    int N = s.size();
    return make_pair(N, mask);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    uint64_t x;
    cin >> N >> x;
    set<uint64_t> seen = {x};
    vector<pair<uint64_t, int>> bfs = {{x, 0}};
    for (int i = 0, B = 1; i < B; i++) {
        auto [u, dist] = bfs[i];
        auto [L, mask] = digit_mask(u);
        if (L == N) {
            cout << dist << '\n';
            return 0;
        }
        for (int d = 1; d <= 9; d++) {
            if (mask >> d & 1) {
                uint64_t v = u * d;
                if (seen.insert(v).second) {
                    bfs.push_back({v, dist + 1}), B++;
                }
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}