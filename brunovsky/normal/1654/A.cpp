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
        vector<int> pref(N), suff(N);
        pref[0] = a[0], suff[N - 1] = a[N - 1];
        for (int i = 1; i < N; i++) {
            pref[i] = max(pref[i - 1], a[i]);
        }
        for (int i = N - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], a[i]);
        }
        int ans = 0;
        for (int i = 0; i + 1 < N; i++) {
            ans = max(ans, a[i] + suff[i + 1]);
        }
        for (int i = 1; i < N; i++) {
            ans = max(ans, a[i] + pref[i - 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}