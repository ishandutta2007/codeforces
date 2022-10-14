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
        int N = s.size(), M = t.size();
        if (M > N) {
            cout << "NO\n";
            continue;
        } else if (s == t) {
            cout << "YES\n";
            continue;
        } else if (N == M) {
            cout << "NO\n";
            continue;
        }

        // append blocks of two characters at the end of t
        string u = s;
        while (!u.empty() && !t.empty()) {
            if (u.back() != t.back()) {
                u.pop_back();
                if (!u.empty()) {
                    u.pop_back();
                }
            } else {
                u.pop_back();
                t.pop_back();
            }
        }
        if (t.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}