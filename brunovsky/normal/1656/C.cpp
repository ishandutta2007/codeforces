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
        sort(begin(a), end(a));
        a.erase(unique(begin(a), end(a)), end(a));
        N = a.size();
        bool ok;
        if (a[0] >= 2) {
            ok = true;
        } else if (a[0] == 0) {
            ok = N == 1 || a[1] >= 2;
        } else {
            assert(a[0] == 1);
            ok = true;
            for (int i = 1; i < N; i++) {
                ok &= a[i] != a[i - 1] + 1;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}

// If all 1s ok