#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> order = {0}, depth(n, 0);
    vector<vector<int>> link(20, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        int node = order[i];
        for (auto vec : graph[node]) {
            link[0][vec] = node;
            depth[vec] = 1 + depth[node];
            for (int i = 1; i < 20; ++i) {
                int anc = link[i - 1][vec];
                if (anc != -1)
                    link[i][vec] = link[i - 1][anc];
            }
            graph[vec].erase(find(graph[vec].begin(), graph[vec].end(), node));
            order.push_back(vec);    
        }
    }

    auto anc = [&](int a, int k) {
        for (int i = 0; k; ++i, k /= 2)
            if (k % 2)
                a = link[i][a];
        return a;
    };
    auto lca = [&](int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        a = anc(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int i = 19; i >= 0; --i) {
            if (link[i][a] != link[i][b])
                a = link[i][a], b = link[i][b];
        }
        return link[0][a];
    };

    vector<int> sz(n, 1);
    for (int i = n - 1; i >= 0; --i) {
        for (auto vec : graph[order[i]])
            sz[order[i]] += sz[vec];
    }

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        if (a == b) {
            cout << n << '\n';
            continue;
        }

            
        int lc = lca(a, b);
        int dist = depth[a] + depth[b] - 2 * depth[lc];
        if (dist % 2) {
            cout << 0 << '\n';
            continue;
        }
        
        dist /= 2;
        if (depth[a] < depth[b])
            swap(a, b);
        int mid = anc(a, dist);
        if (mid == lc) {
            cout << n - sz[anc(a, dist - 1)] - sz[anc(b, dist - 1)] << '\n';
        } else {
            cout << sz[mid] - sz[anc(a, dist - 1)] << '\n';
        }
    }

    return 0;
}