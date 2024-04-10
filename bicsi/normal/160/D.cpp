#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> link;
    DSU(int n) : link(n, -1) {}

    int Find(int x) {
        if (link[x] == -1) return x; 
        return link[x] = Find(link[x]);
    }

    int Union(int a, int b) {
        a = Find(a); b = Find(b);
        if (a == b) return 0;
        link[a] = b;
        return 1;
    }
};

struct BCC {
    vector<pair<int, int>> edges;
    vector<vector<int>> G;
    vector<int> enter, low, stk;

    BCC(int n) : G(n), enter(n, -1) {}

    int AddEdge(int a, int b) {
        int ret = edges.size();
        edges.emplace_back(a, b);
        G[a].push_back(ret);
        G[b].push_back(ret);
        return ret;
    }

    function<void(int)> cb;
    template<typename Iter>
    void Callback(Iter bg, Iter en) {
        if (distance(bg, en) != 1) return;
        cb(*bg);
    }

    void Solve(function<void(int)> cb) {
        this->cb = cb;
        for (int i = 0; i < (int)G.size(); ++i)
            if (enter[i] == -1) {
                dfs(i, -1);
            }
    }

    int timer = 0;
    int dfs(int node, int pei) {
        enter[node] = timer++;
        int ret = enter[node];

        for (auto ei : G[node]) if (ei != pei) {
            int vec = (edges[ei].first ^ edges[ei].second ^ node);
            if (enter[vec] != -1) {
                ret = min(ret, enter[vec]);
                if (enter[vec] < enter[node])
                    stk.push_back(ei);
            } else {
                int sz = stk.size(), low = dfs(vec, ei);
                ret = min(ret, low);
                stk.push_back(ei);
                if (low >= enter[node]) {
                    Callback(stk.begin() + sz, stk.end());
                    stk.resize(sz);
                }
            }
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<tuple<int, int, int>>> edges(1000005);

    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        edges[c].emplace_back(a - 1, b - 1, i);
    }
    
    DSU dsu(n);
    vector<int> ans(m, -1);
    for (auto& es : edges) {
        vector<tuple<int, int, int>> nes;
        vector<int> all;

        for (auto x : es) {
            int a, b, i; tie(a, b, i) = x;
            a = dsu.Find(a); b = dsu.Find(b);
            if (a == b) {
                continue;
            }
            all.push_back(a);
            all.push_back(b);
            nes.emplace_back(a, b, i);
        }
        
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        auto norm = [&](int x) {
            auto it = lower_bound(all.begin(), all.end(), x);
            assert(*it == x);
            return distance(all.begin(), it);
        };

        BCC bcc(all.size());
        vector<int> true_idx;

        for (auto x : nes) {
            int a, b, i; tie(a, b, i) = x;
            dsu.Union(a, b);
            a = norm(a); b = norm(b);
            assert((int)true_idx.size() == bcc.AddEdge(a, b));
            true_idx.push_back(i);
            ans[i] = 0;    
        }

        bcc.Solve([&](int id) { ans[true_idx[id]] = 1; });
    }

    for (auto x : ans) {
        if (x == -1) cout << "none" << '\n';
        if (x ==  0) cout << "at least one" << '\n';
        if (x ==  1) cout << "any" << '\n';
    }


    return 0;
}