#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

template <uint32_t mod>
struct modnum {
    using u32 = uint32_t;
    using u64 = uint64_t;
    static_assert(mod > 0 && mod < UINT_MAX / 2);

    uint32_t n;

    constexpr modnum() : n(0) {}
    constexpr modnum(u64 v) : n(v >= mod ? v % mod : v) {}
    constexpr modnum(u32 v) : n(v >= mod ? v % mod : v) {}
    constexpr modnum(int64_t v) : modnum(v >= 0 ? u64(v) : u64(mod + v % int(mod))) {}
    constexpr modnum(int32_t v) : modnum(v >= 0 ? u32(v) : u32(mod + v % int(mod))) {}
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
    friend constexpr modnum modpow(modnum b, long e) {
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
    constexpr modnum &operator++() { return n = fit(n + 1), *this; }
    constexpr modnum &operator--() { return n = fit(mod + n - 1), *this; }
    constexpr modnum &operator+=(modnum v) { return n = fit(n + v.n), *this; }
    constexpr modnum &operator-=(modnum v) { return n = fit(mod + n - v.n), *this; }
    constexpr modnum &operator*=(modnum v) { return n = (u64(n) * v.n) % mod, *this; }
    constexpr modnum &operator/=(modnum v) { return *this *= v.inv(); }

    friend constexpr modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend constexpr modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend constexpr modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend constexpr modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend constexpr bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend constexpr bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream &operator<<(ostream &out, modnum v) { return out << v.n; }
    friend istream &operator>>(istream &in, modnum &v) {
        int64_t n;
        return in >> n, v = modnum(n), in;
    }
};

using num = modnum<998244353>;

void simulate() {
    vector<bool> white = {0, 0, 0, 1, 1, 1};
    vector<int> weight = {3, 5, 7, 5, 7, 9};
    assert(white.size() == weight.size());

    const int N = white.size();
    const int M = 6;
    const int RUNS = 10'000'000;
    vector<double> sum(N);

    mt19937 mt(random_device{}());
    for (int r = 0; r < RUNS; r++) {
        vector<int> current = weight;
        for (int m = 0; m < M; m++) {
            discrete_distribution<int> distd(begin(current), end(current));
            int i = distd(mt);
            if (white[i]) {
                current[i]++;
            } else {
                current[i]--;
            }
        }
        for (int i = 0; i < N; i++) {
            sum[i] += current[i];
        }
    }
    for (int i = 0; i < N; i++) {
        sum[i] /= RUNS;
    }

    debug(sum);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    // simulate(); // we have linearity of expectation

    int N, M;
    cin >> N >> M;
    vector<bool> white(N); // likes white, dislikes black (lol)
    vector<int> weight(N);
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        white[i] = b;
    }
    for (int i = 0; i < N; i++) {
        cin >> weight[i];
    }

    int W = 0, B = 0;
    for (int i = 0; i < N; i++) {
        if (white[i]) {
            W += weight[i];
        } else {
            B += weight[i];
        }
    }
    assert(W > 0);
    int X = W - B;

    // W-B increases by one every trial
    // W-B=X+m => W=X+B+m
    // dp[m][b]: probability that on the m-th trial we'll have b blacks

    vector<unordered_map<int, num>> dp(M + 1);
    dp[0][B] = 1;

    // expected number of times we pick W or B
    num ew = 0;
    num eb = 0;

    for (int m = 1; m <= M; m++) {
        for (auto [b, p] : dp[m - 1]) {
            int w = X + b + m - 1;
            assert(w > 0);
            // probability of playing white: w/(w+b)
            if (w > 0) { // always true
                dp[m][b] += p * w / (w + b);
                ew += p * w / (w + b);
            }
            // probability of playing black: b/(w+b)
            if (b > 0) {
                dp[m][b - 1] += p * b / (w + b);
                eb += p * b / (w + b);
            }
        }
    }

    // linearity of expectation!
    vector<num> ans(N);
    for (int i = 0; i < N; i++) {
        if (white[i]) {
            num w = weight[i];
            ans[i] = w + w * ew / W;
        } else {
            num b = weight[i];
            ans[i] = b - b * eb / B;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}