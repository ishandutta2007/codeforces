#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> p(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }
    vector<int> where(N + 1);
    for (int i = 1; i <= N; i++) {
        where[p[i]] = i;
    }
    vector<array<int, 2>> ops;
    auto do_swap = [&](int i, int j) {
        ops.push_back({i, j});
        swap(where[p[i]], where[p[j]]), swap(p[i], p[j]);
        assert(j - i >= N / 2);
    };
    auto do_safe_swap = [&](int a, int b) {
        if (a == b) {
            return;
        } else if (b - a >= N / 2) {
            do_swap(a, b);
        } else if (a <= N / 2 && b <= N / 2) {
            do_swap(b, N);
            do_swap(a, N);
        } else if (a <= N / 2 && b > N / 2) {
            do_swap(1, b);
            do_swap(1, N);
            do_swap(a, N);
            do_swap(1, b);
        } else if (a > N / 2 && b > N / 2) {
            do_swap(1, b);
            do_swap(1, a);
            do_swap(1, b);
        } else {
            assert(false);
        }
    };
    for (int v = 1; v <= N; v++) {
        if (v != where[v]) {
            do_safe_swap(min(where[v], v), max(where[v], v));
        }
    }
    debug(p);
    debug(where);
    int S = ops.size();
    cout << S << '\n';
    for (int i = 0; i < S; i++) {
        auto [x, y] = ops[i];
        cout << x << ' ' << y << '\n';
    }
    return 0;
}