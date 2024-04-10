/**
 *  created: 12/09/2021, 17:39:10
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        int mn = inf, mx = -inf, cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                mn = min(mn, i);
                mx = max(mx, i);
                ++cnt;
            }
        }
        if (!cnt) {
            cout << "0\n";
        } else if (cnt == mx - mn + 1) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    return 0;
}