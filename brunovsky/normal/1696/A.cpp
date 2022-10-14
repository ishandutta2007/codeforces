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
        int N, z;
        cin >> N >> z;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = max(ans, a[i] | z);
        }
        cout << ans << '\n';
    }
    return 0;
}