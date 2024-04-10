#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

struct P {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;

    vector<P> ps(N);
    for (int i = 0; i < N; i++) {
        P lo, hi;
        cin >> lo.x >> lo.y >> hi.x >> hi.y;
        ps[i] = {lo.x + hi.x, lo.y + hi.y};
    }

    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    vector<int> D(N);

    iota(begin(A), end(A), 0);
    iota(begin(B), end(B), 0);
    iota(begin(C), end(C), 0);
    iota(begin(D), end(D), 0);

    // A: left to right
    sort(begin(A), end(A), [&](int i, int j) {
        auto a = ps[i], b = ps[j];
        return make_tuple(a.x, a.y) < make_tuple(b.x, b.y);
    });
    // B: right to left
    sort(begin(B), end(B), [&](int i, int j) {
        auto a = ps[i], b = ps[j];
        return make_tuple(a.x, a.y) > make_tuple(b.x, b.y);
    });
    // C: bottom to top
    sort(begin(C), end(C), [&](int i, int j) {
        auto a = ps[i], b = ps[j];
        return make_tuple(a.y, a.x) < make_tuple(b.y, b.x);
    });
    // D: top to bottom
    sort(begin(D), end(D), [&](int i, int j) {
        auto a = ps[i], b = ps[j];
        return make_tuple(a.y, a.x) > make_tuple(b.y, b.x);
    });

    vector<array<int, 4>> to_be_removed;
    for (int a = 0; a <= K; a++) {
        for (int b = 0; a + b <= K; b++) {
            for (int c = 0; a + b + c <= K; c++) {
                int d = K - a - b - c;
                to_be_removed.push_back({a, b, c, d});
            }
        }
    }

    long ans = LLONG_MAX;
    vector<bool> ondoor(N, true);

    for (auto [a, b, c, d] : to_be_removed) {
        vector<int> removed;
        int ia, ib, ic, id;
        for (ia = 0; a > 0; ia++) {
            if (ondoor[A[ia]]) {
                removed.push_back(A[ia]);
                ondoor[A[ia]] = false;
                a--;
            }
        }
        for (ib = 0; b > 0; ib++) {
            if (ondoor[B[ib]]) {
                removed.push_back(B[ib]);
                ondoor[B[ib]] = false;
                b--;
            }
        }
        for (ic = 0; c > 0; ic++) {
            if (ondoor[C[ic]]) {
                removed.push_back(C[ic]);
                ondoor[C[ic]] = false;
                c--;
            }
        }
        for (id = 0; d > 0; id++) {
            if (ondoor[D[id]]) {
                removed.push_back(D[id]);
                ondoor[D[id]] = false;
                d--;
            }
        }
        while (!ondoor[A[ia]])
            ia++;
        while (!ondoor[B[ib]])
            ib++;
        while (!ondoor[C[ic]])
            ic++;

        assert(ia < N && ib < N && ic < N && id < N);

        long left = ps[A[ia]].x;
        long right = ps[B[ib]].x;
        long low = ps[C[ic]].y;
        long high = ps[D[id]].y;

        long x = (right - left) / 2;
        long y = (high - low) / 2;
        x = max(x, long(1)), y = max(y, long(1));
        debug(left, right, low, high, x, y);

        long area = 1LL * x * y;
        ans = min(ans, area);

        for (int i : removed) {
            ondoor[i] = true;
        }
    }

    assert(count(begin(ondoor), end(ondoor), true) == N);

    cout << ans << '\n';
    return 0;
}