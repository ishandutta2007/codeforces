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
    // change these if you need another size of integers
    using u32 = uint32_t;
    using u64 = uint64_t;
    using i32 = int32_t;
    using i64 = int64_t;
    static inline u32 mod;

    u32 n;

    modnum() : n(0) {}
    modnum(u64 v) : n(v >= mod ? v % mod : v) {}
    modnum(u32 v) : n(v >= mod ? v % mod : v) {}
    modnum(i64 v) : modnum(v >= 0 ? u64(v) : u64(mod + v % int(mod))) {}
    modnum(i32 v) : modnum(v >= 0 ? u32(v) : u32(mod + v % int(mod))) {}
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
    modnum &operator++() { return n = fit(n + 1), *this; }
    modnum &operator--() { return n = fit(mod + n - 1), *this; }
    modnum &operator+=(modnum v) { return n = fit(n + v.n), *this; }
    modnum &operator-=(modnum v) { return n = fit(mod + n - v.n), *this; }
    modnum &operator*=(modnum v) { return n = (u64(n) * v.n) % mod, *this; }
    modnum &operator/=(modnum v) { return *this *= v.inv(); }

    friend modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream &operator<<(ostream &out, modnum v) { return out << v.n; }
    friend istream &operator>>(istream &in, modnum &v) {
        i64 n;
        return in >> n, v = modnum(n), in;
    }
};

using num = modnum;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    // 4e6*4*2=32e6 which is still ok?

    int N, M;
    cin >> N >> M;
    num::mod = M;

    vector<num> dp(N + 2);
    vector<num> sum(N + 2);
    dp[N] = 1;

    for (int n = N; n >= 1; n--) {
        dp[n] += sum[n + 1];

        int k = 2;
        while (true) {
            int L = k * n;
            int R = min(k * n + (k - 1), N);
            if (L > N) {
                break;
            }
            dp[n] += sum[L] - sum[R + 1];
            k++;
        }

        sum[n] = sum[n + 1] + dp[n];
    }

    cout << dp[1] << '\n';
    return 0;
}