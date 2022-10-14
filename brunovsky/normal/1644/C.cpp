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
        int N, x;
        cin >> N >> x;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        vector<int> best(N + 1);
        for (int len = 1; len <= N; len++) {
            int sum = best[len] = accumulate(begin(a), begin(a) + len, 0);
            for (int i = len; i < N; i++) {
                sum += a[i] - a[i - len];
                best[len] = max(best[len], sum);
            }
        }
        vector<int> ans(N + 1);
        for (int k = 0; k <= N; k++) {
            for (int len = 0; len <= N; len++) {
                ans[k] = max(ans[k], best[len] + x * min(len, k));
            }
        }
        for (int k = 0; k <= N; k++) {
            cout << ans[k] << " \n"[k == N];
        }
    }
    return 0;
}