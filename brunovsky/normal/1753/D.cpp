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
struct binary_int_heap {
    vector<int> c, id;
    Compare comp;

    explicit binary_int_heap(int N = 0, const Compare& comp = Compare())
        : c(0, 0), id(N, -1), comp(comp) {}

    bool empty() const { return c.empty(); }
    size_t size() const { return c.size(); }
    bool contains(int u) const { return id[u] != -1; }
    int top() const {
        assert(!empty());
        return c[0];
    }
    void push(int u) {
        assert(!contains(u));
        id[u] = c.size(), c.push_back(u);
        heapify_up(id[u]);
    }
    int pop() {
        assert(!empty());
        int u = c[0];
        c[0] = c.back();
        id[c[0]] = 0, id[u] = -1;
        c.pop_back();
        heapify_down(0);
        return u;
    }
    void improve(int u) { assert(contains(u)), heapify_up(id[u]); }
    void decline(int u) { assert(contains(u)), heapify_down(id[u]); }
    void push_or_improve(int u) { contains(u) ? improve(u) : push(u); }
    void push_or_decline(int u) { contains(u) ? decline(u) : push(u); }
    void clear() {
        for (int u : c)
            id[u] = -1;
        c.clear();
    }
    void fill() {
        for (int u = 0, N = id.size(); u < N; u++) {
            if (!contains(u)) {
                push(u);
            }
        }
    }

  private:
    static int parent(int i) { return (i - 1) >> 1; }
    static int child(int i) { return i << 1 | 1; }
    void exchange(int i, int j) { swap(id[c[i]], id[c[j]]), swap(c[i], c[j]); }
    void heapify_up(int i) {
        while (i > 0 && comp(c[i], c[parent(i)])) { // while c[i] < c[parent(i)]
            exchange(i, parent(i)), i = parent(i);
        }
    }
    void heapify_down(int i) {
        int k, S = c.size();
        while ((k = child(i)) < S) {
            if (k + 1 < S && !comp(c[k], c[k + 1])) // if c[rchild(i)] <= c[lchild(i)]
                k++;
            if (!comp(c[k], c[i])) // break if c[i] <= c[minchild(i)]
                break;
            exchange(i, k), i = k;
        }
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, ROT, MOV;
    cin >> N >> M >> ROT >> MOV;

    vector<string> beach(N);
    for (int i = 0; i < N; i++) {
        cin >> beach[i];
    }

    auto fine = [&](int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < M && beach[r][c] != '#';
    };
    auto horiz = [&](int r, int c) { return fine(r, c) && beach[r][c] == 'L'; };
    auto vert = [&](int r, int c) { return fine(r, c) && beach[r][c] == 'U'; };
    auto mkid = [&](int r, int c) { return r * M + c; };
    auto gtid = [&](int id) { return make_pair(id / M, id % M); };

    constexpr int64_t inf = 1e18;
    vector<int64_t> dist(N * M, inf);
    binary_int_heap<less_container<vector<int64_t>>> heap(N * M, dist);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (beach[i][j] == '.') {
                int id = mkid(i, j);
                dist[id] = 0;
                heap.push(id);
            }
        }
    }

    constexpr int dd[4][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

    auto relax = [&](int r, int c, int64_t d) {
        int id = mkid(r, c);
        if (dist[id] > d) {
            dist[id] = d;
            heap.push_or_improve(id);
        }
    };

    int64_t ans = inf;

    while (heap.size()) {
        int s = heap.pop();
        auto [r, c] = gtid(s);
        int64_t d = dist[s];

        for (int x : {r - 1, r + 1}) {
            if (horiz(x, c)) {
                relax(x, c + 1, d + ROT);
            }
            if (horiz(x, c - 1)) {
                relax(x, c - 1, d + ROT);
            }
        }
        for (int y : {c - 1, c + 1}) {
            if (vert(r, y)) {
                relax(r + 1, y, d + ROT);
            }
            if (vert(r - 1, y)) {
                relax(r - 1, y, d + ROT);
            }
        }
        if (horiz(r, c + 1)) {
            relax(r, c + 2, d + MOV);
        }
        if (horiz(r, c - 2)) {
            relax(r, c - 2, d + MOV);
        }
        if (vert(r + 1, c)) {
            relax(r + 2, c, d + MOV);
        }
        if (vert(r - 2, c)) {
            relax(r - 2, c, d + MOV);
        }
        for (auto [dr, dc] : dd) {
            int x = r + dr, y = c + dc;
            int o = mkid(x, y);
            if (fine(x, y) && dist[o] < inf) {
                ans = min(ans, d + dist[o]);
            }
        }
    }

    cout << (ans == inf ? -1 : ans) << '\n';
    return 0;
}