#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<pair<int, int>> edges;
vector<bool> used;

void Dfs(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u]) {
            Dfs(u);
        }
    }
}

void Solve() {
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (g[i].size() != 0) {
            Dfs(i);
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i] && g[i].size() != 0) {
            cout << 0 << endl;
            return;
        }
    }

    vector<int> degree(n, 0);
    int loopCount = 0;
    for (int i = 0; i < m; ++i) {
        if (edges[i].first == edges[i].second) {
            ++loopCount;
        } else {
            ++degree[edges[i].first];
            ++degree[edges[i].second];
        }
    }

    long long result = 0;
    for (int i = 0; i < m; ++i) {
        int v = edges[i].first;
        int u = edges[i].second;

        if (v == u) {
            --loopCount;

            result += (m - i - 1);
        } else {
            --degree[v];
            --degree[u];

            result += loopCount;
            result += degree[v];
            result += degree[u];
        }
    }

    cout << result << endl;
}

bool Read() {
    if (!(cin >> n >> m)) {
        return false;
    }
    g.clear();
    g.resize(n);
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first;
        --edges[i].second;
        g[edges[i].first].push_back(edges[i].second);
        g[edges[i].second].push_back(edges[i].first);
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}