#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

template <int mod>
struct modnum {
    static_assert(mod > 0 && 2LL * mod < INT_MAX);
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
    modnum operator-() const { return {fit(-n)}; }
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

using num = modnum<1'000'000'007>;

int main() {
    ios::sync_with_stdio(false);
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<num> a(N + 1);
    for (int n = 1; n <= N; n++) {
        cin >> a[n];
    }

    vector<vector<num>> count_paths(N + 2, vector<num>(K + 1));
    for (int n = 1; n <= N; n++) {
        count_paths[n][0] = 1;
    }
    for (int k = 1; k <= K; k++) {
        for (int n = 1; n <= N; n++) {
            count_paths[n][k] = count_paths[n - 1][k - 1] + count_paths[n + 1][k - 1];
        }
    }

    vector<num> dp(N + 1);
    for (int n = 1; n <= N; n++) {
        for (int i = 0; i <= K; i++) {
            dp[n] += count_paths[n][i] * count_paths[n][K - i];
        }
    }

    num ans = 0;
    for (int n = 1; n <= N; n++) {
        ans += a[n] * dp[n];
    }
    for (int q = 0; q < Q; q++) {
        int i;
        cin >> i;
        ans -= a[i] * dp[i];
        cin >> a[i];
        ans += a[i] * dp[i];
        cout << ans << endl;
    }
    return 0;
}