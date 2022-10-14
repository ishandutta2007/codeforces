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

struct disjoint_set {
    int N, S;
    vector<int> nxt, siz;

    explicit disjoint_set(int N = 0) : N(N), S(N), nxt(N), siz(N, 1) {
        iota(begin(nxt), end(nxt), 0);
    }

    void assign(int n) { *this = disjoint_set(n); }
    void reset() { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    int size(int i) { return siz[find(i)]; }

    void reroot(int u) {
        if (int r = find(u); u != r) {
            siz[u] = siz[r];
            nxt[u] = nxt[r] = u;
        }
    }

    int find(int i) { return i != nxt[i] ? nxt[i] = find(nxt[i]) : i; }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (siz[i] < siz[j]) {
                swap(i, j);
            }
            nxt[j] = i;
            siz[i] += siz[j];
            S--;
            return true;
        }
        return false;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N);
    vector<array<int, 2>> edges(M);
    string ans(M, '0');
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        if (u > v) {
            swap(u, v);
        }
        graph[u].emplace_back(v, i);
        graph[v].emplace_back(u, i);
        edges[i] = {u, v};
    }

    vector<int> avail(N, true), depth(N);
    vector<pair<int, int>> parent(N, {-1, -1});

    y_combinator([&](auto self, int u) -> void {
        avail[u] = false;
        for (auto [v, i] : graph[u]) {
            if (avail[v]) {
                ans[i] = '1';
                parent[v] = {u, i};
                depth[v] = depth[u] + 1;
                self(v);
            }
        }
    })(0);

    if (M < N + 2) {
        cout << ans << '\n';
        return;
    }

    map<array<int, 2>, int> idmap;
    vector<array<int, 2>> R;
    for (int i = 0; i < M; i++) {
        if (ans[i] == '0') {
            auto [u, v] = edges[i];
            R.push_back({u, v});
            idmap[{u, v}] = idmap[{v, u}] = i;
        }
    }

    disjoint_set dsu(N);
    bool bad = false;

    for (auto [u, v] : R) {
        bad |= !dsu.join(u, v);
    }

    if (bad) {
        vector<int> ids = {R[0][0], R[0][1], R[1][0], R[1][1], R[2][0], R[2][1]};
        sort(begin(ids), end(ids), [&](int u, int v) {
            return make_pair(depth[u], u) > make_pair(depth[v], v);
        });
        ids.erase(unique(begin(ids), end(ids)), end(ids));
        int x = ids[0], y = ids[1], z = ids[2];
        auto [p, e] = parent[x];
        ans[e] = '0';
        ans[idmap[{x, y}]] = '1';
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}