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
    vector<set<int>> out(N), in(N);
    vector<int> outdeg(N), indeg(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        out[u].insert(v);
        in[v].insert(u);
        outdeg[u]++;
        indeg[v]++;
    }
    for (int u = 0; u < N; u++) {
        if (outdeg[u] == 1 && !out[u].empty()) {
            int v = *out[u].begin();
            out[u].clear();
            in[v].erase(u);
        }
        if (indeg[u] == 1 && !in[u].empty()) {
            int v = *in[u].begin();
            in[u].clear();
            out[v].erase(u);
        }
    }
    vector<int> bfs(N), dp(N, 1);
    int B = 0;
    for (int u = 0; u < N; u++) {
        indeg[u] = in[u].size();
        if (indeg[u] == 0) {
            bfs[B++] = u;
        }
    }
    for (int i = 0; i < B; i++) {
        int u = bfs[i];
        for (int v : out[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            if (--indeg[v] == 0) {
                bfs[B++] = v;
            }
        }
    }
    int ans = *max_element(begin(dp), end(dp));
    cout << ans << '\n';
    return 0;
}