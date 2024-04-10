#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int n) { *this = disjoint_set(n); }
    void reset() { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return i == next[i] && size[i] == 1; }
    bool root(int i) { return find(i) == i; }
    void reroot(int u) {
        if (int r = find(u); u != r) {
            size[u] = size[r];
            next[u] = next[r] = u;
        }
    }

    int find(int i) {
        while (i != next[i]) {
            i = next[i] = next[next[i]];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            next[j] = i;
            size[i] += size[j];
            S--;
            return true;
        }
        return false;
    }
};

auto build_edge_line_tree(int N, const vector<array<int, 2>>& tree, vector<int> order) {
    disjoint_set dsu(N);
    reverse(begin(order), end(order));

    vector<int> left(N), right(N);
    iota(begin(left), end(left), 0);
    iota(begin(right), end(right), 0);

    vector<array<int, 3>> line;

    for (int e : order) {
        int u = tree[e][0], v = tree[e][1];
        u = dsu.find(u), v = dsu.find(v);
        dsu.join(u, v);
        int y = dsu.find(u);
        line.push_back({right[u], left[v], e});
        left[y] = left[u], right[y] = right[v];
    }

    return line;
}

// min edge line array for less<T> (i.e. array retains the minimum weight edge on path)
template <typename T, typename Compare = greater<T>>
auto build_min_edge_line(int N, const vector<array<int, 2>>& edges,
                         const vector<T>& weight, const Compare& cmp = Compare()) {
    int E = N - 1;
    assert(E == int(edges.size()) && E == int(weight.size()));

    vector<int> order(E);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order),
         [&](int a, int b) { return cmp(weight[a], weight[b]); });

    auto line = build_edge_line_tree(N, edges, order);

    vector<array<int, 2>> adj(N, {-1, -1});
    for (int i = 0; i < E; i++) {
        auto [u, v, e] = line[i];
        adj[u][adj[u][0] != -1] = adj[v][adj[v][0] != -1] = i;
    }

    for (int s = 0; s < N; s++) {
        if (adj[s][1] == -1) {
            vector<int> index(N), edge(E);
            vector<T> value(E);
            int u = s, j = adj[s][0];
            for (int i = 0; i < E; i++) {
                index[u] = i, edge[i] = line[j][2];
                value[i] = weight[edge[i]];
                u = line[j][u == line[j][0]];
                j = adj[u][j == adj[u][0]];
            }
            assert(j == -1);
            index[u] = N - 1;
            return make_tuple(move(index), move(edge), move(value));
        }
    }
    __builtin_unreachable();
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q, s, d;
    cin >> N >> Q >> s >> d, s--;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    auto cost = [&](int i, int j) {
        return a[j] - a[i] - d;
    };

    vector<array<int, 2>> cand_edges;
    for (int L = 1; L < N; L *= 2) {
        for (int a = 0; a + L < N; a += 2 * L) {
            int R = min(L, N - L - a);
            int b = a + L;
            int c = b + R;
            for (int i = a, j = b; i < b; i++) {
                while (j + 1 < c && cost(i, j + 1) <= 0) {
                    j++;
                }
                cand_edges.push_back({ i, j});
                if (j + 1 < c) {
                    cand_edges.push_back({i, j + 1});
                }
            }
            for (int j = b, i = a; j < c; j++) {
                while (i + 1 < b && cost(i + 1, j) >= 0) {
                    i++;
                }
                cand_edges.push_back({ i, j});
                if (i + 1 < b) {
                    cand_edges.push_back({i + 1, j});
                }
            }
        }
    }

    sort(begin(cand_edges), end(cand_edges), [&](auto a, auto b) {
        return abs(cost(a[0], a[1])) < abs(cost(b[0], b[1]));
    });

    disjoint_set dsu(N);
    vector<array<int, 2>> minedges;
    vector<int> minweight;

    for (auto [ u, v] : cand_edges) {
        if (dsu.join(u, v)) {
            minedges.push_back({u, v});
            minweight.push_back(abs(cost(u, v)));
        }
    }
    assert(int(minweight.size()) == N - 1);

    auto [index, edge, value] = build_min_edge_line(N, minedges, minweight);

    vector<int> ans(N, 0);
    ans[index[s]] = 0;
    for (int t = index[s] - 1; t >= 0; t--) {
        ans[t] = max(value[t], ans[t + 1]);
    }
    for (int t = index[s] + 1; t < N; t++) {
        ans[t] = max(value[t - 1], ans[t - 1]);
    }

    while (Q--) {
        int t, k;
        cin >> t >> k, t--;
        assert(0 <= s && s < N && 0 <= t && t < N);
        cout << (k >= ans[index[t]] ? "Yes\n" : "No\n");
    }
    return 0;
}