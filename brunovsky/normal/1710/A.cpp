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
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> a(K);
        for (int i = 0; i < K; i++) {
            cin >> a[i];
        }

        bool ok = false;
        // Be careful with parity
        // Try vertical wrapping
        {
            int64_t can = 0, more = 0;
            for (int i = 0; i < K; i++) {
                if (a[i] >= 2 * N) {
                    can += a[i] / N;
                    more += a[i] / N - 2;
                }
            }
            if (M % 2 == 0) {
                ok |= can >= M;
            } else {
                ok |= can >= M && more;
            }
        }
        {
            int64_t can = 0, more = 0;
            for (int i = 0; i < K; i++) {
                if (a[i] >= 2 * M) {
                    can += a[i] / M;
                    more += a[i] / M - 2;
                }
            }
            if (N % 2 == 0) {
                ok |= can >= N;
            } else {
                ok |= can >= N && more;
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}