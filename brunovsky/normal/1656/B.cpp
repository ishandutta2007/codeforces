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
        set<int> vals(begin(a), end(a));
        bool ok = false;
        for (int i = 0; i < N; i++) {
            // a[i] - a[j] = K
            ok |= vals.count(a[i] - K);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}

//