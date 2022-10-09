#include <bits/stdc++.h>
using namespace std;

int main() {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s;
        cin >> s;
        bool ok = true;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] != '?') {
                if (i and s[i] == s[i - 1]) {
                    ok = false;
                    break;
                }
                continue;
            }
            for (char  ch: {'a', 'b', 'c'}) {
                if (i and s[i - 1] == ch) continue;
                if (i + 1 < (int)s.size() and s[i + 1] == ch) continue;
                s[i] = ch;
                break;
            }
        }
        if (!ok) {
            cout << "-1\n";
        } else
        cout << s << '\n';
    }
    return 0;
}