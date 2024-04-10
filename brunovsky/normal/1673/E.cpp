#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

// HOW MANY TIMES IS IT ODD
int prefix_count(int n, int s) {
    if (s == 0) {
        return 1;
    }
    int b = 31 - __builtin_clz(s);
    if (n >> b & 1) {
        int c = __builtin_popcount(n & ((1 << b) - 1)) == 0;
        return c ^ prefix_count(n - (1 << b), s - (1 << b));
    } else {
        int c = __builtin_popcount(n & ((1 << b) - 1)) == 0;
        return c;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    int B = N - 1 - K; // at most this many power symbols

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int M = 1 << 20;

    vector<int8_t> ans(M);

    auto check = [&](int b, int c, int r) {
        // we only care about parity... yikes
        // (c 0) + (c 1) + (c 2) + ... + (c r) what is the parity of this?
        // (c p) odd iff every bit of p is less than that of c
        ans[b] ^= prefix_count(c, min(r, c));
    };

    // (bit, remaining cells, powers used)
    vector<tuple<int, int, int>> consider;

    // only need to consider windows of size at most 20
    for (int i = 0; i < N; i++) {
        int64_t b = P[i];
        int count = (i > 0) + (i < N - 1);
        check(b, N - 1 - count, B);

        for (int r = 1; i + r < N && r <= min(20, B); r++) {
            int p = P[i + r];
            while (b < M && p > 0) {
                b *= 2, p--;
            }
            if (b >= M) {
                break;
            }
            count = (i > 0) + (i + r < N - 1);
            check(b, N - 1 - r - count, B - r);
        }
    }

    while (M > 1 && ans.back() == 0) {
        ans.pop_back(), M--;
    }
    reverse(begin(ans), end(ans));
    for (int i = 0; i < M; i++) {
        cout << int(ans[i]);
    }
    cout << '\n';
    return 0;
}