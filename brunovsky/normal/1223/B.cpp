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
        string s, t;
        cin >> s >> t;
        int has[26] = {};
        for (char c : s) {
            has[c - 'a'] = true;
        }
        bool ok = false;
        for (char c : t) {
            ok |= has[c - 'a'];
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}