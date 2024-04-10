#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long 

using namespace std;

int n, k; 
vector<vector<pair<int, int>>> graph;

pair<long long, long long> DFS(int node, int par) {
    vector<long long> wins;
    long long ans = 0;
    for (auto p : graph[node]) {
        int vec, weight; tie(vec, weight) = p;
        if (vec == par) continue;
        long long without, with; 
        tie(without, with) = DFS(vec, node);
        wins.push_back(max(0LL, with + weight - without));
        ans += without;
    }
    sort(wins.rbegin(), wins.rend());
    if (k > (int)wins.size()) {
        for (auto x : wins) 
            ans += x;
        return {ans, ans};
    } else {
        for (int i = 0; i < k; ++i)
            ans += wins[i];
        return {ans, ans - wins[k - 1]};
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        graph.assign(n, {});
        for (int i = 1; i < n; ++i) {
            int a, b, c; cin >> a >> b >> c;
            --a; --b;
            graph[a].emplace_back(b, c);
            graph[b].emplace_back(a, c);
        }
        auto p = DFS(0, -1);
        cout << max(p.first, p.second) << '\n';
    }

    return 0;
}