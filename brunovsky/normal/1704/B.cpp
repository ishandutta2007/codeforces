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
        int64_t x;
        cin >> N >> x;
        vector<int64_t> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        debug(N, x, a);
        int ops = 0;
        for (int l = 0, r = 0; l < N; l = r) {
            int64_t L = -1e12, R = 1e12;
            while (r < N && max(L, a[r] - x) <= min(R, a[r] + x)) {
                L = max(L, a[r] - x);
                R = min(R, a[r] + x);
                r++;
            }
            debug(l, r, L, R);
            ops++;
        }
        cout << ops - 1 << '\n';
    }
    return 0;
}