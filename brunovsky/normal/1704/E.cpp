#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <uint32_t mod>
struct modnum {
    // change these if you need another size of integers
    static constexpr inline uint32_t MOD = mod;
    using u32 = uint32_t;
    using u64 = uint64_t;
    using i32 = int32_t;
    using i64 = int64_t;
    static_assert(MOD > 0 && MOD < UINT_MAX / 2);

    u32 n;

    constexpr modnum() : n(0) {}
    constexpr modnum(u64 v) : n(v >= MOD ? v % MOD : v) {}
    constexpr modnum(u32 v) : n(v >= MOD ? v % MOD : v) {}
    constexpr modnum(i64 v) : modnum(v >= 0 ? u64(v) : u64(MOD + v % int(MOD))) {}
    constexpr modnum(i32 v) : modnum(v >= 0 ? u32(v) : u32(MOD + v % int(MOD))) {}
    explicit constexpr operator i32() const { return n; }
    explicit constexpr operator u32() const { return n; }
    explicit constexpr operator bool() const { return n != 0; }

    static constexpr u32 fit(u32 x) { return x >= MOD ? x - MOD : x; }
    static constexpr int modinv(u32 x) {
        int nx = 1, ny = 0;
        u32 y = MOD;
        while (x) {
            auto k = y / x;
            y = y % x;
            ny = ny - k * nx;
            swap(x, y), swap(nx, ny);
        }
        return ny < 0 ? MOD + ny : ny;
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
    constexpr modnum operator-() const { return n == 0 ? n : MOD - n; }
    constexpr modnum operator+() const { return *this; }
    constexpr modnum operator++(int) { return n = fit(n + 1), *this - 1; }
    constexpr modnum operator--(int) { return n = fit(MOD + n - 1), *this + 1; }
    constexpr modnum &operator++() { return n = fit(n + 1), *this; }
    constexpr modnum &operator--() { return n = fit(MOD + n - 1), *this; }
    constexpr modnum &operator+=(modnum v) { return n = fit(n + v.n), *this; }
    constexpr modnum &operator-=(modnum v) { return n = fit(MOD + n - v.n), *this; }
    constexpr modnum &operator*=(modnum v) { return n = (u64(n) * v.n) % MOD, *this; }
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
        int N, M;
        cin >> N >> M;
        vector<num> a(N);
        vector<int64_t> b(N);
        for (int i = 0; i < N; i++) {
            cin >> b[i];
            a[i] = b[i];
        }
        vector<set<int>> out(N), in(N);
        vector<int> indeg(N);
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v, u--, v--;
            out[u].insert(v);
            in[v].insert(u);
            indeg[v]++;
        }
        if (count(begin(b), end(b), 0) == N) {
            cout << 0 << '\n';
            continue;
        }
        vector<int> alive(N, true);
        auto rem_node = [&](int u) {
            alive[u] = false;
            for (int v : out[u]) {
                in[v].erase(u);
                --indeg[v];
            }
            b[u] = 0;
            out[u].clear();
        };
        num ops = 0;
        auto run_simple = [&]() {
            ops += 1;
            vector<int> cnt(N);
            for (int u = 0; u < N; u++) {
                if (alive[u] && b[u] > 0) {
                    for (int v : out[u]) {
                        assert(alive[v]);
                        cnt[v] += 1;
                    }
                }
            }
            for (int u = 0; u < N; u++) {
                if (alive[u]) {
                    if (b[u] > 0) {
                        a[u] -= 1;
                        b[u] -= 1;
                    }
                    a[u] += cnt[u];
                    b[u] += cnt[u];
                }
            }
        };
        auto run_complex = [&](int c) {
            ops += c;
            vector<num> cnt(N);
            for (int u = 0; u < N; u++) {
                if (alive[u]) {
                    for (int v : out[u]) {
                        assert(alive[v]);
                        cnt[v] += c;
                    }
                }
            }
            for (int u = 0; u < N; u++) {
                if (alive[u]) {
                    a[u] += cnt[u] - c;
                }
            }
        };
        int dead = 0;
        for (int iter = 0; iter < 2 * N; iter++) {
            bool found = false;
            for (int u = 0; u < N; u++) {
                if (alive[u] && indeg[u] == 0 && b[u] == 0) {
                    found = true;
                    rem_node(u);
                    dead++;
                }
            }
            if (dead == N) {
                break;
            } else if (!found) {
                run_simple();
            }
        }
        while (true) {
            auto play = make_pair(INT_MAX, -1);
            for (int u = 0; u < N; u++) {
                if (alive[u] && indeg[u] == 0) {
                    play = min(play, make_pair(int(a[u]), u));
                }
            }
            if (play.second == -1) {
                break;
            } else if (play.first == 0) {
                rem_node(play.second);
            } else {
                run_complex(play.first);
                rem_node(play.second);
            }
        }
        cout << ops << '\n';
    }
    return 0;
}