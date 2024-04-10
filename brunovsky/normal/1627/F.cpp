#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Container>
struct less_container {
    const Container* cont = nullptr;
    less_container() = default;
    less_container(const Container& cont) : cont(&cont) {}
    inline bool operator()(int u, int v) const {
        return tie((*cont)[u], u) < tie((*cont)[v], v);
    }
};

template <typename Compare = less<>>
struct pairing_int_heap {
    struct node_t {
        int parent = 0, child = 0, next = 0, prev = 0;
    }; // elements are shifted by 1 to allow 0 to be used as a scratchpad
    vector<node_t> node;
    int root = 0;
    Compare comp;

    explicit pairing_int_heap(int N = 0, const Compare& comp = Compare())
        : node(N + 1), comp(comp) {}

    bool empty() const { return root == 0; }
    bool contains(int u) const { return u++, node[u].parent != 0; }
    int top() const { return root - 1; }

    void push(int u) {
        assert(!contains(u)), u++;
        node[u].parent = -1;
        root = safe_meld(root, u);
    }
    int pop() {
        assert(!empty());
        int u = root;
        root = two_pass_pairing(u);
        node[root].parent = -1;
        node[u] = node_t();
        return u - 1;
    }
    void improve(int u) {
        assert(!empty() && contains(u)), u++;
        if (u != root && do_comp(u, node[u].parent)) {
            take(u), root = meld(root, u);
        }
    }
    void push_or_improve(int u) {
        if (contains(u)) {
            improve(u);
        } else {
            push(u);
        }
    }
    void adjust(int u) {
        erase(u);
        push(u);
    }
    void erase(int u) {
        assert(contains(u)), u++;
        if (u == root) {
            pop();
        } else {
            take(u);
            int v = two_pass_pairing(u);
            root = safe_meld(root, v);
            node[root].parent = -1;
            node[u] = node_t();
        }
    }
    void clear() {
        if (!empty()) {
            clear_rec(root), root = 0;
        }
    }
    void fill() {
        for (int u = 1, N = node.size() - 1; u <= N; u++) {
            if (!contains(u)) {
                push(u);
            }
        }
    }

  private:
    bool do_comp(int u, int v) const { return comp(u - 1, v - 1); }
    int meld(int u, int v) { return do_comp(u, v) ? splice(u, v) : splice(v, u); }
    int safe_meld(int u, int v) {
        if (u == 0 || v == 0 || u == v)
            return u ? u : v;
        return meld(u, v);
    }
    int splice(int u, int v) {
        node[node[u].child].prev = v;
        node[v].next = node[u].child, node[u].child = v;
        return node[v].prev = node[v].parent = u;
    }
    void take(int u) {
        assert(node[u].parent > 0);
        if (node[node[u].parent].child == u) {
            node[node[u].parent].child = node[u].next;
        } else {
            node[node[u].prev].next = node[u].next;
        }
        node[node[u].next].prev = node[u].prev;
    }
    int two_pass_pairing(int n) {
        if (node[n].child == 0)
            return 0;
        int u = node[n].child, v = node[u].next, w;
        while (v && node[v].next) {
            w = node[node[v].next].next;
            u = node[u].next = v = meld(v, node[v].next);
            v = node[v].next = w;
        }
        u = node[n].child, v = node[u].next;
        while (v) {
            w = node[v].next, u = meld(u, v), v = w;
        }
        return u;
    }
    void clear_rec(int u) {
        for (int v = node[u].child, w = node[v].next; v; v = w, w = node[v].next) {
            clear_rec(v);
        }
        node[u] = node_t();
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<array<int, 4>> arr(N);

        for (auto& [a, b, c, d] : arr) {
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;
            if (a == c && b > d) {
                swap(b, d);
            } else if (b == d && a > c) {
                swap(a, c);
            }
        }

        vector<int> border, mirror;
        vector<array<int, 2>> cells;
        vector<vector<int>> cellid(K + 1, vector<int>(K + 1));
        int P = 0;

        for (int i = 0; i <= K; i++) {
            for (int j = 0; j <= K; j++) {
                cells.push_back({i, j});
                if (i == 0 || j == 0 || i == K || j == K) {
                    border.push_back(P);
                }
                cellid[i][j] = P++;
            }
        }

        for (int i = 0; i <= K; i++) {
            for (int j = 0; j <= K; j++) {
                mirror.push_back(cellid[K - i][K - j]);
            }
        }

        vector<int> down(P), right(P);
        for (auto [a, b, c, d] : arr) {
            int id = cellid[c][d];
            a == c ? down[id]++ : right[id]++;
        }

        auto move_cost = [&](int i, int j) {
            auto [a, b] = cells[i];
            auto [c, d] = cells[j];
            int id = min(i, j);
            return a == c ? right[id] : down[id];
        };

        static constexpr int dd[4][2] = {{+1, 0}, {-1, 0}, {0, -1}, {0, +1}};
        vector<vector<int>> adj(P);
        for (int i = 0; i <= K; i++) {
            for (int j = 0; j <= K; j++) {
                for (auto [dx, dy] : dd) {
                    int x = i + dx, y = j + dy;
                    if (x >= 0 && y >= 0 && x <= K && y <= K) {
                        adj[cellid[i][j]].emplace_back(cellid[x][y]);
                    }
                }
            }
        }

        // Now bfs from the center
        constexpr int inf = 1e9;
        vector<int> dist(P, inf);
        pairing_int_heap<less_container<vector<int>>> heap(P, dist);

        int center = cellid[K / 2][K / 2];
        dist[center] = 0;
        heap.push(center);

        while (!heap.empty()) {
            int u = heap.pop();
            for (int v : adj[u]) {
                int c = move_cost(u, v);
                int d = move_cost(mirror[u], mirror[v]);
                c += d;
                if (dist[v] > dist[u] + c) {
                    dist[v] = dist[u] + c;
                    heap.push_or_improve(v);
                }
            }
        }

        int ans = inf;
        for (int i : border) {
            ans = min(ans, dist[i]);
        }
        cout << N - ans << '\n';
    }
    return 0;
}