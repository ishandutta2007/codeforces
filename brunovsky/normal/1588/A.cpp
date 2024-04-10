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

        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }

        sort(begin(a), end(a));
        sort(begin(b), end(b));

        bool ok = true;
        for (int i = 0; i < N; i++) {
            ok &= a[i] == b[i] || a[i] + 1 == b[i];
        }
        debug(a, b);

        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}