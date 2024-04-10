#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct Point {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, D1, D2;
    cin >> N >> D1 >> D2;
    vector<Point> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].x >> A[i].y;
        cin >> B[i].x >> B[i].y;
    }
    bool state_large = true;
    long ans = 0;

    // Square
    D1 = D1 * D1;
    D2 = D2 * D2;
    debug(D1, D2);

    auto process_increase = [&](auto lo, auto hi) {
        debug("+", lo, hi);
        assert(lo <= hi);
        if (!state_large && hi >= D2) {
            state_large = true;
        }
    };
    auto process_decrease = [&](auto hi, auto lo) {
        debug("-", hi, lo);
        assert(lo <= hi);
        if (state_large && lo <= D1) {
            state_large = false;
            ans++;
            debug("HELLO");
        }
    };

    for (int i = 0; i + 1 < N; i++) {
        auto [x1, y1] = A[i];
        auto [x2, y2] = A[i + 1];
        auto [x3, y3] = B[i];
        auto [x4, y4] = B[i + 1];
        auto c1 = x1 - x3;
        auto c2 = x2 - x4;
        auto c3 = y1 - y3;
        auto c4 = y2 - y4;
        auto d1 = c2 - c1;
        auto d3 = c4 - c3;
        // c1 + td1, c3 + td3
        auto a = d1 * d1 + d3 * d3;
        auto b = 2 * (c1 * d1 + c3 * d3);
        auto c = c1 * c1 + c3 * c3;
        // distance at time t: at^2 + bt + c
        assert(a >= 0 && c >= 0);

        auto f = [&](auto t) { return a * t * t + b * t + c; };
        // debug(i, a, b, c);

        // process first
        if (i == 0) {
            process_decrease(f(0), f(0));
        }

        if (a > 0) {
            if (b >= 0) {
                // the eye of the parabola is at negative t, so [0,1] is increasing
                process_increase(f(0), f(1));
            } else if (b < 0) {
                // the eye of the parabola is at positive t
                if (-b < 2 * a) {
                    double t = -b / (2.0 * a);
                    assert(0 < t && t < 1);
                    process_decrease(f(0), f(t));
                    process_increase(f(t), f(1));
                } else {
                    process_decrease(f(0), f(1));
                }
            }
        } else {
            if (b > 0) {
                process_increase(f(0), f(1));
            } else if (b < 0) {
                process_decrease(f(0), f(1));
            }
        }
    }

    cout << ans << '\n';
    return 0;
}