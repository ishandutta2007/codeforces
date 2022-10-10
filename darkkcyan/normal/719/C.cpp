#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log(msg) clog << __LINE__ << ": " << msg
#else
#define log(msg)
#endif

#define _ << ' ' <<
#define lim numeric_limits
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

int n, m;
string s;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n >> m >> s;
    if (m == 0) return cout << s, 0;
    int pp = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '.') {
            pp = i;
            break;
        }
    }

    int i;
    for (i = pp + 1; i < sz(s); ++i) {
        if (s[i] >= '5') break;
    }
    if (i == sz(s)) return cout << s, 0;
    s.resize(i);
    while (s[s.size() - 1] != '.') {
        ++s[s.size() - 1];
        -- m;
        if (m == 0) break;
        if (s[s.size() - 1] >= '5') {
            s.resize(s.size() - 1);
        } else break;
    }

    if (s[s.size() - 1] == '.') {
        s.resize(s.size() - 1);
        if (m) {
            reverse(s.bb, s.ee);
            s.resize(s.size() + 1, '0');
            for (int i = 0; i < sz(s); ++i) {
                if (s[i] != '9') {
                    ++s[i];
                    break;
                }
                s[i] = '0';
            }
            while (s[s.size() - 1] == '0') s.resize(s.size() - 1);
            reverse(s.bb, s.ee);
        }
    }

    cout << s;

    return 0;
}