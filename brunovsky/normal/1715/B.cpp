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
        int N, K;
        int64_t B, S;
        cin >> N >> K >> B >> S;
        int64_t R = int64_t(K - 1) * N;
        if (S < K * B || S > K * B + R) {
            cout << -1 << '\n';
            continue;
        }
        vector<int64_t> a(N);
        a[0] = K * B;
        int64_t G = S - K * B;
        for (int i = 0; i < N && G > 0; i++) {
            int64_t put = min<int64_t>(K - 1, G);
            a[i] += put;
            G -= put;
        }
        for (int i = 0; i < N; i++) {
            cout << a[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}