#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

struct modnum {
    static inline uint32_t mod;
    using u32 = uint32_t;
    using u64 = uint64_t;

    uint32_t n;

    modnum() : n(0) {}
    modnum(u64 v) : n(v >= mod ? v % mod : v) {}
    modnum(u32 v) : n(v >= mod ? v % mod : v) {}
    modnum(int64_t v) : modnum(v >= 0 ? u64(v) : u64(mod + v % int(mod))) {}
    modnum(int32_t v) : modnum(v >= 0 ? u32(v) : mod + v % int(mod)) {}
    explicit operator int() const { return n; }
    explicit operator bool() const { return n != 0; }

    static u32 fit(u32 x) { return x >= mod ? x - mod : x; }
    static int modinv(u32 x) {
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

    modnum inv() const { return modinv(n); }
    modnum operator-() const { return n == 0 ? n : mod - n; }
    modnum operator+() const { return *this; }
    modnum operator++(int) { return n = fit(n + 1), *this - 1; }
    modnum operator--(int) { return n = fit(mod + n - 1), *this + 1; }
    modnum& operator++() { return n = fit(n + 1), *this; }
    modnum& operator--() { return n = fit(mod + n - 1), *this; }
    modnum& operator+=(modnum v) { return n = fit(n + v.n), *this; }
    modnum& operator-=(modnum v) { return n = fit(mod + n - v.n), *this; }
    modnum& operator*=(modnum v) { return n = (u64(n) * v.n) % mod, *this; }
    modnum& operator/=(modnum v) { return *this *= v.inv(); }

    friend modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream& operator<<(ostream& out, modnum v) { return out << v.n; }
    friend istream& operator>>(istream& in, modnum& v) {
        int64_t n;
        return in >> n, v = modnum(n), in;
    }
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
        assign(shape_, t);
    }

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

    void assign(std::array<int, NDIMS> shape_, const T& t = T()) {
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
};

void brute(int LEN = 4) {
    string s(LEN, '0');
    iota(begin(s), end(s), '1');
    vector<int> cnt;
    do {
        int ans = 0;
        for (int i = 0, N = s.size(); i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                ans += s[i] > s[j];
            }
        }
        cnt.push_back(ans);
    } while (next_permutation(begin(s), end(s)));

    map<int, int> hist;

    int ans = 0;
    for (int i = 0, N = cnt.size(); i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans += cnt[i] > cnt[j];
        }
    }
    for (int i = 0, N = cnt.size(); i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cnt[i] >= cnt[j]) {
                hist[cnt[i] - cnt[j]]++;
            }
        }
    }
    cout << LEN << ' ' << ans << '\n';
    for (auto [n, c] : hist) {
        cout << "HIST " << n << ' ' << c << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N;
    cin >> N >> modnum::mod;
    // brute(2), brute(3), brute(4), brute(5), brute(6), brute(7);

    if (N <= 3 || modnum::mod == 1) {
        cout << 0 << endl;
        return 0;
    }
    const int O = N * (N + 1) / 2; // maximum number of inversions

    tensor<modnum, 2> inv({N + 1, O + 1});
    inv[{1, 0}] = 1;
    for (int n = 2; n <= N; n++) {
        inv[{n, 0}] = 1;
        for (int k = 1; k <= O; k++) {
            inv[{n, k}] = inv[{n - 1, k}] + inv[{n, k - 1}] -
                          (k >= n ? inv[{n - 1, k - n}] : 0);
        }
    }

    // how many permutations have
    tensor<modnum, 2> diff({N + 1, O + 1});
    for (int n = 1; n <= N; n++) {
        // how many ordered pairs of permutations of length n differ by =d inversions
        for (int d = 0; d <= O; d++) {
            for (int k = 0; k <= O - d; k++) {
                diff.at({n, d}) += inv[{n, k + d}] * inv[{n, k}];
            }
        }
        // how many pairs of permutations of length n differ by >=d inversions
        for (int i = O - 1; i >= 0; i--) {
            diff[{n, i}] += diff[{n, i + 1}];
        }
    }

    vector<modnum> dp(N + 1); // how many permutations
    for (int n = 1; n <= N; n++) {
        for (int d = 1; d < n; d++) {
            dp[n] += (n - d) * diff[{n - 1, d + 1}];
        }
    }
    modnum ans = 0, fac = 1;
    for (int n = N; n >= 1; n--) {
        ans += fac * dp[n];
        fac *= n;
    }
    cout << ans << '\n';
    return 0;
}