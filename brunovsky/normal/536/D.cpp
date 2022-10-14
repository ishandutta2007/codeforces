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
        for (int u = 0, N = node.size() - 1; u < N; u++) {
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

template <typename T, int NDIMS>
struct tensor {
    static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

  protected:
    array<int, NDIMS> shape;
    array<int, NDIMS> strides;
    int len;
    T* data;

  public:
    tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

    explicit tensor(array<int, NDIMS> shape_, const T& t = T()) { assign(shape_, t); }

    tensor(const tensor& o)
        : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
        copy(o.data, o.data + len, data);
    }
    tensor(tensor&& o) : tensor() { *this = std::move(o); }

    tensor& operator=(const tensor& o) { return *this = tensor(o); }
    tensor& operator=(tensor&& o) noexcept {
        using std::swap;
        swap(shape, o.shape);
        swap(strides, o.strides);
        swap(len, o.len);
        swap(data, o.data);
        return *this;
    }
    ~tensor() { delete[] data; }

    void assign(array<int, NDIMS> shape_, const T& t = T()) {
        shape = shape_;
        strides[NDIMS - 1] = 1;
        for (int i = NDIMS - 1; i > 0; i--) {
            strides[i - 1] = strides[i] * shape[i];
        }
        len = strides[0] * shape[0];
        data = new T[len];
        std::fill(data, data + len, t);
    }

    const auto& size() const { return shape; }
    int size(int dim) const { return shape[dim]; }

    friend istream& operator>>(istream& in, tensor& t) {
        for (int i = 0; i < t.len; i++) {
            in >> t.data[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, tensor& t) {
        for (int i = 0; i < t.len; i++) {
            out << ' ' << t.data[i];
        }
        return out;
    }
    bool operator==(const tensor& o) const {
        return shape == o.shape && equal(data, data + len, o.data);
    }
    bool operator!=(const tensor& o) const { return !(*this == o); }

  private:
    template <size_t D>
    int flatten_index(array<int, D> idx) const {
        static_assert(1 <= D && D <= NDIMS);
        int res = 0;
        for (int i = 0; i < int(D); i++) {
            res += idx[i] * strides[i];
        }
        return res;
    }

  public:
    T& operator[](array<int, NDIMS> idx) const { return data[flatten_index(idx)]; }
    T* operator[](array<int, NDIMS - 1> idx) const { return data + flatten_index(idx); }
};

static const string S_WIN = "Break a heart";
static const string T_WIN = "Cry";
static const string DRAW = "Flowers";

template <typename T>
void setmax(T& a, T b) {
    a = max(a, b);
}
template <typename T>
void setmin(T& a, T b) {
    a = min(a, b);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, s, t;
    cin >> N >> M >> s >> t, s--, t--;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    static constexpr int64_t inf = INT64_MAX / 3;

    auto dijkstra = [&](int r) {
        vector<int64_t> dist(N, inf);
        dist[r] = 0;
        pairing_int_heap<less_container<vector<int64_t>>> heap(N, dist);
        heap.push(r);

        while (!heap.empty()) {
            int u = heap.pop();
            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    heap.push_or_improve(v);
                }
            }
        }

        return dist;
    };

    array<vector<int64_t>, 2> dist = {dijkstra(s), dijkstra(t)};
    array<vector<int>, 2> order = {}, rank = {};
    for (int r : {0, 1}) {
        order[r].assign(N, 0);
        rank[r].assign(N, 0);
        iota(begin(order[r]), end(order[r]), 0);
        sort(begin(order[r]), end(order[r]), [&](int u, int v) {
            return make_pair(dist[r][u], u) < make_pair(dist[r][v], v); //
        });
        for (int i = 1, R = 0; i < N; i++) {
            int u = order[r][i], p = order[r][i - 1];
            rank[r][u] = R += dist[r][u] > dist[r][p];
        }
    }
    int MA = rank[0][order[0][N - 1]] + 1;
    int MB = rank[1][order[1][N - 1]] + 1;

    tensor<int64_t, 2> sum({MA + 1, MB + 1});
    tensor<int, 2> count({MA + 1, MB + 1});
    for (int A = 0; A <= MA; A++) {
        int i = 0, j = 0, c = 0;
        int64_t t = 0;
        while (i < N && rank[0][order[0][i]] < A) {
            int u = order[0][i++];
            t += p[u], c++;
        }
        sum[{A, 0}] = t;
        count[{A, 0}] = c;
        for (int B = 1; B <= MB; B++) {
            while (j < N && rank[1][order[1][j]] < B) {
                int v = order[1][j++];
                t += rank[0][v] >= A ? p[v] : 0, c += rank[0][v] >= A;
            }
            sum[{A, B}] = t;
            count[{A, B}] = c;
        }
    }

    tensor<int, 3> next({MA + 1, MB + 1, 2});
    for (int A = 0; A <= MA; A++) {
        next[{A, MB, 1}] = -1;
        for (int B = MB - 1; B >= 0; B--) {
            if (count[{A, B}] == count[{A, B + 1}]) {
                next[{A, B, 1}] = next[{A, B + 1, 1}];
            } else {
                next[{A, B, 1}] = B + 1;
            }
        }
    }
    for (int B = 0; B <= MB; B++) {
        next[{MA, B, 0}] = -1;
        for (int A = MA - 1; A >= 0; A--) {
            if (count[{A, B}] == count[{A + 1, B}]) {
                next[{A, B, 0}] = next[{A + 1, B, 0}];
            } else {
                next[{A, B, 0}] = A + 1;
            }
        }
    }

    // DP State: {order[0][0,A) taken, order[1][0,B) taken, 0/1 mover}
    // DP Value: score 0 - score 1
    tensor<int64_t, 3> play({MA + 1, MB + 1, 2}), pass({MA + 1, MB + 1, 2});

    for (int s = MA + MB - 1; s >= 0; s--) {
        for (int A = MA, B = s - MA; A >= 0; A--, B++) {
            if (0 <= A && A <= MA && 0 <= B && B <= MB) {
                auto base = sum[{A, B}];
                int a = next[{A, B, 0}];
                int b = next[{A, B, 1}];
                if (a != -1) {
                    auto more = sum[{a, B}] - base;
                    play[{A, B, 0}] = pass[{a, B, 0}] + more;
                }
                if (b != -1) {
                    auto more = sum[{A, b}] - base;
                    play[{A, B, 1}] = pass[{A, b, 1}] - more;
                }
                pass[{A, B, 0}] = max(play[{A, B, 0}], play[{A, B, 1}]);
                pass[{A, B, 1}] = min(play[{A, B, 0}], play[{A, B, 1}]);
                if (A < MA) {
                    auto more = sum[{A + 1, B}] - base;
                    setmax(pass[{A, B, 0}], pass[{A + 1, B, 0}] + more);
                }
                if (B < MB) {
                    auto more = sum[{A, B + 1}] - base;
                    setmin(pass[{A, B, 1}], pass[{A, B + 1, 1}] - more);
                }
            }
        }
    }

    int64_t ans = play[{0, 0, 0}];
    debug(ans);

    if (ans > 0) {
        cout << S_WIN << '\n';
    } else if (ans < 0) {
        cout << T_WIN << '\n';
    } else {
        cout << DRAW << '\n';
    }
    return 0;
}