#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n;
string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s, s + n, [](const string &a, const string &b) { return a.length() < b.length(); });
    for (int i = 0; i + 1 < n; ++i) {
        bool ok = false;
        for (int j = 0; j + s[i].length() <= s[i + 1].length(); ++j) {
            if (s[i + 1].substr(j, s[i].length()) == s[i]) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << s[i] << endl;
    }
    return 0;
}