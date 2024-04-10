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
    constexpr modnum& operator++() { return n = fit(n + 1), *this; }
    constexpr modnum& operator--() { return n = fit(mod + n - 1), *this; }
    constexpr modnum& operator+=(modnum v) { return n = fit(n + v.n), *this; }
    constexpr modnum& operator-=(modnum v) { return n = fit(mod + n - v.n), *this; }
    constexpr modnum& operator*=(modnum v) { return n = (u64(n) * v.n) % mod, *this; }
    constexpr modnum& operator/=(modnum v) { return *this *= v.inv(); }

    friend constexpr modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend constexpr modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend constexpr modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend constexpr modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend constexpr bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend constexpr bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream& operator<<(ostream& out, modnum v) { return out << v.n; }
    friend istream& operator>>(istream& in, modnum& v) {
        int64_t n;
        return in >> n, v = modnum(n), in;
    }
};

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> A(2 * N, vector<int>(N));
    for (int i = 0; i < 2 * N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> A[i][k], A[i][k]--;
        }
    }

    vector<bool> alive(2 * N, true);
    vector<int> sample;
    modnum<998244353> ans = 1;

    // given a column c and a value v, find adjacents
    vector<vector<set<int>>> colval(N, vector<set<int>>(N));
    for (int i = 0; i < 2 * N; i++) {
        for (int c = 0; c < N; c++) {
            colval[c][A[i][c]].insert(i);
        }
    }

    auto pick = [&](int i) {
        sample.push_back(i);
        alive[i] = false;
        set<int> bad;
        for (int c = 0; c < N; c++) {
            int v = A[i][c];
            colval[c][v].erase(i);
            for (int j : colval[c][v]) {
                bad.insert(j);
            }
            colval[c][v].clear();
        }
        for (int j : bad) {
            alive[j] = false;
            for (int c = 0; c < N; c++) {
                int v = A[j][c];
                colval[c][v].erase(j);
            }
        }
    };

    while (int(sample.size()) < N) {
        bool picked = false;
        for (int c = 0; c < N; c++) {
            for (int v = 0; v < N; v++) {
                if (colval[c][v].size() == 1u) {
                    int i = *colval[c][v].begin();
                    pick(i);
                    picked = true;
                }
            }
        }
        if (picked) {
            continue;
        }
        for (int c = 0; c < N; c++) {
            for (int v = 0; v < N; v++) {
                assert(colval[c][v].empty() || colval[c][v].size() == 2u);
            }
        }
        ans *= 2;
        for (int i = 0; i < 2 * N; i++) {
            if (alive[i]) {
                pick(i);
                break;
            }
        }
    }

    sort(begin(sample), end(sample));

    cout << ans << '\n';
    for (int i = 0; i < N; i++) {
        cout << sample[i] + 1 << " \n"[i + 1 == N];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}