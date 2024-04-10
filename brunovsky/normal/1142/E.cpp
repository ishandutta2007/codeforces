#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

auto build_scc(const vector<vector<int>>& adj, bool reverse_order = true) {
    int V = adj.size(), C = 0; // C = number of scc

    vector<int> cmap(V, -1), index(V), lowlink(V), stack(V);
    int timer = 1, S = 0;

    auto dfs = y_combinator([&](auto self, int u) -> void {
        index[u] = lowlink[u] = timer++;
        stack[S++] = u;

        for (int v : adj[u]) {
            if (index[v] && cmap[v] == -1) { // <-- skip cmap'd nodes
                lowlink[u] = min(lowlink[u], index[v]);
            } else if (!index[v]) {
                self(v);
                lowlink[u] = min(lowlink[u], lowlink[v]);
            }
        }

        // found a strongly connected component
        if (index[u] == lowlink[u]) {
            int c = C++;
            int v;
            do {
                v = stack[--S];
                cmap[v] = c;
            } while (u != v);
        }
    });

    for (int u = 0; u < V; u++) {
        if (!index[u]) {
            dfs(u);
        }
    }
    if (!reverse_order) {
        for (int u = 0; u < V; u++) {
            cmap[u] = C - 1 - cmap[u];
        }
    }

    return make_pair(C, cmap);
}

auto condensate_sccedges(const vector<vector<int>>& adj, const vector<int>& cmap) {
    int V = adj.size();
    vector<array<int, 2>> edges;
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            if (cmap[u] != cmap[v]) {
                edges.push_back({cmap[u], cmap[v]});
            }
        }
    }
    sort(begin(edges), end(edges));
    edges.erase(unique(begin(edges), end(edges)), end(edges));
    return edges;
}

auto condensate_scc(int C, const vector<vector<int>>& adj, const vector<int>& cmap) {
    auto edges = condensate_sccedges(adj, cmap);
    vector<vector<int>> sccout(C), sccin(C);
    for (auto [u, v] : edges) {
        sccout[u].push_back(v);
        sccin[v].push_back(u);
    }
    return make_tuple(edges, sccout, sccin);
}

bool FORWARD(int u, int v) {
    cout << "? " << u + 1 << ' ' << v + 1 << endl;
    int ans;
    cin >> ans;
    if (ans != 0 && ans != 1) {
        exit(0);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<array<int, 2>> graph(M);
    vector<vector<int>> pink(N);
    for (auto& [u, v] : graph) {
        cin >> u >> v, u--, v--;
        pink[u].push_back(v);
    }

    auto [C, cmap] = build_scc(pink);
    vector<vector<int>> sccout(C);
    vector<int> indeg(C);
    for (auto [u, v] : graph) {
        if (cmap[u] != cmap[v]) {
            sccout[cmap[u]].push_back(cmap[v]);
        }
    }
    for (int c = 0; c < C; c++) {
        sort(begin(sccout[c]), end(sccout[c]));
        sccout[c].erase(unique(begin(sccout[c]), end(sccout[c])), end(sccout[c]));
        for (int d : sccout[c]) {
            indeg[d]++;
        }
    }

    vector<vector<int>> cset(C);
    for (int u = 0; u < N; u++) {
        cset[cmap[u]].push_back(u);
    }

    vector<int> roots;
    for (int c = 0; c < C; c++) {
        if (indeg[c] == 0) {
            roots.push_back(c);
        }
    }

    auto take_root = [&]() {
        int r = roots.back();
        roots.pop_back();
        return r;
    };
    auto take_node = [&](int c) {
        int u = cset[c].back();
        cset[c].pop_back();
        return u;
    };

    int root = take_root();
    int u = take_node(root);

    while (!roots.empty()) {
        int other = take_root();

        do {
            int v = take_node(other);
            if (!FORWARD(u, v)) {
                swap(u, v);
                swap(root, other);
            }
        } while (!cset[other].empty());

        for (int c : sccout[other]) {
            if (--indeg[c] == 0) {
                roots.push_back(c);
            }
        }
    }

    cout << "! " << u + 1 << endl;
    return 0;
}