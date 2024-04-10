#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

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
    static int modinv(int x) {
        int nx = 1, ny = 0, y = mod;
        while (x) {
            int k = y / x;
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
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;
    int N = s.size();
    if (s[0] == '0') {
        assert(N & 1);
        int K = N / 2;
        string a = "0";
        string b = s.substr(1, K);
        string c = s.substr(K + 1, K);
        cout << a << '+' << b << '=' << c << endl;
        return 0;
    }
    vector<num> suf(N + 1);
    num g = 1;
    for (int i = N - 1; i >= 0; i--) {
        suf[i] = (s[i] - '0') * g + suf[i + 1];
        g *= 10;
    }
    auto hashrange = [&](int l, int r) {
        // exclusive on the right
        return (suf[l] - suf[r]) / modpow(num(10), N - r);
    };
    vector<pair<int, int>> cand;
    for (int len = (N + 2) / 3; len <= N / 2; len++) {
        vector<int> is = {len - 1, len, N - len - (len - 1), N - len - len};
        for (int i : is) {
            if (i <= 0 || N - len <= i) {
                continue; // empty string
            }
            if (s[i] == '0' && N - len != i + 1) {
                continue; // leading zeros
            }
            auto a = hashrange(0, i);
            auto b = hashrange(i, N - len);
            auto c = hashrange(N - len, N);
            if (a + b == c) {
                cand.emplace_back(i, N - len);
            }
        }
    }
    debug(cand);
    assert(!cand.empty());
    auto [i, j] = cand[0];
    auto a = s.substr(0, i);
    auto b = s.substr(i, j - i);
    auto c = s.substr(j);
    cout << a << '+' << b << '=' << c << endl;
    return 0;
}