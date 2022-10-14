#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> in(N + 1);
    vector<int> outdeg(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        in[v].push_back(u);
        outdeg[u]++;
    }

    set<int> alive;
    for (int u = 1; u <= N; u++) {
        if (outdeg[u] == 0) {
            alive.insert(u);
        }
    }

    vector<int> label(N + 1);
    int timer = N;

    while (!alive.empty()) {
        int u = *alive.rbegin();
        alive.erase(u);

        label[u] = timer--;
        for (int v : in[u]) {
            if (--outdeg[v] == 0) {
                alive.insert(v);
            }
        }
    }

    for (int u = 1; u <= N; u++) {
        cout << label[u] << " \n"[u == N];
    }

    return 0;
}