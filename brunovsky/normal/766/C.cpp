#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

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
    int N;
    cin >> N;
    string s;
    cin >> s;
    array<int, 26> maxlen = {};
    for (int i = 0; i < 26; i++) {
        cin >> maxlen[i];
    }
    vector<num> dp(N + 1);
    int longest = 0;
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        int l = 0;
        for (int j = i; j > l; j--) {
            int cap = i - maxlen[s[j - 1] - 'a'];
            if (cap <= j) {
                l = max(l, cap);
            } else {
                l = j;
                break;
            }
        }
        longest = max(longest, i - l);
        for (int j = i - 1; j >= l; j--) {
            dp[i] += dp[j];
        }
    }
    // Greedy
    int start = 1, len = N, i = 1, blocks = 1;
    while (i <= N) {
        int nxt_len = maxlen[s[i - 1] - 'a'];
        if (start + len == i || start + nxt_len <= i) {
            blocks++;
            start = i;
            len = N;
        } else {
            len = min(len, nxt_len);
            i++;
        }
    }
    // Problem 1
    cout << dp[N] << endl;
    // Problem 2
    cout << longest << endl;
    // Problem 3
    cout << blocks << endl;
    return 0;
}