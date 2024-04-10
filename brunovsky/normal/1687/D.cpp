#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int64_t get(int64_t n) {
    int64_t k = floor(sqrt(n));
    k -= k * k > n;
    k += (k + 1) * (k + 1) <= n;
    return k;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int64_t> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    a.erase(unique(begin(a), end(a)), end(a));
    N = a.size();
    vector<int64_t> b(N);
    auto compress = [&]() {
        b[0] = a[0];
        int M = 1;
        for (int i = 1; i + 1 < N; i++) {
            if (a[i - 1] != b[M - 1] || a[i + 1] - a[i - 1] >= get(a[i - 1])) {
                b[M++] = a[i];
            }
        }
        b[M++] = a[N - 1];
        swap(a, b), N = M;
    };
    auto shift = [&](int k) {
        for (int i = 0; i < N; i++) {
            a[i] += k;
        }
    };
    auto compute = [&]() {
        int64_t need = 0, got = 3 * get(a[N - 1]);
        for (int i = 0; i < N; i++) {
            auto g = get(a[i]);
            if (a[i] > g * g + g) {
                int64_t d = (g + 1) * (g + 1) - a[i];
                assert(d > 0);
                need = max(need, d);
            } else {
                int64_t d = g * g + g - a[i];
                assert(d >= 0);
                got = min(got, d);
            }
        }
        return make_pair(need, got);
    };
    compress();
    int64_t k = 0;
    while (true) {
        auto [need, got] = compute();
        if (need <= got) {
            k += need;
            break;
        } else {
            int64_t x = get(a[0]) + 1;
            int64_t add = max<int64_t>(need, x * x - a[0]);
            k += add;
            shift(add);
            compress();
        }
    }
    cout << k << '\n';
    return 0;
}

// square f(x)>x and square g(x)<=x

// 16 17 18 19 20 21 22 23 24 25
//  1  1  1  1  1  0  0  0  0  .