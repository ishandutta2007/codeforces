#include <bits/stdc++.h>

using namespace std;

int t;
string s;

void solve() {
    for (int i = 0; i + 1 < s.length(); ++i) {
        if (s[i] == s[i + 1] && s[i] != '?') {
            puts("-1");
            return;
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '?') {
            for (char c = 'a'; c <= 'c'; ++c) {
                if ((!i || s[i - 1] != c) && (i + 1 == s.length() || s[i + 1] != c)) {
                    s[i] = c;
                }
            }
        }
    }
    cout << s << "\n";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        solve();
    }
    return 0;
}