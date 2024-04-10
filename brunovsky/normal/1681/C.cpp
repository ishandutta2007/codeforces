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
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        vector<vector<int>> pos(N + 1);
        for (int i = 0; i < N; i++) {
            pos[a[i]].push_back(i);
        }
        vector<int> ordered, match(N, -1);
        for (int v = 1; v <= N; v++) {
            vector<pair<int, int>> vals;
            for (int i : pos[v]) {
                vals.push_back(make_pair(b[i], i));
            }
            sort(begin(vals), end(vals));
            int V = vals.size();
            for (int i = 0, S = ordered.size(); i < V; i++) {
                match[vals[i].second] = S + i;
                ordered.push_back(vals[i].first);
            }
        }
        if (!is_sorted(begin(ordered), end(ordered))) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> who(N, -1);
        for (int i = 0; i < N; i++) {
            who[match[i]] = i;
        }
        vector<array<int, 2>> swaps;
        for (int i = 0; i < N; i++) {
            if (who[i] != i) {
                swaps.push_back({i, who[i]});
                who[match[i]] = who[i];
                match[who[i]] = match[i];
            }
        }
        int S = swaps.size();
        cout << S << '\n';
        for (auto [u, v] : swaps) {
            cout << u + 1 << ' ' << v + 1 << '\n';
        }
    }
    return 0;
}