#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
const int kMod = 998244353;

bool DFS(vector<vector<pair<int, int>>>& graph, int node, int col, vector<int>& v) {
    if (v[node] == col) return 1;
    if (v[node] == -1) v[node] = col;
    if (v[node] != col) return 0;
    
    for (auto e : graph[node]) {
        if (!DFS(graph, e.first, col ^ e.second, v))
            return false;
    }
    return true;
}

int Count(vector<vector<pair<int, int>>> graph) {
    vector<int> v(graph.size(), -1);
    int total = DFS(graph, 0, 0, v);
    for (int i = 0; i < (int)graph.size(); ++i) {
        if (v[i] == -1) {
            if (!DFS(graph, i, 0, v)) return 0;
            total += total;
            if (total >= kMod) total -= kMod;
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string xorsum; cin >> xorsum;
    int n = xorsum.size();

    int total = 0;

    for (int cz = 1; cz < n; ++cz) {

        vector<vector<pair<int, int>>> graph(2 * n + 1);
        auto add_edge = [&](int i, int j, int neq) {
            graph[i].emplace_back(j, neq);
            graph[j].emplace_back(i, neq);
        };

        for (int i = 0, j = n - 1; i < j; ++i, --j)
            add_edge(i + 1, j + 1, 0);
        add_edge(0, 1, 1);
        for (int i = cz, j = n - 1; i < j; ++i, --j)
            add_edge(i + n + 1, j + n + 1, 0);
        add_edge(0, cz + n + 1, 1);
        for (int i = 0; i < cz; ++i)
            add_edge(0, i + n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            if (xorsum[i] == '0') add_edge(i + 1, i + n + 1, 0);
            if (xorsum[i] == '1') add_edge(i + 1, i + n + 1, 1);
        }
        
        total += Count(graph);
        if (total >= kMod) total -= kMod;
    }

    cout << total << endl;

    return 0;
}