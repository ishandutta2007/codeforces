#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T>
struct unit_pwlc {
    static inline constexpr T MIN = numeric_limits<T>::lowest() / 2;
    static inline constexpr T MAX = numeric_limits<T>::max() / 2;
    template <typename U>
    using max_heap = priority_queue<U, vector<U>, less<U>>;
    template <typename U>
    using min_heap = priority_queue<U, vector<U>, greater<U>>;

    T y0, left_offset = 0, right_offset = 0;
    max_heap<T> left;
    min_heap<T> right;

    explicit unit_pwlc(T y0 = 0) : y0(y0) {}

    T minimum() const { return y0; }
    T left_arg_min() const { return left.empty() ? MIN : (left.top() + left_offset); }
    T right_arg_min() const { return right.empty() ? MAX : (right.top() + right_offset); }

    // __ : f(x) = b
    static unit_pwlc constant(T b) { return unit_pwlc(b); }

    // _/ : f(x) = max(0, x - x0) + b
    static unit_pwlc positive_slope(T x0, T b = 0) {
        unit_pwlc f(b);
        f.right.push(x0);
        return f;
    }

    // _/ : f(x) = max(0, x0 - x) + b
    static unit_pwlc negative_slope(T x0, T b = 0) {
        unit_pwlc f(b);
        f.left.push(x0);
        return f;
    }

    // \/ : y = c * abs(x - x0) + b
    static unit_pwlc abs(T x0, T b = 0) {
        unit_pwlc f(b);
        f.left.push(x0);
        f.right.push(x0);
        return f;
    }

    // f'(x) = f(x + c)
    auto& shift(int c) {
        left_offset -= c;
        right_offset -= c;
        return *this;
    }

    // \_/ => \__ : f'(x) = min_{y <= x} f(y)
    auto& prefix_min() {
        right = min_heap<T>();
        return *this;
    }

    // \_/ => \__ : f'(x) = min_{y >= x} f(y)
    auto& suffix_min() {
        left = max_heap<T>();
        return *this;
    }

    // \_/ => \___/ : f'(x) = min_{dx in [xl, xr]} f(x + dx) */
    auto& range_min(T xl, T xr) {
        assert(xl <= xr);
        if (xl > 0) {
            shift(xl), xr -= xl, xl = 0;
        }
        if (xr < 0) {
            shift(xr), xl -= xr, xr = 0;
        }
        left_offset -= xr;
        right_offset -= xl;
        return *this;
    }

    auto& add_constant(T dy) {
        y0 += dy;
        return *this;
    }

    auto& add(unit_pwlc&& o) {
        y0 += o.y0;

        while (!o.left.empty()) {
            auto x = o.left.top();
            auto beta_change = 1;
            x += o.left_offset;
            o.left.pop();

            if (x <= right_arg_min()) {
                left.emplace(x - left_offset);
            } else {
                T x0 = right_arg_min();
                y0 += (x - x0) * beta_change;
                right.emplace(x - right_offset);
                T beta = beta_change;
                while (beta > 0) {
                    T next_change = 1;
                    right.pop();
                    if (next_change >= beta) {
                        left.emplace(x0 - left_offset);
                        if (next_change > beta) {
                            right.emplace(x0 - right_offset);
                        }
                        beta = 0;
                    } else {
                        beta -= next_change;
                        y0 -= beta * (right_arg_min() - x0);
                        x0 = right_arg_min();
                    }
                }
            }
        }

        while (!o.right.empty()) {
            auto x = o.right.top();
            auto beta_change = 1;
            o.right.pop();

            if (x >= left_arg_min()) {
                right.emplace(x - right_offset);
            } else {
                T x0 = left_arg_min();
                y0 += (x0 - x) * beta_change;
                left.emplace(x - left_offset);
                T beta = beta_change;
                while (beta > 0) {
                    T next_change = 1;
                    left.pop();
                    if (next_change >= beta) {
                        right.emplace(x0 - right_offset);
                        if (next_change > beta) {
                            left.emplace(x0 - left_offset);
                        }
                        beta = 0;
                    } else {
                        beta -= next_change;
                        y0 -= beta * (x0 - left_arg_min());
                        x0 = left_arg_min();
                    }
                }
            }
        }

        return *this;
    }

    unit_pwlc& add(const unit_pwlc& o) {
        unit_pwlc f(o);
        return add(move(f));
    }

    friend unit_pwlc operator+(unit_pwlc a, const unit_pwlc& b) { return a.add(b); }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] -= i;
    }

    long long ans1 = 0;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        pq.push(a[i]);                // go down of |x-ai|
        pq.push(a[i]);                // go up of |x-ai|
        ans1 += abs(pq.top() - a[i]); // transform ai to pq.top()
        pq.pop();                     // prefix min
    }
    // cout << ans1 << '\n';

    long long ans2 = 0;
    unit_pwlc<int> f;
    for (int i = 0; i < N; i++) {
        f.add(unit_pwlc<int>::abs(a[i]));
        ans2 += abs(f.right_arg_min() - a[i]); // transform ai to rightmost lowest
        f.prefix_min();
    }
    cout << ans2 << '\n';

    return 0;
}