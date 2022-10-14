#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename O, typename T>
auto compress(const vector<T>& u, T s = 0) {
    int N = u.size();
    if (N == 0)
        return vector<O>();

    vector<pair<T, int>> ps(N);
    for (int i = 0; i < N; i++) {
        ps[i] = {u[i], i};
    }
    sort(begin(ps), end(ps));

    vector<O> v(N);
    v[ps[0].second] = s;
    for (int i = 1; i < N; i++) {
        v[ps[i].second] = v[ps[i - 1].second] + (ps[i].first != ps[i - 1].first);
    }
    return v;
}

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
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    a = compress<int>(a);

    vector<int> vals(N, -1), pre(N), nxt(N);
    for (int i = 0; i < N; i++) {
        pre[i] = vals[a[i]], vals[a[i]] = i;
    }
    vals.assign(N, N);
    for (int i = N - 1; i >= 0; i--) {
        nxt[i] = vals[a[i]], vals[a[i]] = i;
    }

    constexpr int B = 512, inf = INT_MAX;

    int S = (N - 1) / B + 1;
    tensor<int, 2> blk({S, S});
    for (int l = 0; l < S; l++) {
        int ans = inf;
        for (int r = l; r < S; r++) {
            int s = r * B, e = min(N, s + B);
            for (int i = s; i < e; i++) {
                if (pre[i] >= l * B) {
                    ans = min(ans, i - pre[i]);
                }
            }
            blk[{l, r}] = ans;
        }
    }

    while (Q--) {
        int l, r;
        cin >> l >> r, l--;
        int bl = (l + B - 1) / B; // anything >=bl ok
        int br = r / B;           // anything  <br ok
        int ans = bl < br ? blk[{bl, br - 1}] : inf;
        int L = min(N, bl * B);
        int R = br * B;
        for (int i = l; i < L; i++) {
            if (nxt[i] < r) {
                ans = min(ans, nxt[i] - i);
            }
        }
        for (int i = r - 1; i >= R; i--) {
            if (pre[i] >= l) {
                ans = min(ans, i - pre[i]);
            }
        }
        cout << (ans == inf ? -1 : ans) << '\n';
    }

    return 0;
}