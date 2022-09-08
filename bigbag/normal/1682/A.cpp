/**
 *  created: 22/05/2022, 17:39:56
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = 0;
        if (n % 2 == 0) {
            int len = 0;
            while (n / 2 - len >= 0 && n / 2 + len < n && s[n / 2 - len] == s[n / 2 + len]) {
                ++len;
            }
            ans = 2 * len;
        } else {
            int len = 0;
            while (n / 2 - len >= 0 && n / 2 + 1 + len < n && s[n / 2 - len] == s[n / 2 + 1 + len]) {
                ++len;
            }
            ans = 2 * len + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}