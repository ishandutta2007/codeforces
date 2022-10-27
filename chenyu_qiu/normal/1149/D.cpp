#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    // freopen("gray.in", "r", stdin);
    // freopen("gray.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a > b) {
        swap(a, b);
    }

    vector<int> par(n);
    function<int(int)> find = [&](int x) {
        return x == par[x] ? x : (par[x] = find(par[x]));
    };
    iota(par.begin(), par.end(), 0);

    vector<vector<pair<int, int>>> e(n);
    vector<pair<int, int>> edges;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        if (w == a) {
            par[find(u)] = find(v);
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        } else {
            edges.push_back({u, v});
        }
    }

    for (auto it : edges) {
        int u, v;
        tie(u, v) = it;
        if (find(u) != find(v)) {
            e[u].push_back({v, b});
            e[v].push_back({u, b});
        }
    }

    vector<int> siz(n);
    for (int i = 0; i < n; ++i) {
        ++siz[find(i)];
    }
    vector<int> id(n, -1);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (find(i) == i && siz[i] >= 4) {
            id[i] = cnt++;
        }
    }
    for (int i = 0; i < n; ++i) {
        id[i] = id[find(i)];
    }

    vector<int> dp(n << cnt, 1e9);
    vector<int> ans(n, 1e9);
    priority_queue<pair<int, int>> pq;
    pq.emplace(-0, 0);
    dp[0] = 0;
    while (!pq.empty()) {
        int dis, ID;
        tie(dis, ID) = pq.top();
        pq.pop();
        if (-dis != dp[ID]) {
            continue;
        }
        int u = ID >> cnt;
        int s = ID & ((1 << cnt) - 1);
        ans[u] = min(ans[u], dp[ID]);
        for (auto it : e[u]) {
            int v = it.first;
            int val = dp[ID] + it.second;
            if (id[u] != id[v]) {
                if (id[v] != -1 && (s >> id[v] & 1)) {
                    continue;
                }
                int nID = v << cnt | s;
                if (id[u] != -1) {
                    nID |= 1 << id[u];
                }
                if (dp[nID] > val) {
                    dp[nID] = val;
                    pq.emplace(-dp[nID], nID);
                } 
            } else {
                int nID = v << cnt | s;
                if (dp[nID] > val) {
                    dp[nID] = val;
                    pq.emplace(-dp[nID], nID);
                } 
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}