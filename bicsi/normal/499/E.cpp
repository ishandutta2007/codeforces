#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct EZFlow {
    vector<map<int, int>> G;
    vector<bool> seen;

    EZFlow(int n) : G(n), seen(n, false) {}

    void AddEdge(int a, int b, int c) {
        G[a][b] += c;
        G[b][a] += 0;
    }

    int dfs(int node, int d, int flow) {
        if (node == d or flow == 0) return flow;
        if (seen[node]) return 0;
        seen[node] = true;
        
        for (auto e : G[node]) {
            int vec, cap; tie(vec, cap) = e;
            if (int ret = dfs(vec, d, min(flow, cap))) {
                G[node][vec] -= ret;
                G[vec][node] += ret;
                return ret;
            }
        }
        return 0;
    }
    int MaxFlow(int s, int d) {
        int total = 0;
        while (int flow = dfs(s, d, 1e9)) {
            fill(seen.begin(), seen.end(), false);
            total += flow;
        }
        return total;
    };
};

int main() {
    int n, m; cin >> n >> m;
        
    vector<map<int, pair<int, int>>> facts(n);
    int nodes = 2;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;

        for (int d = 2; d <= x; d += 1) {
            if (d * d > x) d = x;

            int e = 0;
            while (x % d == 0) {
                x /= d;
                e += 1;
            }
            if (e) {
                int node = nodes++;
                facts[i][d] = make_pair(node, e);
            }
        }    
    }

    EZFlow flow(nodes);
    for (int i = 0; i < n; ++i) {
        for (auto x : facts[i]) {
            int node, cap; tie(node, cap) = x.second;
            if (i % 2) {
                flow.AddEdge(0, node, cap);
            } else {
                flow.AddEdge(node, 1, cap);
            }
        }
    }

    while (m--) {
        int a, b; cin >> a >> b; --a; --b;
        if (b % 2) swap(a, b);
        for (auto p : facts[a]) {
            auto it = facts[b].find(p.first);
            if (it == facts[b].end()) continue;

            flow.AddEdge(p.second.first, it->second.first, 1e9);
        }
    }

    cout << flow.MaxFlow(0, 1) << endl;
    return 0;
}