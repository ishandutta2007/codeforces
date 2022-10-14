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
    vector<int64_t> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    int64_t ans = INT64_MAX;
    for (int i = 1; i + 1 < N; i++) {
        ans = min(ans, a[i + 1] - a[i - 1]);
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