#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <uint32_t mod>
struct modnum {
    // change these if you need another size of integers
    static constexpr inline uint32_t MOD = mod;
    using u32 = uint32_t;
    using u64 = uint64_t;
    using i32 = int32_t;
    using i64 = int64_t;
    static_assert(mod > 0 && mod < UINT_MAX / 2);

    u32 n;

    constexpr modnum() : n(0) {}
    constexpr modnum(u64 v) : n(v >= mod ? v % mod : v) {}
    constexpr modnum(u32 v) : n(v >= mod ? v % mod : v) {}
    constexpr modnum(i64 v) : modnum(v >= 0 ? u64(v) : u64(mod + v % int(mod))) {}
    constexpr modnum(i32 v) : modnum(v >= 0 ? u32(v) : u32(mod + v % int(mod))) {}
    explicit constexpr operator int() const { return n; }
    explicit constexpr operator bool() const { return n != 0; }

    static constexpr u32 fit(u32 x) { return x >= mod ? x - mod : x; }
    static constexpr int modinv(u32 x) {
        int nx = 1, ny = 0;
        u32 y = mod;
        while (x) {
            auto k = y / x;
            y = y % x;
            ny = ny - k * nx;
            swap(x, y), swap(nx, ny);
        }
        return ny < 0 ? mod + ny : ny;
    }
    friend constexpr modnum modpow(modnum b, int64_t e) {
        modnum p = 1;
        while (e > 0) {
            if (e & 1)
                p = p * b;
            if (e >>= 1)
                b = b * b;
        }
        return p;
    }

    constexpr modnum inv() const { return modinv(n); }
    constexpr modnum operator-() const { return n == 0 ? n : mod - n; }
    constexpr modnum operator+() const { return *this; }
    constexpr modnum operator++(int) { return n = fit(n + 1), *this - 1; }
    constexpr modnum operator--(int) { return n = fit(mod + n - 1), *this + 1; }
    constexpr modnum& operator++() { return n = fit(n + 1), *this; }
    constexpr modnum& operator--() { return n = fit(mod + n - 1), *this; }
    constexpr modnum& operator+=(modnum v) { return n = fit(n + v.n), *this; }
    constexpr modnum& operator-=(modnum v) { return n = fit(mod + n - v.n), *this; }
    constexpr modnum& operator*=(modnum v) { return n = (u64(n) * v.n) % mod, *this; }
    constexpr modnum& operator/=(modnum v) { return *this *= v.inv(); }

    friend constexpr modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend constexpr modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend constexpr modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend constexpr modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend constexpr bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend constexpr bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream& operator<<(ostream& out, modnum v) { return out << v.n; }
    friend istream& operator>>(istream& in, modnum& v) {
        i64 n;
        return in >> n, v = modnum(n), in;
    }
};

using num = modnum<1'000'000'007>;

template <typename Node>
struct persistent_segtree {
    vector<Node> node;
    vector<array<int, 2>> kids;
    vector<int> roots;

    persistent_segtree() = default;

    int num_nodes() const { return node.size(); }
    int versions() const { return roots.size(); }

    // After you're done building the dynamic tree, add a root to use
    int add_root(int u) {
        int version = roots.size();
        roots.push_back(u);
        return version;
    }

    // Sparse: build an arbitrary sized tree where nodes just point back to themselves
    int build_sparse(Node init) {
        int u = node.size();
        node.push_back(init);
        kids.push_back({u, u});
        return u;
    }

    // Concatenation: # nodes must be a power of two and all have the same length
    int build_concat(const vector<int>& leaves) {
        int N = leaves.size();
        int u = node.size();
        int M = N / 2;
        assert((N & (N - 1)) == 0 && N > 1);
        node.resize(u + N);
        kids.resize(u + N);
        for (int i = 0; i < M; i++) {
            kids[u + i + M] = {leaves[i << 1], leaves[i << 1 | 1]};
            pushup(u + i + M);
        }
        for (int i = M - 1; i > 0; i--) {
            kids[u + i] = {u + (i << 1), u + (i << 1 | 1)};
            pushup(u + i);
        }
        return u + 1;
    }

    // Levels: # levels nodes are added
    int build_levels(int leaf, int levels) {
        assert(levels > 0 && leaf < int(node.size()));
        int r = node.size();
        node.resize(r + levels);
        kids.resize(r + levels);
        kids[r + levels - 1] = {leaf, leaf};
        pushup(r + levels - 1);
        for (int u = r + levels - 2; u >= r; u--) {
            kids[u] = {u + 1, u + 1};
            pushup(u);
        }
        return r;
    }

    // Array: For an array of size N=R-L, build a straightforward segtree with 2N-1 nodes
    template <typename T>
    int build_array(int L, int R, const vector<T>& arr, int s = 0) {
        int N = R - L;
        int u = node.size();
        node.resize(u + 2 * N - 1);
        kids.resize(u + 2 * N - 1);
        auto dfs = [&](const auto& self, int l, int r) -> int {
            if (l + 1 == r) {
                kids[u] = {-1, -1};
                node[u] = Node(arr[l - s]);
            } else {
                int m = l + (r - l) / 2;
                int a = self(self, l, m);
                int b = self(self, m, r);
                kids[u] = {a, b};
                pushup(u);
            }
            return u++;
        };
        return dfs(dfs, L, R);
    }

