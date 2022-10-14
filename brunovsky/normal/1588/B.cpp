#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto QUERY(int l, int r) {
    assert(1 <= l && l <= r);
    cout << "? " << l << ' ' << r << endl;
    int64_t x;
    cin >> x;
    if (x == -1) {
        exit(0);
    }
    return x;
}

// one index in [i,k)
auto find_any(int N, int64_t All) {
    int L = 0, R = N;
    while (L + 1 < R) {
        int M = (L + R) / 2;
        int64_t m = QUERY(1, M);
        if (m == 0) {
            L = M;
        } else if (m == All) {
            R = M;
        } else {
            return make_pair(m, M);
        }
    }
    assert(false);
}

auto bsup(int N, int64_t have, int64_t add, int64_t target) {
    int64_t L = 0, R = N;
    while (L + 1 < R) {
        int64_t M = L + (R - L) / 2;
        // add+(add+1)+...+(add+M)
        // =(M+1)add + M(M-1)/2
        int64_t get = have + (M + 1) * add + M * (M - 1) / 2;
        if (get < target) {
            L = M;
        } else if (get > target) {
            R = M;
        } else {
            return M + 1;
        }
    }
    return L + 1;
}

auto bschoose(int N, int64_t x) {
    int L = 0, R = N;
    while (L + 1 < R) {
        int64_t M = (L + R) / 2;
        int64_t y = M * (M - 1) / 2;
        if (y < x) {
            L = M;
        } else if (y > x) {
            R = M;
        } else {
            return M;
        }
    }
    assert(false);
}

array<int, 3> solve(int N, int i, int64_t B, int64_t All) {
    if (i < N) { // try advance right
        int64_t C = QUERY(1, i + 1);
        int64_t add = C - B;
        assert(B <= C);
        if (add == 0) {
            return solve(N, i + 1, C, All);
        }
        int k = i + bsup(N, B, add, All);
        assert(k <= N && k > i);
        int64_t E = QUERY(1, k);
        debug(k, E, All);
        if (E == All) {
            // found k
            // find j
            int j = i - (add - 1);
            int64_t R = B - (add - 1) * add / 2;
            i = j - bschoose(N, R);
            return {i, j, k};
        } else {
            return solve(N, k, QUERY(1, k), All);
        }
    } else {
        return solve(N, i - 1, QUERY(1, i - 1), All);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        int64_t All = QUERY(1, N);
        auto [B, M] = find_any(N, All);
        auto [i, j, k] = solve(N, M, B, All);

        cout << "! " << i << ' ' << j << ' ' << k << endl;
    }
    return 0;
}