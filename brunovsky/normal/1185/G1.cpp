#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

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
    friend ostream& operator<<(ostream& out, tensor& t) {
        for (int i = 0; i < t.len; i++) {
            out << (i > 0 ? " " : "") << t.data[i];
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
            assert(0 <= idx[i] && idx[i] < shape[i]);
            res += idx[i] * strides[i];
        }
        return res;
    }

  public:
    T& operator[](array<int, NDIMS> idx) const { return data[flatten_index(idx)]; }
    T* operator[](array<int, NDIMS - 1> idx) const { return data + flatten_index(idx); }
};

template <uint32_t mod>
struct modnum {
    // change these if you need another size of integers
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

/**
 * For every possible subset sum, compute how many subsets of fixed size give this sum.
 */
auto dense_subset_sum_sized_count(const vector<int>& nums) {
    int N = nums.size();
    int S = accumulate(begin(nums), end(nums), 0);

    vector<int> sums(N + 1);
    for (int i = 0; i < N; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }

    tensor<num, 2> dp({S + 1, N + 1}, 0);
    dp[{0, 0}] = 1;

    for (int i = 0; i < N; i++) {
        for (int size = i; size >= 0; size--) {
            for (int sum = 0; sum <= sums[i]; sum++) {
                dp[{sum + nums[i], size + 1}] += dp[{sum, size}];
            }
        }
    }

    return make_pair(S, move(dp));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, T;
    cin >> N >> T;

    array<vector<int>, 3> songs;
    for (int i = 0; i < N; i++) {
        int t, g;
        cin >> t >> g, g--;
        songs[g].push_back(t);
    }

    int A = songs[0].size();
    int B = songs[1].size();
    int C = songs[2].size();
    assert(A + B + C == N);

    auto [Asum, adp] = dense_subset_sum_sized_count(songs[0]);
    auto [Bsum, bdp] = dense_subset_sum_sized_count(songs[1]);
    auto [Csum, cdp] = dense_subset_sum_sized_count(songs[2]);

    tensor<num, 3> ways({A + 2, B + 2, C + 2});
    tensor<num, 4> ways_end({A + 2, B + 2, C + 2, 3}, 0);
    ways_end[{1, 0, 0, 0}] = 1;
    ways_end[{0, 1, 0, 1}] = 1;
    ways_end[{0, 0, 1, 2}] = 1;

    vector<num> fac(max({A, B, C}) + 1);
    fac[0] = 1;
    for (int i = 1; i <= max({A, B, C}); i++) {
        fac[i] = fac[i - 1] * i;
    }

    for (int a = 0; a <= A; a++) {
        for (int b = 0; b <= B; b++) {
            for (int c = 0; c <= C; c++) {
                ways_end[{a + 1, b, c, 0}] += ways_end[{a, b, c, 1}];
                ways_end[{a + 1, b, c, 0}] += ways_end[{a, b, c, 2}];
                ways_end[{a, b + 1, c, 1}] += ways_end[{a, b, c, 0}];
                ways_end[{a, b + 1, c, 1}] += ways_end[{a, b, c, 2}];
                ways_end[{a, b, c + 1, 2}] += ways_end[{a, b, c, 0}];
                ways_end[{a, b, c + 1, 2}] += ways_end[{a, b, c, 1}];
                ways[{a, b, c}] += ways_end[{a, b, c, 0}];
                ways[{a, b, c}] += ways_end[{a, b, c, 1}];
                ways[{a, b, c}] += ways_end[{a, b, c, 2}];
                ways[{a, b, c}] *= fac[a] * fac[b] * fac[c];
            }
        }
    }

    num ans = 0;
    for (int a = 0; a <= A; a++) {
        for (int x = 0; x <= Asum; x++) {
            if (adp[{x, a}]) {
                for (int b = 0; b <= B; b++) {
                    for (int y = 0; y <= Bsum && x + y <= T; y++) {
                        int z = T - x - y;
                        if (bdp[{y, b}] && z <= Csum) {
                            for (int c = 0; c <= C; c++) {
                                ans += adp[{x, a}] * bdp[{y, b}] * cdp[{z, c}] *
                                       ways[{a, b, c}];
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}