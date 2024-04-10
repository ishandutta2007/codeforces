#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

inline void next_lexicographical_mask(unsigned& v) {
    unsigned c = v & -v, r = v + c;
    v = c ? (((r ^ v) >> 2) / c) | r : 0;
}
#define FOR_EACH_MASK(mask, size, max_size)                                            \
    for (unsigned mask = (1 << (size)) - 1, m##mask = 1 << (max_size); mask < m##mask; \
         next_lexicographical_mask(mask))

// includes mask but not 0
#define FOR_EACH_NONZERO_SUBSET(subset, mask)                                       \
    for (remove_const<decltype(mask)>::type s##subset = (mask), subset = s##subset; \
         subset; subset = s##subset & (subset - 1))
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

    friend istream& operator>>(istream& in, tensor& t) {
        for (int i = 0; i < t.len; i++) {
            in >> t.data[i];
        }
        return in;
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
            assert(0 <= idx[i] && idx[i] < shape[i]);
            res += idx[i] * strides[i];
        }
        return res;
    }

  public:
    T& operator[](array<int, NDIMS> idx) const { return data[flatten_index(idx)]; }
    T* operator[](array<int, NDIMS - 1> idx) const { return data + flatten_index(idx); }
};

bool contains(int mask, int bit) { return (mask >> bit) & 1; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<array<int, 2>> edges(M);
    vector<array<int, 3>> lca(Q);
    vector<int> adj(N);

    for (auto& [u, v] : edges) {
        cin >> u >> v, u--, v--;
        adj[u] |= 1 << v;
        adj[v] |= 1 << u;
    }
    for (auto& [x, y, a] : lca) {
        cin >> x >> y >> a, x--, y--, a--;
    }

    const int FULL = (1 << N) - 1;

    tensor<bool, 2> valid({N, 1 << N});
    for (int p = 0; p < N; p++) {
        FOR_EACH_NONZERO_SUBSET(t, FULL ^ (1 << p)) {
            valid[{p, t}] = __builtin_popcount(adj[p] & 1) <= 1;

            for (auto [u, v, a] : lca) {
                valid[{p, t}] &= !(a == p && contains(t, u) && contains(t, v));
                valid[{p, t}] &= !(contains(t, a) && !(contains(t, u) && contains(t, v)));
            }

            for (auto [u, v] : edges) {
                valid[{p, t}] &= !(u != p && v != p && contains(t, u) != contains(t, v));
            }
        }
    }

    tensor<long, 2> dp({N, 1 << N});
    for (int u = 0; u < N; u++) {
        dp[{u, 1 << u}] = 1;
    }

    for (int size = 2; size <= N; size++) {
        for (int p = 0; p < N; p++) {
            FOR_EACH_MASK (S, size, N) {
                if (!contains(S, p)) {
                    continue;
                }
                int s = S ^ (1 << p);
                int x = __builtin_ctz(s);
                FOR_EACH_NONZERO_SUBSET(t, s) {
                    if (contains(t, x) && valid[{p, t}]) {
                        int f = t ^ s;
                        if (adj[p] & t) {
                            int r = __builtin_ctz(adj[p] & t);
                            dp[{p, S}] += dp[{r, t}] * dp[{p, f | (1 << p)}];
                        } else {
                            for (int r = 0; r < N; r++) {
                                if (contains(t, r)) {
                                    dp[{p, S}] += dp[{r, t}] * dp[{p, f | (1 << p)}];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << dp[{0, FULL}] << '\n';
    return 0;
}