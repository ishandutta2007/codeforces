#include <bits/stdc++.h>

using namespace std;

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

using num = modnum<998244353>;

int main() {
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<num> corner(N + 1), same(N + 1), diff(N + 1);
    same[0] = 0;
    corner[0] = diff[0] = 1;
    for (int n = 1; n <= N; n++) {
        corner[n] = (K - 1) * corner[n - 1]; // (K-1)^n
        same[n] = (K - 1) * diff[n - 1];
        diff[n] = (K - 2) * diff[n - 1] + same[n - 1];
    }

    num ans = 1;

    for (int start : {0, 1}) {
        int i = start;
        while (i < N && arr[i] == -1) {
            i += 2;
        }
        if (i > start && i < N) {
            int n = i / 2;
            ans *= corner[n];
        } else if (i >= N) {
            int n = i / 2;
            ans *= K * corner[n - 1];
        }
        while (i < N) {
            int a = arr[i];
            int j = i + 2;
            while (j < N && arr[j] == -1) {
                j += 2;
            }
            int n = (j - i - 2) / 2;
            if (j >= N) {
                ans *= corner[n];
            } else {
                int b = arr[j];
                if (a == b) {
                    ans *= same[n];
                } else {
                    ans *= diff[n];
                }
            }
            i = j;
        }
    }

    cout << ans << endl;
    return 0;
}