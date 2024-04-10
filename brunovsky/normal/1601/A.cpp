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
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        constexpr int B = 30;
        array<int, B> cnt = {};

        for (int i = 0; i < N; i++) {
            for (int b = 0; b < B; b++) {
                cnt[b] += a[i] >> b & 1;
            }
        }

        int g = 0;
        for (int b = 0; b < B; b++) {
            g = gcd(g, cnt[b]);
        }

        vector<int> ks;
        for (int k = 1; k <= N; k++) {
            if (g % k == 0) {
                ks.push_back(k);
            }
        }

        for (int i = 0, K = ks.size(); i < K; i++) {
            cout << ks[i] << " \n"[i + 1 == K];
        }
    }

    return 0;
}