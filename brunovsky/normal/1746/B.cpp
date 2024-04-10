#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int ro = count(begin(a), end(a), 1);
    int rz = N - ro;
    int lo = 0, lz = 0;

    int ans = min(ro, rz);
    for (int i = 0; i + 1 < N; i++) {
        lo += a[i] == 1;
        lz += a[i] == 0;
        ro -= a[i] == 1;
        rz -= a[i] == 0;
        ans = min(ans, max(lo, rz));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}