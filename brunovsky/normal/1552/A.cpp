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
        string s;
        cin >> s;
        string u = s;
        sort(begin(u), end(u));
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += u[i] != s[i];
        }
        cout << ans << '\n';
    }
    return 0;
}