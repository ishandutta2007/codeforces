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

struct Ladder {
    int a, b, c, d, h, id;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> cost(N);
        for (int i = 0; i < N; i++) {
            cin >> cost[i];
        }

        vector<array<int, 2>> places;
        vector<Ladder> ladders(K);

        places.push_back({0, 0});
        places.push_back({N - 1, M - 1});

        for (int i = 0; i < K; i++) {
            auto& [a, b, c, d, h, id] = ladders[i];
            cin >> a >> b >> c >> d >> h;
            a--, b--, c--, d--, id = i;
            places.push_back({a, b});
            places.push_back({c, d});
        }

        sort(begin(places), end(places));
        places.erase(unique(begin(places), end(places)), end(places));

        auto get_place_id = [&](int a, int b) {
            array<int, 2> cell = {a, b};
            int i = lower_bound(begin(places), end(places), cell) - begin(places);
            assert(places[i] == cell);
            return i;
        };

        int P = places.size();
        vector<vector<int>> walk(P);
        vector<vector<pair<int, int>>> climb(P);

        for (int p = 0; p < P; p++) {
            auto [a, b] = places[p];
            if (p > 0 && places[p - 1][0] == a) {
                walk[p].push_back(p - 1);
                walk[p - 1].push_back(p);
            }
        }
        for (int i = 0; i < K; i++) {
            auto [a, b, c, d, h, id] = ladders[i];
            int x = get_place_id(a, b);
            int y = get_place_id(c, d);
            climb[x].push_back({y, h});
        }

        constexpr int64_t inf = numeric_limits<int64_t>::max() / 2;
        vector<int64_t> dist(P, inf);
        dist[0] = 0;

        pairing_int_heap<less_container<vector<int64_t>>> heap(P, dist);

        for (int l = 0, r = 1; l < P; l = r++) {
            int floor = places[l][0];
            while (r < P && places[r][0] == floor) {
                r++;
            }

            if (*min_element(begin(dist) + l, begin(dist) + r) == inf) {
                continue;
            }

            for (int u = l; u < r; u++) {
                heap.push(u);
            }

            do {
                int u = heap.pop();
                for (int v : walk[u]) {
                    int64_t loss = 1LL * cost[floor] * abs(places[u][1] - places[v][1]);
                    if (dist[v] > dist[u] + loss) {
                        dist[v] = dist[u] + loss;
                        heap.push_or_improve(v);
                    }
                }
                for (auto [v, h] : climb[u]) {
                    if (dist[v] > dist[u] - h) {
                        dist[v] = dist[u] - h;
                    }
                }
            } while (!heap.empty());
        }

        if (dist[P - 1] == inf) {
            cout << "NO ESCAPE\n";
        } else {
            cout << dist[P - 1] << '\n';
        }
    }
    return 0;
}