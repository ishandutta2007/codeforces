#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, long long>>> graph;
vector<long long> vals;
long long best = 0;

long long DFS(int node, int par) {
    best = max(best, vals[node]);
    long long ret = 0;

    for (auto e : graph[node]) {
        int vec, cost; tie(vec, cost) = e;
        if (vec == par) continue;
        long long now = DFS(vec, node) - cost;
        best = max(best, ret + now + vals[node]);
        ret = max(ret, now);
    }
    return ret + vals[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    graph.resize(n);
    vals.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> vals[i];
    for (int i = 1; i < n; ++i) {
        int a, b, c; cin >> a >> b >> c; --a; --b;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    DFS(0, -1);
    cout << best << endl;

    return 0;
}