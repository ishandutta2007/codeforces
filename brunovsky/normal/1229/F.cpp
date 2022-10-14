#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename V>
struct LinPoints {
    static constexpr V ninf = numeric_limits<V>::lowest() / 2;
    static constexpr V pinf = numeric_limits<V>::max() / 2;
    using max_heap = priority_queue<pair<V, V>, vector<pair<V, V>>, less<pair<V, V>>>;
    using min_heap = priority_queue<pair<V, V>, vector<pair<V, V>>, greater<pair<V, V>>>;

    max_heap L;
    min_heap R;
    V y, Loff = 0, Roff = 0;
    // valley is top(L)..top(R), value there is y, Loff/Roff are lazily added to points

    // f(x) = 0
    LinPoints() = default;

    int merge_size() const { return L.size() + R.size(); }

    static LinPoints constant(V y) {
        LinPoints fn;
        fn.y = y;
        return fn;
    }

    static LinPoints point(V x, V y) {
        LinPoints fn;
        fn.y = y;
        fn.push_left(x, pinf);
        fn.push_right(x, pinf);
        return fn;
    }

    // f(x) = {y if x<=M | a(x-M)+y if M<=x}
    static LinPoints valley_right(V a, V M, V y) {
        assert(a > 0);
        LinPoints fn;
        fn.y = y;
        fn.push_right(M, a);
        return fn;
    }

    // f(x) = {a(M-x)+y if x<=M | y if M<=x}
    static LinPoints valley_left(V a, V M, V y) {
        assert(a > 0);
        LinPoints fn;
        fn.y = y;
        fn.push_left(M, a);
        return fn;
    }

    // f(x) = {a(L-x)+y if x<=L | y if L<=x<=R | b(x-R)+y if R<=x}
    static LinPoints valley(V a, V b, V L, V R, V y) {
        assert(L <= R && a > 0 && b > 0);
        LinPoints fn;
        fn.y = y;
        fn.push_left(L, a);
        fn.push_right(R, b);
        return fn;
    }

    // f(x) = {a(p-x)+y if x<=p | b(x-p)+y if p<=x}
    static LinPoints abs(V a, V b, V p, V y) { return valley(a, b, p, p, y); }

    void add_left_point(V x, V slope) {
        if (x <= right_argmin()) {
            push_left(x, slope);
            return;
        }
        auto p = right_argmin();
        y += (x - p) * slope;
        push_right(x, slope);
        while (slope > 0) {
            auto [r, dr] = pop_heap(R, Roff);
            if (dr >= slope) {
                push_left(p, slope);
                push_right(p, dr - slope);
                break;
            } else {
                slope -= dr;
                y -= slope * (right_argmin() - p);
                p = right_argmin();
            }
        }
    }

    void add_right_point(V x, V slope) {
        if (x >= left_argmin()) {
            push_right(x, slope);
            return;
        }
        auto p = left_argmin();
        y += (p - x) * slope;
        push_left(x, slope);
        while (slope > 0) {
            auto [l, dl] = pop_heap(L, Loff);
            if (dl >= slope) {
                push_right(p, slope);
                push_left(p, dl - slope);
                break;
            } else {
                slope -= dl;
                y -= slope * (p - left_argmin());
                p = left_argmin();
            }
        }
    }

    static void pointwise(LinPoints& fn, LinPoints& gn) {
        if (fn.merge_size() < gn.merge_size()) {
            swap(fn, gn);
        }
        fn.y += gn.y;
        while (gn.L.size()) {
            auto [x, d] = pop_heap(gn.L, gn.Loff);
            fn.add_left_point(x, d);
        }
        while (gn.R.size()) {
            auto [x, d] = pop_heap(gn.R, gn.Roff);
            fn.add_right_point(x, d);
        }
    }

    // f(x) := g(x) + c|x|
    auto add_abs(V c) { add_left_point(0, c), add_right_point(0, c); }

    // f(x) := g(x+c)
    auto shift(int c) { Loff -= c, Roff -= c; }

    // f(x) := g(x)+dy
    void add_constant(V dy) { y += dy; }

    // f(x) := min{da+x<=y<=db+y} g(y)
    void range_min(V da, V db) { assert(da <= db), Loff -= db, Roff -= da; }

    // f(x) := min{x<=y} g(y). Clears the left heap.
    void suffix_min() { L.swap(min_heap()), Loff = 0; }

    // f(x) := min{y<=x} g(y). Clears the right heap.
    void prefix_min() { R.swap(min_heap()), Roff = 0; }

    V minimum() const { return y; }
    V left_argmin() const { return L.empty() ? ninf : (L.top().first + Loff); }
    V right_argmin() const { return R.empty() ? pinf : (R.top().first + Roff); }
    auto valley() const { return make_pair(left_argmin(), right_argmin()); }

    auto destructive_query(V x) {
        V a = left_argmin(), b = right_argmin();
        if (a <= x && x <= b) {
            return y;
        } else if (x < a) {
            V slope = 0, ans = y;
            while (L.size()) {
                auto [f, d] = pop_heap(L, Loff);
                auto advance = min(a - x, a - f);
                ans += slope * advance;
                a -= advance, slope += d;
            }
            ans += slope * (a - x);
            return ans;
        } else /* b < x */ {
            V slope = 0, ans = y;
            while (R.size()) {
                auto [f, d] = pop_heap(R, Roff);
                auto advance = min(x - b, f - b);
                ans += slope * advance;
                b += advance, slope += d;
            }
            ans += slope * (x - b);
            return ans;
        }
    }

  private:
    template <typename Heap>
    static auto pop_heap(Heap& heap, V off) {
        auto [x, slope] = heap.top();
        V ans = 0;
        do {
            ans += heap.top().second, heap.pop();
        } while (heap.size() && heap.top().first == x);
        return make_pair(x + off, ans);
    }
    void push_left(V x, V slope) {
        if (slope) {
            L.emplace(x - Loff, slope);
        }
    }
    void push_right(V x, V slope) {
        if (slope) {
            R.emplace(x - Roff, slope);
        }
    }
};

int64_t floor(int64_t n, int64_t d) { return (n >= 0 ? n / d : (n - d + 1) / d); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N), l(N), r(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> l[i] >> r[i];
    }
    const int64_t A = accumulate(begin(a), begin(a) + N, 0);
    using Function = LinPoints<int64_t>;
    auto compute = [&](int64_t x) {
        Function fn = Function::point(x, 0);
        for (int i = 0; i < N; i++) {
            // a[i]+x[j]-x[i] in [l[i],r[i]]
            // a[i]+x[j]-r[i] <= x[i] <= a[i]+x[j]-l[i]
            fn.range_min(a[i] - r[i], a[i] - l[i]);
            fn.add_left_point(0, 1);
            fn.add_right_point(0, 1);
        }
        return fn.destructive_query(x);
    };
    int64_t xL = -A - 1, xR = A + 1;
    while (xR - xL > 2) {
        int64_t x0 = floor(xL + xR, 2);
        int64_t x1 = x0 + 1;
        assert(xL < x0 && x0 < x1 && x1 < xR);
        if (compute(x0) < compute(x1)) {
            xR = x1;
        } else {
            xL = x0;
        }
    }
    int64_t x = (xL + xR) / 2;
    cout << compute(x) << '\n';
    return 0;
}