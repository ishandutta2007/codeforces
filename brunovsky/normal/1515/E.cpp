#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

inline namespace lib {

template <typename T, int NDIMS>
struct tensor_view {
    static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

  protected:
    std::array<int, NDIMS> shape;
    std::array<int, NDIMS> strides;
    T* data;

    tensor_view(std::array<int, NDIMS> shape_, std::array<int, NDIMS> strides_, T* data_)
        : shape(shape_), strides(strides_), data(data_) {}

  public:
    tensor_view() : shape{0}, strides{0}, data(nullptr) {}

  protected:
    int flatten_index(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) {
            res += idx[i] * strides[i];
        }
        return res;
    }
    int flatten_index_checked(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) {
            assert(0 <= idx[i] && idx[i] < shape[i]);
            res += idx[i] * strides[i];
        }
        return res;
    }

  public:
    T& operator[](std::array<int, NDIMS> idx) const { return data[flatten_index(idx)]; }
    T& at(std::array<int, NDIMS> idx) const { return data[flatten_index_checked(idx)]; }

    template <int D = NDIMS>
    typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type operator[](
        int idx) const {
        std::array<int, NDIMS - 1> nshape;
        std::copy(shape.begin() + 1, shape.end(), nshape.begin());
        std::array<int, NDIMS - 1> nstrides;
        std::copy(strides.begin() + 1, strides.end(), nstrides.begin());
        T* ndata = data + (strides[0] * idx);
        return tensor_view<T, NDIMS - 1>(nshape, nstrides, ndata);
    }
    template <int D = NDIMS>
    typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type at(int idx) const {
        assert(0 <= idx && idx < shape[0]);
        return operator[](idx);
    }

    template <int D = NDIMS>
    typename std::enable_if<(0 == D), T&>::type operator*() const {
        return *data;
    }

    template <typename U, int D>
    friend struct tensor_view;
    template <typename U, int D>
    friend struct tensor;
};

template <typename T, int NDIMS>
struct tensor {
    static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

  protected:
    std::array<int, NDIMS> shape;
    std::array<int, NDIMS> strides;
    int len;
    T* data;

  public:
    tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

    explicit tensor(std::array<int, NDIMS> shape_, const T& t = T()) {
        shape = shape_;
        strides[NDIMS - 1] = 1;
        for (int i = NDIMS - 1; i > 0; i--) {
            strides[i - 1] = strides[i] * shape[i];
        }
        len = strides[0] * shape[0];
        data = new T[len];
        std::fill(data, data + len, t);
    }

    tensor(const tensor& o)
        : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
        for (int i = 0; i < len; i++) {
            data[i] = o.data[i];
        }
    }

    tensor& operator=(tensor&& o) noexcept {
        using std::swap;
        swap(shape, o.shape);
        swap(strides, o.strides);
        swap(len, o.len);
        swap(data, o.data);
        return *this;
    }
    tensor(tensor&& o) : tensor() { *this = std::move(o); }
    tensor& operator=(const tensor& o) { return *this = tensor(o); }
    ~tensor() { delete[] data; }

    auto size() const { return shape; }

    using view_t = tensor_view<T, NDIMS>;
    view_t view() { return tensor_view<T, NDIMS>(shape, strides, data); }

    using const_view_t = tensor_view<const T, NDIMS>;
    const_view_t view() const {
        return tensor_view<const T, NDIMS>(shape, strides, data);
    }

  protected:
    int flatten_index(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) {
            res += idx[i] * strides[i];
        }
        return res;
    }
    int flatten_index_checked(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) {
            assert(0 <= idx[i] && idx[i] < shape[i]);
            res += idx[i] * strides[i];
        }
        return res;
    }

  public:
    T& operator[](std::array<int, NDIMS> idx) const { return data[flatten_index(idx)]; }
    T& at(std::array<int, NDIMS> idx) const { return data[flatten_index_checked(idx)]; }

    template <int D = NDIMS>
    typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type operator[](
        int idx) {
        return view()[idx];
    }
    template <int D = NDIMS>
    typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type at(int idx) {
        return view().at(idx);
    }

    template <int D = NDIMS>
    typename std::enable_if<(0 < D), tensor_view<const T, NDIMS - 1>>::type operator[](
        int idx) const {
        return view()[idx];
    }
    template <int D = NDIMS>
    typename std::enable_if<(0 < D), tensor_view<const T, NDIMS - 1>>::type at(
        int idx) const {
        return view().at(idx);
    }

    template <int D = NDIMS>
    typename std::enable_if<(0 == D), T&>::type operator*() {
        return *view();
    }
    template <int D = NDIMS>
    typename std::enable_if<(0 == D), const T&>::type operator*() const {
        return *view();
    }
};

} // namespace lib

