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
    vector<vector<int>> out(N), in(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        out[u].push_back(v);
        in[v].push_back(u);
    }
    vector<vector<int>> batches;
    vector<int> live(N, true), color(N), colored;
    for (int u = 0; u < N; u++) {
        if (live[u]) {
            vector<int> batch = {u};
            for (int v : out[u]) {
                if (live[v]) {
                    batch.push_back(v);
                }
            }
            for (int v : batch) {
                live[v] = false;
            }
            batches.push_back(move(batch));
        }
    }
    reverse(begin(batches), end(batches));
    for (const auto& batch : batches) {
        int u = batch[0];
        bool ok = false;
        for (int v : in[u]) {
            ok |= live[v] && color[v];
        }
        if (!ok) {
            color[u] = 1;
            colored.push_back(u);
        }
        for (int v : batch) {
            live[v] = true;
        }
    }
    int C = colored.size();
    cout << C << '\n';
    for (int i = 0; i < C; i++) {
        cout << colored[i] + 1 << " \n"[i + 1 == C];
    }
    return 0;
}