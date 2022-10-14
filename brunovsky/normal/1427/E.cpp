#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int64_t gcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
    int64_t xn = 1, yn = 0;
    x = 0, y = 1;
    while (a != 0) {
        int64_t q = b / a;
        b = b % a;
        x = x - q * xn, y = y - q * yn;
        swap(a, b), swap(x, xn), swap(y, yn);
    }
    if (b < 0) {
        b = -b, x = -x, y = -y;
    }
    return b;
}

int64_t invmod(int64_t a, int64_t m) {
    int64_t x, y, g = gcd(a, m, x, y);
    (void)g, assert(g == 1);
    x = x % m;
    return x < 0 ? x + m : x;
}

auto solve(int64_t x) {
    vector<array<int64_t, 3>> ops;
    // Produce a * y, given that y has already been produced
    auto prodadd = [&](int64_t a, int64_t b) { ops.push_back({a, b, 0}); };
    auto prodxor = [&](int64_t a, int64_t b) { ops.push_back({a, b, 1}); };
    auto prodmul = [&](int64_t a, int64_t y) {
        int64_t c = a;
        int S = 0;
        while (c > 0) {
            S++, c >>= 1;
        }

        for (int b = 0; b < S; b++) {
            prodadd((1LL << b) * y, (1LL << b) * y);
        }
        int64_t z = 0;
        for (int b = 0; b < S; b++) {
            if (a >> b & 1) {
                if (z == 0) {
                    z = (1LL << b) * y;
                } else {
                    prodadd(z, (1LL << b) * y);
                    z += (1LL << b) * y;
                }
            }
        }
    };
    for (int64_t a = 1; true; a += 2) {
        int64_t y = x ^ (a * x);
        if (gcd(x, y) != 1) {
            continue;
        }
        prodmul(a, x);
        prodxor(x, a * x);
        int64_t u = invmod(x, y);
        int64_t v = (u * x - 1) / y;
        assert(u >= 0 && v >= 0);
        prodmul(u, x);
        prodmul(v, y);
        prodxor(u * x, v * y);
        break;
    }
    cout << ops.size() << '\n';
    for (auto [a, b, op] : ops) {
        assert(a >= 0 && b >= 0);
        if (op == 0) {
            cout << a << " + " << b << '\n';
        } else {
            cout << a << " ^ " << b << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int64_t x;
    cin >> x;
    solve(x);
    return 0;
}