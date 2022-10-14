#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T>
struct cht_line {
    T m, b;
    mutable T end; // largest x for which this line is in the hull
    bool operator<(const cht_line<T>& other) const { return m < other.m; }
    bool operator<(T x) const { return end < x; }
};

template <typename T>
struct dynamic_cht : multiset<cht_line<T>, less<>> {
    using Line = cht_line<T>;
    using base_t = multiset<cht_line<T>, less<>>;
    static inline const T pinf = numeric_limits<T>::max();
    static inline const T ninf = numeric_limits<T>::lowest();
    static inline const T eps = 20 * numeric_limits<T>::epsilon();
    static inline T zerodiv(T a, T b) {
        if constexpr (is_integral<T>::value) {
            return (a < 0) != (b < 0) ? a / b - !!(a % b) : a / b;
        } else {
            return a / b;
        }
    }
    bool intersect(typename base_t::iterator x, typename base_t::iterator y) {
        if (y == base_t::end()) {
            x->end = pinf;
            return false;
        }
        if (abs(x->m - y->m) <= eps) {
            x->end = x->b > y->b ? pinf : ninf;
        } else {
            x->end = zerodiv(y->b - x->b, x->m - y->m);
        }
        return x->end >= y->end;
    }
    void add(T m, T b) {
        auto z = base_t::insert(cht_line<T>{m, b, 0});
        auto y = z++;
        auto x = y;
        while (intersect(y, z)) {
            z = base_t::erase(z);
        }
        if (x != base_t::begin() && intersect(--x, y)) {
            intersect(x, y = base_t::erase(y));
        }
        while ((y = x) != base_t::begin() && (--x)->end >= y->end) {
            intersect(x, base_t::erase(y));
        }
    }
    cht_line<T> argmax(T x) const {
        assert(!base_t::empty());
        return *base_t::lower_bound(x);
    }
    T max(T x) const {
        auto line = argmax(x);
        return line.m * x + line.b;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    // b[k] = SUM{i<=k} a[i]
    // c[k] = SUM{i<=k} i a[i]
    vector<int64_t> b(N + 1), c(N + 1);
    for (int i = 1; i <= N; i++) {
        b[i] = b[i - 1] + a[i];
        c[i] = c[i - 1] + 1LL * i * a[i];
    }

    dynamic_cht<int64_t> cht;
    cht.add(0, 0);

    int64_t ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, c[i] + cht.max(b[i]));
        cht.add(-i, 1LL * i * b[i] - c[i]);
    }
    cout << ans << '\n';

    // Consider solutions of kind (L..R] for fixed R and L<=R
    // c[R] - c[L] - L(b[R] - b[L])
    // = c[R] - Lb[R] + (Lb[L] - c[L])
    // = constant - Lx + f(L)
    // = constant +

    // Let p[i] =
    return 0;
}