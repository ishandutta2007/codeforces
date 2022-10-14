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
        i64 n;
        return in >> n, v = modnum(n), in;
    }
};

using num = modnum<998244353>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }

        if (N == 1) {
            cout << 1 << '\n';
            continue;
        } else if (N == 2) {
            cout << 1 + (a[1] != a[2]) << '\n';
            continue;
        }

        // so try some trivial cases first:
        // PP...PP -> yes
        // CC...CC -> no
        // PP...PC...CC -> maybe
        // CC...CP...PP -> maybe
        // otherwise we can assume there is an alternation, CP...
        // sliding window + counting
        // start with C on the index 1, slide it to the right
        // brute-force C/P combinations on the sides that are valid
        // decide where to stop alternating and start spamming Ps
        vector<long> prefix(N + 1);
        vector<long> odd(N + 1), even(N + 1);
        for (int i = 1; i <= N; i++) {
            prefix[i] = prefix[i - 1] + a[i];
            odd[i] = odd[i - 1] + ((i & 1) ? a[i] : 0);
            even[i] = even[i - 1] + ((i & 1) ? 0 : a[i]);
        }

        auto all_inclusive = [&](int l, int r) {
            if (l > r)
                return long(0);
            return prefix[r] - prefix[l - 1];
        };
        auto even_inclusive = [&](int l, int r) {
            if (l > r)
                return long(0);
            return even[r] - even[l - 1];
        };
        auto odd_inclusive = [&](int l, int r) {
            if (l > r)
                return long(0);
            return odd[r] - odd[l - 1];
        };
        auto same_inclusive = [&](int parity, int l, int r) {
            return (parity & 1) ? odd_inclusive(l, r) : even_inclusive(l, r);
        };

        num ans = 1; // PP...PP
        for (int i = 3; i <= N; i++) {
            ans += all_inclusive(i, N) < all_inclusive(1, i - 1);
            // PPPC...CCC
        }

        vector<pair<bool, bool>> start_end = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

        for (auto [start_with_c, end_with_c] : start_end) {
            long Cbefore = 0, Pbefore = 0;
            (start_with_c ? Cbefore : Pbefore) += a[1];
            (end_with_c ? Cbefore : Pbefore) += a[N];

            for (int i = start_with_c ? 1 : 2; i < N; i++) {
                long Csum = Cbefore + all_inclusive(2, i);
                long Psum = Pbefore;
                if (Csum >= Pbefore + all_inclusive(i + 1, N - 1)) {
                    break; // no more solutions
                }
                // so we have at least one solution
                // now how many alternating Cs can we add before overflowing?
                int L = i - 1, R = N;
                R -= end_with_c && (i + 1 != N) && (i & 1) != (N & 1);
                // prevent annoying edge case ending with CPCC
                // suppose we can add Cs on positions with the same parity as i
                // M is inclusive
                while (L + 2 < R) {
                    int M = (L + R + 1) / 2;
                    long Cs = Csum + same_inclusive(i, i + 1, M);
                    long Ps = Psum + same_inclusive(i + 1, i + 1, M) +
                              all_inclusive(M + 1, N - 1);
                    if (Cs < Ps) {
                        L = M - 1;
                    } else {
                        R = M;
                    }
                }
                // how many positions?
                int M = (L + R) / 2;
                assert(i <= M && M < N);
                int positions = (M - i + 2) / 2;
                ans += positions;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}