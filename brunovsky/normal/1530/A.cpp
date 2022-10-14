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
        string s = to_string(N);
        int ans = 1;
        int S = s.size();
        for (int i = 0; i < S; i++) {
            ans = max(ans, s[i] - '0');
        }
        cout << ans << '\n';
    }
    return 0;
}