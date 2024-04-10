#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log(msg) clog << __LINE__ << ": " << msg
#else
#define log(msg)
#endif

#define _ << ' ' <<
#define long long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int) v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()

set<char> se;
string s;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> s;

    if (s.size() < 26) return cout << -1, 0;

    bool h = false;
    for (int i = 0; i <= sz(s) - 26; ++i) {
        se.clear();
        for (char c = 'A'; c <= 'Z'; ++c) se.insert(c);
        h = true;
        for (int f = i; f < i + 26; ++f) {
            if (s[f] == '?') continue;
            if (!se.count(s[f])) {
                h = false;
                break;
            }
            se.erase(s[f]);
        }
        if (!h) continue;
        for (int f = i; f < i + 26; ++f) {
            if (s[f] != '?') continue;
            s[f] = *se.bb;
            se.erase(se.bb);
        }
        break;
    }

    if (!h) return cout << -1, 0;
    for (auto& c: s) {
        if (c == '?') c = 'A';
    }

    cout << s;

    return 0;
}