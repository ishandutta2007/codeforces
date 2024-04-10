#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int ans = INT_MAX;
    // Try adjacent guys
    for (int i = 0; i + 1 < N; i++) {
        int b = (a[i] + 1) / 2;
        int c = (a[i + 1] + 1) / 2;
        int d = (a[i] + a[i + 1] + 2) / 3;
        ans = min(ans, max({b, c, d}));
    }
    // Try separated by two
    for (int i = 1; i + 1 < N; i++) {
        ans = min(ans, 1 + a[i - 1] / 2 + a[i + 1] / 2);
    }
    // Try separate guys
    sort(begin(a), end(a));
    ans = min(ans, (a[0] + 1) / 2 + (a[1] + 1) / 2);
    cout << ans << '\n';
    return 0;
}

// 3 8 3 is tricky