#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int pop(int64_t x) { return __builtin_popcountll(x); }
int par(int64_t x) { return pop(x) % 2; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> val(N);
    vector<int64_t> mask(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i] >> mask[i];
    }
    int64_t V = accumulate(begin(val), end(val), 0LL);
    if (V > 0) {
        for (int i = 0; i < N; i++) {
            val[i] = -val[i];
        }
        V = -V;
    }
    constexpr int B = 62;
    int64_t M = 0;
    for (int b = 0; b < B; b++) {
        int64_t C = 0;
        for (int i = 0; i < N; i++) {
            if (mask[i] < (2LL << b)) {
                C += val[i];
            }
        }
        int64_t D = 0;
        for (int i = 0; i < N; i++) {
            if (mask[i] < (2LL << b) && mask[i] >> b & 1) {
                D += val[i];
            }
        }
        if (D < 0) {
            for (int i = 0; i < N; i++) {
                if (mask[i] >> b & 1) {
                    val[i] = -val[i];
                }
            }
            M |= 1LL << b;
            C -= 2 * D;
        }
        assert(C >= 0);
    }
    cout << M << '\n';
    return 0;
}