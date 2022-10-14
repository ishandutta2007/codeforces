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

using num = modnum<1'000'000'007>;

int brute(const string &s) {
    int N = s.size();
    vector<set<string>> bylen(N + 1);
    vector<int> cnt(N + 1);
    bylen[N].insert(s);
    cnt[N] = 1;

    for (int n = N; n > 1; n--) {
        for (const string &u : bylen[n]) {
            assert(int(u.size()) == n);
            for (int i = 0; i + 1 < n; i++) {
                string v = u;
                v[i] = max(v[i], v[i + 1]);
                v.erase(v.begin() + i + 1);
                bylen[n - 1].insert(v);
            }
        }
        cnt[n - 1] = bylen[n - 1].size();
    }
    int ans = accumulate(begin(cnt) + 1, begin(cnt) + N + 1, 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;

    if (find(begin(s), end(s), '1') == end(s)) {
        cout << s.size() << '\n';
        return 0;
    }
    int zL = find(begin(s), end(s), '1') - begin(s);
    int zR = find(rbegin(s), rend(s), '1') - rbegin(s);
    int N = s.size() - zL - zR;
    s = s.substr(zL, N);

    vector<int> prev(N), next(N), run(N, -1), mate(N, -1);
    for (int i = 0; i < N; i++) {
        prev[i] = s[i] == '1' ? i : prev[i - 1];
    }
    for (int i = N - 1; i >= 0; i--) {
        next[i] = s[i] == '1' ? i : next[i + 1];
    }
    for (int i = 0; i < N; i++) {
        mate[i] = run[i - prev[i]];
        run[i - prev[i]] = i;
    }

    vector<num> dp(N), sum(N);
    dp[0] = sum[0] = 1;

    for (int i = 0; i + 1 < N; i++) {
        if (s[i] == '0') {
            dp[next[i]] += sum[prev[i]] - (mate[i] >= 0 ? sum[mate[i]] : 0);
        } else {
            dp[next[i + 1]] += dp[i];
        }
        sum[i] = (i > 0 ? sum[i - 1] : 0) + dp[i];
    }

    num ans = 0;
    for (int i = 0; i < N; i++) {
        assert(dp[i] == 0 || s[i] == '1');
        ans += dp[i];
    }
    cout << num(zL + 1) * num(zR + 1) * ans << endl;

    return 0;
}