#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct modnum {
    // change these if you need another size of integers
    static inline uint32_t mod = 0;
    using u32 = uint32_t;
    using u64 = uint64_t;
    using i32 = int32_t;
    using i64 = int64_t;

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

constexpr int MAX = 101;
num dp[MAX][MAX][MAX];
num fac[MAX], binom[MAX][MAX];

auto choose(int n, int k) { return k < 0 || k > n ? num(0) : binom[n][k]; }

auto brute(int N, int M, int K) {
    vector<int> perm(N);
    iota(begin(perm), end(perm), 0);
    int ans = 0;
    do {
        int count = 0;
        for (int i = 0; i < N; i++) {
            set<int> maximums = {perm[i]};
            int best = perm[i];
            for (int j = i - 1; j >= 0; j--) {
                best = max(best, perm[j]);
                maximums.insert(best);
            }
            best = perm[i];
            for (int j = i + 1; j < N; j++) {
                best = max(best, perm[j]);
                maximums.insert(best);
            }
            count += maximums.size() == unsigned(M);
        }
        ans += count == K;
    } while (next_permutation(begin(perm), end(perm)));
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K >> num::mod;

    fac[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fac[i] = fac[i - 1] * i;
    }

    // choose(n,k) = n!/(n-k)!k! = (n-k+1)...n, 0<=k<=n
    binom[0][0] = 1;
    for (int n = 1; n < MAX; n++) {
        for (int k = 0; k <= n; k++) {
            binom[n][k] = choose(n - 1, k - 1) + choose(n - 1, k);
        }
    }

    dp[1][1][1] = 1;
    for (int n = 1; n <= N; n++) {
        dp[1][n][1] = fac[n];
        for (int m = n + 1; m <= M; m++) {
            dp[m][n][0] = fac[n];
        }
    }

    for (int n = 2; n <= N; n++) {
        for (int m = 2; m <= min(n, M); m++) {
            int S = min(n - m + 1, K);
            for (int k = 0; k <= S; k++) {
                dp[m][n][k] = 2 * dp[m - 1][n - 1][k]; // n on the edges
            }
            for (int L = 1, R = n - 2; L <= R; L++, R--) {
                auto c = (L < R ? 2 : 1) * binom[n - 1][L];
                for (int l = 0; l <= S; l++) {
                    if (num z = dp[m - 1][L][l] * c; z) {
                        for (int r = 0; l + r <= S; r++) {
                            dp[m][n][l + r] += z * dp[m - 1][R][r];
                        }
                    }
                }
            }
        }
    }

    cout << dp[M][N][K] << '\n';
    return 0;
}

// Suppose we fix where the maximum, n, is, say position i
// i-1 elements to the left, n-i to the right, all "blocked" at i
// The left and right halfs must be good for m-1
// If there are l [m-1]-good on the left, and r [m-1]-good on the right
// then we should have l+r=k because m>2
// So we've got some dimensions:
// n, length of permutation
// m, count of maximums
// k, count of numbers with m maximums
// So need O(nmk) memory which is ok
// For recursion, need to vary position of n in the array so O(n) more states
// Also need to vary count on the left and on the right, so O(k) more states