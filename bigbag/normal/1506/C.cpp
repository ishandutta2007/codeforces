/**
 *  created: 25/03/2021, 16:43:36
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
        int ans = a.size() + b.size();
        for (int l = 0; l < a.size(); ++l) {
            string s;
            for (int r = l; r < a.size(); ++r) {
                s += a[r];
                bool ok = 0;
                for (int i = 0; i + s.size() <= b.size(); ++i) {
                    if (b.substr(i, s.size()) == s) {
                        ok = 1;
                        break;
                    }
                }
                if (ok) {
                    ans = min<int>(ans, a.size() + b.size() - 2 * (r - l + 1));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}