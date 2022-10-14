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
        vector<int> h(N);
        for (int i = 0; i < N; i++) {
            cin >> h[i];
        }

        int L = 1, R = h[N - 1] + 1;
        while (L + 1 < R) {
            int M = L + (R - L) / 2;

            bool ok = true;
            vector<int> p = h;

            for (int i = N - 1; i >= 2; i--) {
                if (p[i] < M) {
                    ok = false;
                    break;
                }
                // pick d such that 3d<=h[i] and p[i]-3d>=M
                // d<=h[i]/3 and d<=(p[i]-M)/3
                int d = min(h[i] / 3, (p[i] - M) / 3);
                p[i] -= 3 * d;
                p[i - 1] += d;
                p[i - 2] += 2 * d;
            }

            ok &= p[1] >= M && p[0] >= M;

            if (ok) {
                L = M;
            } else {
                R = M;
            }
        }

        cout << L << '\n';
    }
    return 0;
}