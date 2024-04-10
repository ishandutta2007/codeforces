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
        string s;
        cin >> N >> s;
        int ones = count(begin(s), end(s), '1');
        if (ones == 0 || ones % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        if (ones == N) {
            cout << "YES\n";
            for (int u = 1; u < N; u++) {
                cout << 1 << ' ' << u + 1 << '\n';
            }
            continue;
        }
        vector<array<int, 2>> edges;
        for (int i = 0; i < N; i++) {
            if (s[i] == '0') {
                edges.push_back({i, (i + 1) % N});
            }
        }
        for (auto [u, v] : edges) {
            s[u] ^= 1, s[v] ^= 1;
        }
        int E = edges.size();
        int root = find(begin(s), end(s), '1') - begin(s);
        assert(root != N && E < N - 1);
        for (int u = 0; u < N; u++) {
            if (u != root && s[u] == '1') {
                edges.push_back({root, u}), E++;
            }
        }
        assert(E == N - 1);
        cout << "YES\n";
        for (auto [u, v] : edges) {
            cout << u + 1 << ' ' << v + 1 << '\n';
        }
    }
    return 0;
}