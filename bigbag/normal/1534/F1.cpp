/**
 *  created: 13/06/2021, 19:41:30
**/

#include <bits/stdc++.h>

using namespace std;

#ifndef ATCODER_SCC_HPP
#define ATCODER_SCC_HPP 1

#include <algorithm>
#ifndef ATCODER_INTERNAL_SCC_HPP
#define ATCODER_INTERNAL_SCC_HPP 1

#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_SCC_HPP

#include <cassert>
#include <vector>

namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder

#endif  // ATCODER_SCC_HPP

using namespace atcoder;

const int max_n = 400444, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int n, m, verts, comp[max_n], ok[max_n];
string s[max_n];
vector<int> num[max_n];

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

vector<pair<int, int>> edges;

void add_edge(int u, int v) {
    edges.push_back({u, v});
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        s[i] = read();
        num[i].resize(m);
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#') {
                num[i][j] = verts++;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int last = n;
        for (int j = n - 1; j >= 0; --j) {
            if (s[j][i] == '#') {
                if (last != n) {
                    add_edge(num[j][i], num[last][i]);
                }
                for (int k = j; k < last; ++k) {
                    if (i && s[k][i - 1] == '#') {
                        add_edge(num[j][i], num[k][i - 1]);
                    }
                    if (i + 1 < m && s[k][i + 1] == '#') {
                        add_edge(num[j][i], num[k][i + 1]);
                    }
                }
                if (j && s[j - 1][i] == '#') {
                    add_edge(num[j][i], num[j - 1][i]);
                }
                last = j;
            }
        }
    }
    scc_graph g(verts);
    for (auto [u, v] : edges) {
        g.add_edge(u, v);
    }
    auto scc = g.scc();
    for (int i = 0; i < scc.size(); ++i) {
        for (int v : scc[i]) {
            comp[v] = i;
            //cout << v << " ";
        }
        //cout << endl;
    }
    for (auto [u, v] : edges) {
        if (comp[u] != comp[v]) {
            //cout << u << " -> " << v << endl;
            ok[comp[v]] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < scc.size(); ++i) {
        ans += !ok[i];
    }
    printf("%d\n", ans);
    return 0;
}