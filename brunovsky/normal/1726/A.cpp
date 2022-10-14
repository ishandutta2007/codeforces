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
    a.push_back(a[0]);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, a[i] - a[i + 1]);
    }
    for (int i = 1; i < N; i++) {
        ans = max(ans, a[i] - a[0]);
    }
    for (int i = 0; i + 1 < N; i++) {
        ans = max(ans, a[N - 1] - a[i]);
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