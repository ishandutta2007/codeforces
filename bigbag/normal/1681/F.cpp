/**
 *  created: 23/05/2022, 18:37:31
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

const int max_n = 500555, inf = 1000111222;

int n, sz[max_n], used[max_n];
GraphIterator<pair<int, int>> g;
long long ans;

void calc_sz(int v, int p) {
    sz[v] = 1;
    for (auto [to, c] : g[v]) {
        if (to == p || used[to]) {
            continue;
        }
        calc_sz(to, v);
        sz[v] += sz[to];
    }
}

int get_root(int v, int p, int tot) {
    for (auto [to, c] : g[v]) {
        if (to == p || used[to]) {
            continue;
        }
        if (sz[to] * 2 >= tot) {
            return get_root(to, v, tot);
        }
    }
    return v;
}

template<typename T = int>
class ArrayResetter {
public:
    ArrayResetter(int n, const T &default_value = {}): v(n, {default_value, 0}),
                                                       default_value(default_value),
                                                       current_version(0) {
    }

    void reset() {
        ++current_version;
        if (current_version == 0) {
            v.assign(v.size(), {default_value, 0});
        }
    }

    void reset(const T &value) {
        default_value = value;
        reset();
    }

    T& operator [](int index) {
        assert(0 <= index && index < v.size());
        if (v[index].second < current_version) {
            v[index].first = default_value;
            v[index].second = current_version;
        }
        return v[index].first;
    }

    const T& operator [](int index) const {
        assert(0 <= index && index < v.size());
        if (v[index].second < current_version) {
            return default_value;
        }
        return v[index].first;
    }

private:
    vector<pair<T, unsigned int>> v;
    T default_value;
    unsigned int current_version;
};

ArrayResetter<> bad(max_n), cnt_col(max_n);

void proc(int v, int p, int pc, int sign) {
    ++cnt_col[pc];
    if (cnt_col[pc] == 1) {
        bad[pc] += sign * sz[v];
    }
    for (auto [to, c] : g[v]) {
        if (to == p || used[to]) {
            continue;
        }
        proc(to, v, c, sign);
    }
    --cnt_col[pc];
}

void get_ans(int v, int p, int pc, int tot) {
    ++cnt_col[pc];
    if (cnt_col[pc] == 1) {
        ans += 1LL * sz[v] * (tot - bad[pc]);
    }
    if (cnt_col[pc] == 2) {
        ans -= 1LL * sz[v] * (tot - bad[pc]);
    }
    for (auto [to, c] : g[v]) {
        if (to == p || used[to]) {
            continue;
        }
        get_ans(to, v, c, tot);
    }
    --cnt_col[pc];
}

void rec(int v) {
    calc_sz(v, -1);
    v = get_root(v, -1, sz[v]);
    calc_sz(v, -1);
    //cout << v << ": " << sz[v] << endl;
    used[v] = 1;
    bad.reset();
    for (auto [to, c] : g[v]) {
        if (used[to]) {
            continue;
        }
        cnt_col.reset();
        proc(to, v, c, 1);
    }
    for (auto [to, c] : g[v]) {
        if (used[to]) {
            continue;
        }
        cnt_col.reset();
        proc(to, v, c, -1);

        cnt_col.reset();
        get_ans(to, v, c, sz[v] - sz[to]);
        cnt_col.reset();
        proc(to, v, c, 1);
    }
    for (auto [to, c] : g[v]) {
        if (used[to]) {
            continue;
        }
        rec(to);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        --u;
        --v;
        g.add_edge(u, {v, x});
        g.add_edge(v, {u, x});
    }
    g.prepare();
    rec(0);
    cout << ans << "\n";
    return 0;
}