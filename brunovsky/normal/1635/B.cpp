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
        vector<int> a(N + 1);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i + 1 < N; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                ans++;
                a[i + 1] = max(a[i], a[i + 2]);
            }
        }
        cout << ans << '\n';
        for (int i = 0; i < N; i++) {
            cout << a[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}