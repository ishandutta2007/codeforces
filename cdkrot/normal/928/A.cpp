#include <bits/stdc++.h>

using namespace std;

void norm(string &s) {
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '0') s[i] = 'O';
        if (s[i] == '1') s[i] = 'L';
        if ('a' <= s[i] && s[i] <= 'z') {
            s[i] = char(s[i] +'A' - 'a');
        }
        if (s[i] == 'I') s[i] = 'L';
    }
}

int main() {

    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

    string s;
    cin >> s;
    norm(s);
    int n;
    cin >> n;
    for (int z = 0; z < n; ++z) {
        string t;
        cin >> t;
        if (t.size() != s.size()) continue;
        norm(t);
        if (s == t) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}