    auto query_point(int version, int l, int r, int Q) {
        assert(0 <= version && version < versions());
        return query_point_node(roots[version], l, r, Q);
    }

    template <typename Update>
    int update_point(int version, int l, int r, int Q, Update&& update) {
        assert(0 <= version && version < versions());
        roots.push_back(update_point_node(roots[version], l, r, Q, update));
        return roots.size() - 1;
    }

    auto query_range(int version, int l, int r, int qL, int qR) {
        assert(0 <= version && version < versions());
        return query_range_node(roots[version], l, r, qL, qR);
    }

  private:
    static Node combine(const Node& x, const Node& y) {
        Node ans;
        ans.pushup(x, y);
        return ans;
    }
    template <typename Update>
    void apply(int u, Update&& update) {
        if constexpr (Node::RANGES) {
            node[u].apply(update, 1);
        } else {
            node[u].apply(update);
        }
    }
    void pushup(int u) {
        node[u].pushup(node[kids[u][0]], node[kids[u][1]]); //
    }

    auto query_point_node(int u, int l, int r, int Q) {
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (Q < m) {
                u = kids[u][0], r = m;
            } else {
                u = kids[u][1], l = m;
            }
        }
        return node[u];
    }

    template <typename Update>
    int update_point_node(int u, int l, int r, int Q, Update&& update) {
        static thread_local vector<int> dfs;
        int x = u = clone_node(u);
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            dfs.push_back(u);
            if (Q < m) {
                u = kids[u][0] = clone_node(kids[u][0]), r = m;
            } else {
                u = kids[u][1] = clone_node(kids[u][1]), l = m;
            }
        }
        dfs.push_back(u);
        apply(u, update);
        for (int B = dfs.size(), i = B - 2; i >= 0; i--) {
            pushup(dfs[i]);
        }
        dfs.clear();
        return x;
    }

    auto query_range_node(int u, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) {
            return node[u];
        }
        int m = l + (r - l) / 2;
        auto [a, b] = kids[u];
        if (qR <= m) {
            return query_range_node(a, l, m, qL, qR);
        } else if (m <= qL) {
            return query_range_node(b, m, r, qL, qR);
        } else {
            return combine(query_range_node(a, l, m, qL, m),
                           query_range_node(b, m, r, m, qR));
        }
    }

    int clone_node(int u) {
        int v = node.size();
        node.push_back(node[u]);
        kids.push_back(kids[u]);
        return v;
    }
};

template <typename T>
struct sum_segnode {
    static constexpr bool LAZY = true, RANGES = true, REVERSE = false;
    T value = 0;
    T lazy = 0;

    sum_segnode() = default;
    sum_segnode(T v) : value(v) {}
    operator T const &() const { return value; }

    void pushup(const sum_segnode& lhs, const sum_segnode& rhs) {
        value = lhs.value + rhs.value;
    }
    void pushdown(sum_segnode& lhs, sum_segnode& rhs, int l, int r) {
        if (lazy != 0) {
            lhs.apply(lazy, l);
            rhs.apply(lazy, r);
            lazy = 0;
        }
    }
    void apply(T add, int s) {
        value += add * s;
        lazy += add;
    }
};

using node = sum_segnode<num>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N;
    cin >> N;

    constexpr int A_EVENT = 0, B_EVENT = 1;
    vector<int> A(N + 1), B(N + 1);
    vector<array<int, 2>> time(2 * N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        time[A[i]] = {i, A_EVENT};
        time[B[i]] = {i, B_EVENT};
    }

    vector<int> version(N + 1);
    vector<num> here(2 * N + 1);

    persistent_segtree<node> seg;
    int v = seg.add_root(seg.build_sparse(node(0)));
    const int L = 1, R = 2 * N + 1;

    // First phase, find time travel counts
    num cur = 0;
    for (int t = 1; t <= 2 * N; t++) {
        auto [i, type] = time[t];
        if (type == B_EVENT) {
            num after = seg.query_range(v, L, R, A[i], B[i]);
            version[i] = v;
            v = seg.update_point(v, L, R, A[i], 1 + after);

            here[A[i]] = cur + 1;
            here[B[i]] = cur + 1 + after;
            cur += 1 + after;
        }
    }

    int T;
    cin >> T;
    vector<int> visit(T);
    set<int> visset;
    for (int i = 0; i < T; i++) {
        cin >> visit[i];
        visset.insert(visit[i]);
    }

    sort(begin(visit), end(visit), [&](int i, int j) { return B[i] > B[j]; });
    int last = visit.front();
    visit.erase(begin(visit));

    int prev = last;
    num ans = here[A[last]];

    for (int i : visit) {
        if (A[i] > A[prev]) {
            auto add = 1 + seg.query_range(version[i], L, R, A[prev], B[i]);
            ans += add;
            prev = i;
        }
    }

    cout << ans << '\n';
    return 0;
}