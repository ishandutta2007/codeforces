#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> link;
    vector<int> dp;

    DSU(int n, vector<int>& spec) : link(n, -1), dp(n, 0) {
        for (auto x : spec) 
            dp[x] = 1;
    }
    int Find(int x) {
        if (link[x] == -1) return x;
        return link[x] = Find(link[x]);
    }
    int Union(int a, int b) {
        a = Find(a); b = Find(b);
        if (a == b) return 0;
        link[a] = b;
        dp[b] += dp[a];
        return 1;
    }
    int Get(int x) { return dp[Find(x)]; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<int> spec(k), ans(k, 0);
    for (int i = 0; i < k; ++i) {
        cin >> spec[i]; --spec[i];
    }

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c; --a; --b;
        edges.emplace_back(c, a, b);
    }
    sort(edges.begin(), edges.end());

    for (int step = (1 << 29); step; step /= 2) {
        vector<pair<int, int>> queries;
        for (int i = 0; i < k; ++i) {
            queries.emplace_back(ans[i] + step, i);
        }
        sort(queries.begin(), queries.end());
        int at = 0;
        DSU dsu(n, spec);

        for (auto itr : queries) {
            int val, pos; tie(val, pos) = itr;
            while (at < m) {
                int c, a, b; tie(c, a, b) = edges[at];
                if (c > val) break;
                dsu.Union(a, b);
                ++at;
            }
            if (dsu.Get(spec[pos]) < k)
              ans[pos] += step;  
        }
    }

    for (auto x : ans)
        cout << x + 1 << " ";
    cout << endl;

    return 0;
}