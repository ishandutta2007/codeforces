#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> out(N);
    vector<int> deg(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        char c;
        cin >> u >> v >> ws >> c, u--, v--;
        out[u].emplace_back(v, c - 'a');
        deg[v]++;
    }
    vector<int> topo;
    for (int u = 0; u < N; u++) {
        if (deg[u] == 0) {
            topo.push_back(u);
        }
    }
    for (int i = 0; i < N; i++) {
        int u = topo[i];
        for (auto [v, c] : out[u]) {
            if (--deg[v] == 0) {
                topo.push_back(v);
            }
        }
    }

    const int A = 26;

    // DP State: {0 ball at l,1 ball at r,>=c,player}
    tensor<bool, 4> win({N, N, A, 2});
    for (int s = 2 * N - 3; s >= 0; s--) {
        for (int l = 0, r = s; l < N && r >= 0; l++, r--) {
            if (0 <= l && l < N && 0 <= r && r < N) {
                int a = topo[l], b = topo[r];
                for (int x = 0; x < A; x++) {
                    for (auto [v, c] : out[a]) {
                        win[{a, b, x, 0}] |= c >= x && !win[{v, b, c, 1}];
                    }
                    for (auto [v, c] : out[b]) {
                        win[{a, b, x, 1}] |= c >= x && !win[{a, v, c, 0}];
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        string ans(N, '.');
        for (int j = 0; j < N; j++) {
            ans[j] = win[{i, j, 0, 0}] ? 'A' : 'B';
        }
        cout << ans << '\n';
    }
    return 0;
}