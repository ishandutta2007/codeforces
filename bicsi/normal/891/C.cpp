#include <bits/stdc++.h>

using namespace std;

struct QryPiece {
    int idx;
    vector<pair<int, int>> edgs;
};

vector<pair<int, int>> edges[500005];
vector<QryPiece> qrs[500005];
vector<tuple<int, int, int>> E;
vector<pair<int, int>> EST[500005];

struct DSU {
    vector<int> link, rank;

    DSU(int n) : link(n, -1), rank(n, 0) {}

    int Find(int x) { 
        while (link[x] != -1)
            x = link[x];
        return x;
    }

    vector<pair<int, int>> ops;

    bool Union(int a, int b) {
        a = Find(a); b = Find(b);
        if (a == b) return false;
        
        if (rank[a] > rank[b]) swap(a, b);

        ops.emplace_back(a, link[a]);
        link[a] = b;
        rank[b] += (rank[a] == rank[b]);
        return true;
    }

    void Undo(int opc) {
        for (int i = 0; i < opc; ++i) {
            int pos, val;
            tie(pos, val) = ops.back();
            link[pos] = val;
            ops.pop_back();
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        edges[c].emplace_back(a - 1, b - 1);
        E.emplace_back(a - 1, b - 1, c);
    }

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int k; cin >> k;
        vector<int> idxs;
        while (k--) {
            int idx; cin >> idx; --idx;
            idxs.push_back(idx);
        }

        vector<int> costs;
        for (auto idx : idxs) {
            int a, b, c; tie(a, b, c) = E[idx];    
            EST[c].emplace_back(a, b);
            costs.push_back(c);
        }

        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());

        for (auto c : costs) {
            qrs[c].push_back(QryPiece{i, EST[c]});
            EST[c].clear();
        }
    }

    DSU dsu(n);

    vector<char> ans(q, 1);

    for (int c = 0; c <= 500000; ++c) {
        for (auto q : qrs[c]) {
            int cnt = 0;
            for (auto e : q.edgs) {
                cnt += dsu.Union(e.first, e.second);
            }
            if (cnt != (int)q.edgs.size()) {
                ans[q.idx] = 0;
            }
            dsu.Undo(cnt);
        }

        for (auto e : edges[c]) {
            dsu.Union(e.first, e.second);
        }   
    }

    for (int i = 0; i < q; ++i) {
        cout << (ans[i] ? "YES\n" : "NO\n");
    }

    return 0;
}