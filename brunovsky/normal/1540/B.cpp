#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

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

using num = modnum<1'000'000'007>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // pi[i][k]: we have a path of length n and we select the kth node first, what is
    // the probability we will then select the 0th node first?
    vector<vector<num>> pi(N + 1, vector<num>(N + 1));

    for (int n = 2; n <= N; n++) {
        pi[n][0] = 1;
        pi[n][1] = 0;
        for (int k = 1; k + 1 < n; k++) {
            pi[n][k] = (pi[n - 1][k - 1] + pi[n - 1][k]) / 2;
        }
    }

    num ans = 0;

    for (int root = 1; root < N; root++) {
        vector<int> subt(N), parent(N);

        y_combinator([&](auto self, int u, int p = -1) -> void {
            subt[u] = 1;
            parent[u] = p;
            for (int v : tree[u]) {
                if (v != p) {
                    self(v, u);
                    subt[u] += subt[v];
                }
            }
        })(root);

        y_combinator([&](auto self, int u) -> void {
            if (u < root) {
                vector<int> lens = {subt[u]};
                int v = u;
                do {
                    lens.push_back(subt[parent[v]] - subt[v]);
                    v = parent[v];
                } while (v != root);

                int L = lens.size();
                for (int i = 0; i < L; i++) {
                    ans += pi[L][i] * lens[L - i - 1];
                }
            }
            for (int v : tree[u]) {
                if (v != parent[u]) {
                    self(v);
                }
            }
        })(root);
    }

    ans = (ans / N);
    cout << ans << '\n';
    return 0;
}