// Copyright (C) 2016 Sayutin Dmitry.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; version 3

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <assert.h>
#include <iterator>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::abs;
using std::max;

using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

#define fori(i, n)      for (int i = 0; i != (n); ++i)
#define forir(i, n)     for (int i = (n) - 1; i >= 0; --i)
#define for64(i, n)     for (int64_t i = 0; i != (n); ++i)
#define for64r(i, n)    for (int64_t i = (n) - 1; i >= 0; --i)
#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define input_arr(b, e) std::generate((b), (e), input<decltype(*b)>)

struct DSU {
    vector<int> par;
    vector<int> rank;

    DSU(int sz) {
        par.resize(sz);
        std::iota(par.begin(), par.end(), 0);
        rank.resize(sz, 0);
    }

    bool unite(int v, int u) {
        v = get(v), u = get(u);
        if (v == u)
            return false;
        if (not (rank[v] <= rank[u]))
            std::swap(v, u);
        par[v] = u;
        if (rank[v] == rank[u])
            ++rank[u];
        return true;
    }

    int get(int v) {
        return (par[v] == v ? v : (par[v] = get(par[v])));
    }
};

void dfs(const vector<vector<int>>& graph, vector<int>& dist, int v, int bad1, int bad2) {
    for (int u: graph[v]) 
        if (u != bad1 and u != bad2 and dist[u] == std::numeric_limits<int>::max()) {
            dist[u] = dist[v] + 1;
            dfs(graph, dist, u, bad1, bad2);
        }
}

void dfs_parent(const vector<vector<int>>& graph, vector<int>& dist, vector<int>& par, int v, int bad) {
    for (int u: graph[v]) 
        if (u != bad and dist[u] == std::numeric_limits<int>::max()) {
            dist[u] = dist[v] + 1;
            par[u] = v;
            dfs_parent(graph, dist, par, u, bad);
        }
}

pair<int, int> get_centre(const vector<vector<int>>& graph, int v, int bad) {
    int n = graph.size();
    vector<int> dists0(n, std::numeric_limits<int>::max());
    dists0[v] = 0;
    dfs(graph, dists0, v, bad, -1);

    int pmx = -1;
    for (int i = 0; i != n; ++i)
        if (dists0[i] != std::numeric_limits<int>::max() and (pmx == -1 or dists0[i] > dists0[pmx]))
            pmx = i;

    vector<int> par(n, -1);
    std::fill(dists0.begin(), dists0.end(), std::numeric_limits<int>::max());
    par[pmx] = pmx;
    dists0[pmx] = 0;
    dfs_parent(graph, dists0, par, pmx, bad);

    int pmx2 = -1;
    for (int i = 0; i != n; ++i)
        if (dists0[i] != std::numeric_limits<int>::max() and (pmx2 == -1 or dists0[i] > dists0[pmx2]))
            pmx2 = i;


    vector<int> theroute = {pmx2};
    int cur = pmx2;
    while (par[cur] != cur) {
        cur = par[cur];
        theroute.push_back(cur);
    }

    assert(pmx != -1 and pmx2 != -1);
    assert(theroute.back() == pmx);
    
    if (theroute.size() % 2 == 1)
        return make_pair(theroute[theroute.size() / 2], theroute[theroute.size() / 2]);
    else
        return make_pair(theroute[theroute.size() / 2 - 1], theroute[theroute.size() / 2]);
}

const uint64_t mod = 1000 * 1000 * 1000 + 7;
const uint64_t prm = 1000 * 1000 + 3;

uint64_t hash_arr(const vector<uint64_t>& data, uint64_t init) {
    uint64_t res = init;
    for (auto elem: data) {
        res = (prm * res) % mod;
        res += elem;
        if (res >= mod)
            res -= mod;
    }
    return res;
}

