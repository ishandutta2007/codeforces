/**
 *  created: 20/05/2022, 14:21:28
**/

#include <bits/stdc++.h>

using namespace std;

template<typename Edge>
class GraphIterator {
public:
    class OutgoingEdges {
    public:
        OutgoingEdges(const GraphIterator *g, int l, int r): g(g), l(l), r(r) {
        }

        const Edge* begin() const {
            if (l == r) {
                return 0;
            }
            return &g->prepared_edges[l];
        }

        const Edge* end() const {
            if (l == r) {
                return 0;
            }
            return &g->prepared_edges[r];
        }

    private:
        int l, r;
        const GraphIterator *g;
    };

    void clear() {
        prepared_edges.clear();
        edges.clear();
        start.clear();
        prepared = false;
    }

    void add_edge(int from, const Edge &e) {
        assert(!prepared && from >= 0);
        edges.push_back({from, e});
    }

    void prepare() {
        assert(!prepared);
        int n = 0;
        for (const auto &e : edges) {
            n = max(n, e.first);
        }
        n += 2;
        start.resize(n);
        for (const auto &e : edges) {
            ++start[e.first + 1];
        }
        for (int i = 1; i < n; ++i) {
            start[i] += start[i - 1];
        }
        prepared_edges.resize(edges.size() + 1);
        auto counter = start;
        for (const auto &e : edges) {
            prepared_edges[counter[e.first]++] = e.second;
        }
        prepared = true;
    }

    OutgoingEdges operator [] (int from) const {
        assert(prepared);
        if (from < 0 || from + 1 >= start.size()) {
            return {this, 0, 0};
        }
        return {this, start[from], start[from + 1]};
    }

private:
    vector<Edge> prepared_edges;
    vector<pair<int, Edge>> edges;
    vector<int> start;
    bool prepared = false;
};

class Solver {
public:
    Solver(int n, const vector<pair<int, int>> &edges): n(n), sides(n, -1), p(n, -1)  {
        for (const auto [u, v] : edges) {
            assert(0 <= u && u < n);
            assert(0 <= v && v < n);
            g.add_edge(u, v);
            g.add_edge(v, u);
        }
        g.prepare();
        fill_sides();
        find_maximum_matching();
    }

    Solver(int n1, int n2, const vector<pair<int, int>> &edges): n(n1 + n2), sides(n1 + n2, 0), p(n1 + n2, -1)  {
        assert(0 <= n1 && 0 <= n2);
        for (const auto [u, v] : edges) {
            assert(0 <= u && u < n1);
            assert(n1 <= v && v < n1 + n2);
            g.add_edge(u, v);
        }
        g.prepare();
        fill(sides.begin(), sides.begin() + n1, 1);
        find_maximum_matching();
    }

    vector<pair<int, int>> maximum_matching() const {
        vector<pair<int, int>> result;
        for (int i = 0; i < n; ++i) {
            if (i < p[i]) {
                result.push_back({i, p[i]});
            }
        }
        return result;
    }

private:
    void fill_sides() {
        function<void(int, int)> fill_sides_dfs = [&](int v, int color) {
            sides[v] = color;
            for (int to : g[v]) {
                if (sides[to] == -1) {
                    fill_sides_dfs(to, color ^ 1);
                } else if (sides[to] != (sides[v] ^ 1)) {
                    assert(false);
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            if (sides[i] == -1) {
                fill_sides_dfs(i, 0);
            }
        }
        if (accumulate(sides.begin(), sides.end(), 0) * 2 > sides.size()) {
            for (char &part : sides) {
                part ^= 1;
            }
        }
    }

    void find_maximum_matching() {
        vector<char> visited(n);
        function<bool(int)> try_khun = [&](int v) {
            if (visited[v]) {
                return false;
            }
            visited[v] = true;
            for (int to : g[v]) {
                if (p[to] == -1) {
                    p[to] = v;
                    p[v] = to;
                    return true;
                }
            }
            for (int to : g[v]) {
                if (try_khun(p[to])) {
                    p[to] = v;
                    p[v] = to;
                    return true;
                }
            }
            return false;
        };
        for (bool run = 1; run; ) {
            run = 0;
            fill(visited.begin(), visited.end(), 0);
            for (int i = 0; i < n; ++i) {
                if (sides[i] && p[i] == -1 && try_khun(i)) {
                    run = 1;
                }
            }
        }
    }

    int n;
    GraphIterator<int> g;
    vector<char> sides;
    vector<int> p;
};

const int max_n = 1011, inf = 1000111222;

int n, m, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> big, small;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (3LL * a[i] > m) {
            big.push_back(a[i]);
        } else {
            small.push_back(a[i]);
        }
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i < big.size(); ++i) {
        for (int j = 0; j < small.size(); ++j) {
            if (2LL * big[i] + small[j] <= m && big[i] % small[j] == 0) {
                edges.push_back({i, big.size() + j});
            }
        }
    }
    Solver solver(big.size() + small.size(), edges);
    auto matching = solver.maximum_matching();
    if (matching.size() != big.size()) {
        cout << "-1\n";
    } else {
        vector<char> used(small.size());
        cout << n - matching.size() << "\n";
        for (auto [u, v] : matching) {
            v -= big.size();
            cout << 2 * big[u] + small[v] << " " << big[u] + small[v] << "\n";
            used[v] = 1;
        }
        for (int i = 0; i < small.size(); ++i) {
            if (!used[i]) {
                cout << 3 * small[i] << " " << 2 * small[i] << "\n";
            }
        }
    }
    return 0;
}