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
    for (int n = 1; n <= N; n++) {
        for (int k = 1; k <= n; k++) {
            cout << "01"[k == 1 || k == n] << " \n"[k == n];
        }
    }
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