uint64_t hash_tree_part_do(const vector<vector<int>>& graph, int v, int bad1, int bad2, int top) {
    vector<uint64_t> sub;
    for (int u: graph[v])
        if (u != top and u != bad1 and u != bad2)
            sub.push_back(hash_tree_part_do(graph, u, bad1, bad2, v));
    std::sort(sub.begin(), sub.end());
    
    return hash_arr(sub, 1);
}

uint64_t hash_tree_part(const vector<vector<int>>& graph, int v, int bad) {
    auto centre = get_centre(graph, v, bad);
    if (centre.first == centre.second)
        return hash_tree_part_do(graph, centre.first, bad, -1, -1);
    else {
        vector<uint64_t> h;
        h.push_back(hash_tree_part_do(graph, centre.first, bad, centre.second, -1));
        h.push_back(hash_tree_part_do(graph, centre.second, bad, centre.first, -1));
        std::sort(h.begin(), h.end());
        return hash_arr(h, 1791791);
    }
}

bool check(const vector<vector<int>>& egraph, vector<uint64_t>& hashes_pre) {
    int n = egraph.size();

    vector<uint64_t> hashes_our;
    for (int i = 0; i != n; ++i) {
        vector<uint64_t> tmp;
        for (int j: egraph[i])
            if (egraph[j].size() >= 2)
                tmp.push_back(hash_tree_part(egraph, j, i));
        std::sort(tmp.begin(), tmp.end());
        hashes_our.push_back(hash_arr(tmp, 1791792));
    }
    std::sort(hashes_our.begin(), hashes_our.end());
    for (int i = 0; i != n; ++i)
        if (hashes_our[i] != hashes_pre[i])
            return false;
    return true;
}
    
void solve() {
    int n, azaza;
    scanf("%d %d", &n, &azaza);

    vector<vector<vector<int>>> graphs(n, vector<vector<int>>(n));
    vector<int> cnts(n);
    vector<uint64_t> hashes_pre;
    for (int i = 0; i != n; ++i) {
        scanf("%d", &(cnts[i]));
        
        for (int t = 0; t != cnts[i]; ++t) {
            int a, b;
            scanf("%d %d", &a, &b);
            --a; --b;
            graphs[i][a].push_back(b);
            graphs[i][b].push_back(a);
        }

        DSU dsu(n);
        for (int v = 0; v != n; ++v)
            for (int u: graphs[i][v])
                if (v < u)
                    dsu.unite(v, u);
        
        vector<uint64_t> tmp;
        for (int z = 0; z != n; ++z)
            if (dsu.get(z) == z and dsu.rank[z] != 0)
                tmp.push_back(hash_tree_part(graphs[i], z, -1));
        std::sort(tmp.begin(), tmp.end());
        hashes_pre.push_back(hash_arr(tmp, 1791792));
    }

    std::sort(hashes_pre.begin(), hashes_pre.end());
    
    int k;
    for (k = 0; k != n; ++k) {
        if (cnts[k] + 2 == n)
            break;
    }

    if (k != n) {
        vector<vector<int>> egraph(n);
        vector<char> usage(n, false);
        for (int v = 0; v != n; ++v)
            for (int u: graphs[k][v]) {
                egraph[v].push_back(u);
                usage[v] = true;
                usage[u] = true;
            }

        
        int v = std::find(usage.begin(), usage.end(), false) - usage.begin();
        for (int u = 0; u != n; ++u)
            if (v != u) {
                egraph[v].push_back(u);
                egraph[u].push_back(v);
                if (check(egraph, hashes_pre)) {
                    printf("YES\n");
                    for (int a0 = 0; a0 != n; ++a0)
                        for (int a1: egraph[a0])
                            if (a0 < a1)
                                printf("%d %d\n", a0 + 1, a1 + 1);
                    return;
                }
                egraph[v].pop_back();
                egraph[u].pop_back();
            }
    }
    printf("NO\n");
}

int main() {
    int q;
    scanf("%d", &q);
    fori(i, q)
        solve();
    
    return 0;
}