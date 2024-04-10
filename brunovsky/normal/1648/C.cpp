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

template <typename T, typename BinOp>
struct bitree {
    int N;
    vector<T> tree;
    BinOp binop;

    explicit bitree(int N, const BinOp &op, T id = T())
        : N(N), tree(N + 1, id), binop(op) {}

    template <typename A>
    explicit bitree(int N, const vector<A> &arr, const BinOp &op = BinOp(), T id = T())
        : bitree(N, op, id) {
        for (int i = 1; i <= N; i++) {
            tree[i] = binop(arr[i - 1], tree[i]);
            if (int j = i + (i & -i); j <= N) {
                tree[j] = binop(tree[i], tree[j]);
            }
        }
    }

    void combine(int i, T v) {
        for (++i; i <= N; i += i & -i) {
            tree[i] = binop(tree[i], v);
        }
    }

    // Prefix sum inclusive, [0..r]
    T prefix(int r) const {
        T accum = tree[0];
        for (int i = r + 1; i > 0; i -= i & -i) {
            accum = binop(tree[i], accum);
        }
        return accum;
    }

    // Find smallest i such that fn(prefix(i)) is true, or N otherwise.
    // fn should be F F F F ... T T T T, e.g. fn(sum) := x <= sum if sum is increasing
    template <typename Fn>
    int lower_bound(Fn &&fn) const {
        int i = 0;
        T accum = tree[0];
        for (int bit = 8 * sizeof(int) - __builtin_clz(N << 1); bit >= 0; bit--) {
            int next = i + (1 << bit);
            if (next <= N) {
                T combined = binop(accum, tree[next]);
                if (!fn(combined)) {
                    i = next;
                    accum = combined;
                }
            }
        }
        return i;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> s(N), t(M);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> t[i];
    }
    sort(begin(s), end(s));
    const int S = *max_element(begin(s), end(s));
    const int T = *max_element(begin(t), end(t));
    const int A = 1 + max(S, T);
    vector<int> count(A);
    for (int c : s) {
        count[c]++;
    }
    vector<num> fac(N + 1, 1);
    for (int n = 2; n <= N; n++) {
        fac[n] = n * fac[n - 1];
    }
    num multi = fac[N];
    for (int c = 0; c < A; c++) {
        multi /= fac[count[c]];
    }
    bitree<int, plus<int>> bit(A, count, {}, 0);
    num ans = 0;
    int i = 0;
    while (i < min(N, M)) {
        int x = bit.prefix(t[i] - 1);
        ans += x * multi / (N - i);
        if (count[t[i]] > 0) {
            int c = count[t[i]]--;
            bit.combine(t[i], -1);
            multi *= num(c) / (N - i);
        } else {
            break;
        }
        i++;
    }
    ans += i == N && i < M;
    cout << ans << '\n';
    return 0;
}