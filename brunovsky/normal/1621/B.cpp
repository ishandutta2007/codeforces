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
        vector<int> l(N), r(N), c(N);
        for (int i = 0; i < N; i++) {
            cin >> l[i] >> r[i] >> c[i];
        }
        int L = 0, R = 0;
        map<array<int, 2>, int> full;
        vector<int> ans(N);
        ans[0] = c[0];
        full[{l[0], r[0]}] = c[0];
        for (int s = 1; s < N; s++) {
            if (l[s] < l[L] || (l[s] == l[L] && c[s] < c[L])) {
                L = s;
            }
            if (r[s] > r[R] || (r[s] == r[R] && c[s] < c[R])) {
                R = s;
            }
            // But is the whole segments still good?
            ans[s] = L == R ? c[L] : c[L] + c[R];
            if (full.count({l[s], r[s]})) {
                full[{l[s], r[s]}] = min(full.at({l[s], r[s]}), c[s]);
            } else {
                full[{l[s], r[s]}] = c[s];
            }
            if (full.count({l[L], r[R]})) {
                ans[s] = min(ans[s], full.at({l[L], r[R]}));
            }
        }

        for (int i = 0; i < N; i++) {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}