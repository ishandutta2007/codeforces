/**
 *  created: 10/03/2021, 17:27:23
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, k;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        int pos = 0;
        while (pos < n - 1 - pos && s[pos] == s[n - 1 - pos]) {
            ++pos;
        }
        if (pos < k || (pos == k && pos > n - 1 - pos)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}