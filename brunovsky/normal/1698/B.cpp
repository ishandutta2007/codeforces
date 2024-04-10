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
        cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        if (K == 1) {
            cout << (N - 1) / 2 << '\n';
        } else {
            int ans = 0;
            for (int i = 1; i + 1 < N; i++) {
                ans += a[i] > a[i - 1] + a[i + 1];
            }
            cout << ans << '\n';
        }
    }
    return 0;
}