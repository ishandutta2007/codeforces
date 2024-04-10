#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        string s; cin >> s;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (i & 1) {
                if (s[i] == 'z') s[i] = 'y';
                else s[i] = 'z';
            } else {
                if (s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
            }
        }
        cout << s << '\n';
    }
    return 0;
}