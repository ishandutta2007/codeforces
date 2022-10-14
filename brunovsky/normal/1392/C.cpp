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
        int64_t ans = 0;
        for (int i = N - 1; i > 0; i--) {
            if (a[i - 1] > a[i]) {
                ans += a[i - 1] - a[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}