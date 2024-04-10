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
        int m = max_element(begin(a), end(a)) - begin(a);
        bool ok = true;
        ok &= is_sorted(begin(a), begin(a) + m);
        ok &= is_sorted(begin(a) + m, end(a), greater<int>{});
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}