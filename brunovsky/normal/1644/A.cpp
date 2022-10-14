#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int D = 'a' - 'A';
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        set<char> keys;
        bool ok = true;
        for (char c : s) {
            if ('a' <= c && c <= 'z') {
                keys.insert(c);
            } else {
                ok &= keys.count(c + D);
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}