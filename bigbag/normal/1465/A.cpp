/**
 *  created: 21/12/2020, 12:00:18
**/

#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int cnt = 0;
        while (cnt < s.length() && s[s.length() - cnt - 1] == ')') {
            ++cnt;
        }
        if (cnt > s.length() - cnt) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}