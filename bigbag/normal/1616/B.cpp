/**
 *  created: 29/12/2021, 17:39:17
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
        string ans;
        for (char c : s) {
            if (ans.empty() || c <= ans.back()) {
                ans += c;
            } else {
                break;
            }
        }
        ans += ans;
        reverse(ans.begin() + ans.size() / 2, ans.end());
        string upd;
        upd += s[0];
        upd += upd;
        ans = min(ans, upd);
        cout << ans << "\n";
    }
    return 0;
}