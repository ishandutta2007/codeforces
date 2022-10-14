#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), C(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            C[i] = abs(A[i]);
        }
        int64_t sum = accumulate(begin(C), end(C), 0LL);
        vector<int> B(M);
        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }
        sort(begin(B), end(B));
        int G = B[0];
        for (int i = 1; i < M; i++) {
            G = std::gcd(G, B[i]);
        }
        if (G == 1) {
            cout << sum << '\n';
            continue;
        }
        int64_t odds = 0, evens = 0;
        for (int g = 0; g < G; g++) {
            bool odd = false;
            for (int i = g; i < N; i += G) {
                odd ^= A[i] < 0;
            }
            int val = INT_MAX;
            for (int i = g; i < N; i += G) {
                val = min(val, C[i]);
            }
            if (odd) {
                odds += val;
            } else {
                evens += val;
            }
        }
        cout << sum - 2 * min(odds, evens) << '\n';
    }
    return 0;
}