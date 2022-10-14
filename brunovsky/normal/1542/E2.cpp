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
    static inline uint32_t mod = 7;
    // change these if you need another size of integers
    using u32 = uint32_t;
    using u64 = uint64_t;
    using i32 = int32_t;
    using i64 = int64_t;

    u32 n;

    modnum() : n(0) {}
    modnum(u64 v) : n(v >= mod ? v % mod : v) {}
    modnum(u32 v) : n(v >= mod ? v % mod : v) {}
    modnum(i64 v) : modnum(v >= 0 ? u64(v) : u64(mod + v % int(mod))) {}
    modnum(i32 v) : modnum(v >= 0 ? u32(v) : mod + v % int(mod)) {}
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
    friend modnum modpow(modnum b, int64_t e) {
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
        i64 n;
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

using num = modnum;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N;
    cin >> N >> num::mod;
    if (N <= 3 || num::mod == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<num> inv = {1}; // inv[o]: number of permutations with o inversions
    vector<num> dp(N + 1);

    for (int n = 2; n < N; n++) {
        int O = n * (n - 1) / 2;
        vector<num> next_inv(O + 1);
        next_inv[0] = 1;
        for (int k = 1, X = inv.size(); k <= O; k++) {
            next_inv[k] = (k < X ? inv[k] : 0) + next_inv[k - 1] -
                          (k >= n ? inv[k - n] : 0);
        }
        inv = move(next_inv);

        vector<num> one(O + 2);
        vector<num> self(O + 2);
        for (int i = 0; i <= O; i++) {
            one[i + 1] = one[i] + inv[i];
            self[i + 1] = self[i] + i * inv[i];
        }

        // prepare the initial window for i=0
        num window = 0;

        for (int i = 1; i < O; i++) {
            // transition to i+1
            int lo = max(0, i - n);
            int hi = i - 1;
            window += (n - i + 1) * (one[hi + 1] - one[lo]);
            window += self[hi + 1] - self[lo];
            dp[n + 1] += window * inv[i + 1];
        }
    }

    num final = 0;
    num fac = 1;
    for (int i = 0; i < N; i++) {
        debug(i, fac, dp[N - i]);
        final += fac * dp[N - i];
        fac *= N - i;
    }
    cout << final << '\n';
    return 0;
}