struct modnum {
    static inline int mod = 0;
    int n;

    modnum() : n(0) {}
    modnum(int v) : n(fit(v % mod)) {}
    explicit operator int() const { return n; }
    explicit operator bool() const { return n != 0; }

    static int fit(int v) { return v >= mod ? v - mod : (v < 0 ? v + mod : v); }
    static int modinv(int v, int m = mod) {
        v %= m, assert(v);
        return v == 1 ? 1 : (m - 1LL * modinv(m, v) * m / v);
    }
    friend modnum modpow(modnum b, long e) {
        modnum p = 1;
        while (e > 0) {
            if (e & 1)
                p = p * b;
            if (e >>= 1)
                b = b * b;
        }
        return p;
    }

    modnum inv() const { return {modinv(n)}; }
    modnum operator-() const { return {fit(n)}; }
    modnum operator+() const { return {n}; }
    modnum operator++(int) { return n = fit(n + 1), *this - 1; }
    modnum operator--(int) { return n = fit(n - 1), *this + 1; }
    modnum& operator++() { return n = fit(n + 1), *this; }
    modnum& operator--() { return n = fit(n - 1), *this; }
    modnum& operator+=(modnum v) { return n = fit(n + v.n), *this; }
    modnum& operator-=(modnum v) { return n = fit(n - v.n), *this; }
    modnum& operator*=(modnum v) { return n = (1LL * n * v.n) % mod, *this; }
    modnum& operator/=(modnum v) { return n = (1LL * n * modinv(v.n)) % mod, *this; }

    friend modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream& operator<<(ostream& out, modnum v) { return out << v.n; }
    friend istream& operator>>(istream& in, modnum& v) {
        return in >> v.n, v.n = fit(v.n % mod), in;
    }
};

using num = modnum;
vector<num> fac, ifac, pow2;

auto pascal_sieve(int N) {
    fac.resize(N + 1), ifac.resize(N + 1), pow2.resize(N + 1);
    fac[0] = fac[1] = ifac[1] = pow2[0] = 1;

    for (int n = 1; n <= N; n++) {
        fac[n] = n * fac[n - 1];
        pow2[n] = 2 * pow2[n - 1];
    }
    ifac[N] = fac[N].inv();
    for (int n = N; n >= 1; n--) {
        ifac[n - 1] = n * ifac[n];
    }
}

auto choose(int n, int k) {
    assert(0 <= k && k <= n);
    return fac[n] * ifac[k] * ifac[n - k];
}

auto solve() {
    int N;
    cin >> N >> num::mod;
    pascal_sieve(2 * N);

    // dp[n][manual]
    tensor<num, 2> dp({N + 1, N + 1});
    dp[{1, 1}] = 1;

    for (int n = 2; n <= N; n++) {
        dp[{n, n}] = pow2[n - 1];
        for (int m = 1; m <= n; m++) {
            for (int k = 1; k <= m && k < n; k++) { // append k contiguous
                dp[{n, m}] += dp[{n - k - 1, m - k}] * choose(m, k) * pow2[k - 1];
            }
        }
    }

    num ans = 0;
    for (int len = 1; len <= N; len++) {
        ans += dp[{N, len}];
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}