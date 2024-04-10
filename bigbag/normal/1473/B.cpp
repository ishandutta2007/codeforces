/**
 *  created: 14/01/2021, 16:38:19
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t;
string a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        string s = a;
        while (s.size() % b.size()) {
            s += a;
        }
        string t = b;
        while (t.size() != s.size()) {
            t += b;
        }
        if (s == t) {
            puts(s.c_str());
        } else {
            puts("-1");
        }
    }
    return 0;
}