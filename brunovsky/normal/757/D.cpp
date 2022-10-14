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
    static_assert(MOD > 0 && MOD < UINT_MAX / 2);

    u32 n;

    constexpr modnum() : n(0) {}
    constexpr modnum(u64 v) : n(v >= MOD ? v % MOD : v) {}
    constexpr modnum(u32 v) : n(v >= MOD ? v % MOD : v) {}
    constexpr modnum(i64 v) : modnum(v >= 0 ? u64(v) : u64(MOD + v % int(MOD))) {}
    constexpr modnum(i32 v) : modnum(v >= 0 ? u32(v) : u32(MOD + v % int(MOD))) {}
    explicit constexpr operator i32() const { return n; }
    explicit constexpr operator u32() const { return n; }
    explicit constexpr operator bool() const { return n != 0; }

    static constexpr u32 fit(u32 x) { return x >= MOD ? x - MOD : x; }
    static constexpr int modinv(u32 x) {
        int nx = 1, ny = 0;
        u32 y = MOD;
        while (x) {
            auto k = y / x;
            y = y % x;
            ny = ny - k * nx;
            swap(x, y), swap(nx, ny);
        }
        return ny < 0 ? MOD + ny : ny;
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
    constexpr modnum operator-() const { return n == 0 ? n : MOD - n; }
    constexpr modnum operator+() const { return *this; }
    constexpr modnum operator++(int) { return n = fit(n + 1), *this - 1; }
    constexpr modnum operator--(int) { return n = fit(MOD + n - 1), *this + 1; }
    constexpr modnum &operator++() { return n = fit(n + 1), *this; }
    constexpr modnum &operator--() { return n = fit(MOD + n - 1), *this; }
    constexpr modnum &operator+=(modnum v) { return n = fit(n + v.n), *this; }
    constexpr modnum &operator-=(modnum v) { return n = fit(MOD + n - v.n), *this; }
    constexpr modnum &operator*=(modnum v) { return n = (u64(n) * v.n) % MOD, *this; }
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
        i64 n;
        return in >> n, v = modnum(n), in;
    }
};

using num = modnum<1'000'000'007>;

int parse(const string &s) {
    int n = 0;
    for (int S = s.size(), i = 0; i < S; i++) {
        n = 2 * n + (s[i] == '1');
    }
    return n;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    string s;
    cin >> N >> s;
    s = '0' + s + '0';

    // dp[i][m]: number of cuts s.t. i| where seen mask is m
    const int M = 20;
    vector<vector<num>> dp(6, vector<num>(1 << M));
    vector<num> last(1 << M);
    dp[0][0] = last[0] = 1;

    num ans = 0;

    for (int i = 1; i <= N; i++) {
        rotate(begin(dp), end(dp) - 1, end(dp));
        dp[0].assign(1 << M, 0), dp[0][0] = 1;

        for (int k = 1; k <= min(5, i); k++) {
            int x = parse(s.substr(i - k + 1, k));
            if (1 <= x && x <= M) {
                int h = 1 << (x - 1);
                for (int m = 0; m < (1 << M); m++) {
                    dp[0][m | h] += dp[k][m];
                }
            }
        }

        if (i >= 6 && s[i - 5] == '0') {
            int x = parse(s.substr(i - 5 + 1, 5));
            if (1 <= x && x <= M) {
                int h = 1 << (x - 1);
                for (int m = 0; m < (1 << M); m++) {
                    dp[0][m | h] += last[m];
                }
            }
        }

        if (i >= 6 && s[i - 5] == '0') {
            for (int m = 0; m < (1 << M); m++) {
                last[m] += dp[5][m];
            }
        } else {
            last = dp[5];
        }

        for (int x = 1; x <= M; x++) {
            int m = (1 << x) - 1;
            ans += dp[0][m];
        }
    }

    cout << ans << '\n';
    return 0;
}