#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<set<int, greater<int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int ans = 0;
    auto survives = [&](int u) { return adj[u].empty() || *adj[u].begin() < u; };
    for (int u = 0; u < N; u++) {
        ans += survives(u);
    }
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            ans -= survives(u);
            ans -= survives(v);
            adj[u].insert(v);
            adj[v].insert(u);
            ans += survives(u);
            ans += survives(v);
        } else if (type == 2) {
            int u, v;
            cin >> u >> v;
            ans -= survives(u);
            ans -= survives(v);
            adj[u].erase(v);
            adj[v].erase(u);
            ans += survives(u);
            ans += survives(v);
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}