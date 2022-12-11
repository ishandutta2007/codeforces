#include <bits/stdc++.h>
using namespace std;

int T;
bool f[35][35];
string s, t;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> s >> t;
        memset(f, 0, sizeof(f)), f[0][0] = 1;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= t.size(); j++) if (f[i][j]) {
                bool flag = 1;
                for (int k = 0; k < j; k++) flag &= s[i] != t[k];
                if (flag) f[i + 1][j] = 1;
                if (s[i] == t[j] && j < t.size()) f[i + 1][j + 1] = 1;
            }
        }
        cout << (f[s.size()][t.size()] ? "YES" : "NO") << "\n";
    }
    return 0;
}