#include <bits/stdc++.h>

using namespace std;

#define long int64_t


template <int mod>
struct modnum {
    static_assert(mod > 0 && 2LL * mod < INT_MAX);
    int n;

    modnum() : n(0) {}
    modnum(int v) : n(fit(v % mod)) {}
    explicit operator int() const { return n; }

    static int fit(int v) { return v >= mod ? v - mod : (v < 0 ? v + mod : v); }
    static int modinv(int v, int m = mod) {
        v %= m, assert(v);
        return v == 1 ? 1 : (m - 1LL * modinv(m, v) * m / v);
    }

    modnum inv() const { return {modinv(n)}; }
    modnum operator-() const { return {fit(n)}; }
    modnum operator+() const { return {n}; }
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

template <typename T, typename... Rs>
string to_string(const vector<T, Rs...>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T, typename... Rs>
ostream& operator<<(ostream& out, const vector<T, Rs...>& v) {
    return out << to_string(v);
}

using num = modnum<998244353>;

// *****

vector<num> fac, ifac;

auto pascal_sieve(int N) {
    fac.resize(N + 1), ifac.resize(N + 1);
    fac[0] = ifac[0] = 1;

    for (int n = 1; n <= N; n++) {
        fac[n] = 1LL * n * fac[n - 1];
    }
    ifac[N] = fac[N].inv();
    for (int n = N; n >= 1; n--) {
        ifac[n - 1] = n * ifac[n];
    }
}

auto solve() {
    int N, M;
    cin >> N >> M;
    // d[p][c]: default distance of point p to city c
    vector<vector<int>> d(M, vector<int>(N));
    for (int c = 0; c < N; c++) {
        for (int p = 0; p < M; p++) {
            cin >> d[p][c];
        }
    }
    vector<num> prob(M);
    for (int p = 0; p < M; p++) {
        vector<int> ctrl(N + 1, 0);
        for (int c = 0; c < N; c++) {
            for (int day = 1; day <= N + 1 - d[p][c]; day++) {
                ctrl[day]++;
            }
        }
        num q = 1;
        for (int day = 1; day <= N; day++) {
            q = q * (N - day + 1 - ctrl[day]);
        }
        prob[p] = 1 - q / fac[N];
    }
    num total = accumulate(begin(prob), end(prob), num(0));
    return total;
}

// *****

int main() {
    pascal_sieve(100);
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}