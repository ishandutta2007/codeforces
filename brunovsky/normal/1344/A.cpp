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
        vector<bool> vis(N);
        for (int i = 0; i < N; i++) {
            int k = ((i + a[i]) % N + N) % N;
            vis[k] = true;
        }
        if (count(begin(vis), end(vis), true) == N) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}