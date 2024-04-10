/**
 *  created: 31/05/2022, 17:43:47
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, k;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        int ans = 0, first = -1, last = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                ans += 11;
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        if (first != -1) {
            if (s.size() - last - 1 <= k) {
                ans -= 10;
                k -= (s.size() - last - 1);
                if (ans != 1 && first <= k) {
                    ans -= 1;
                }
            } else if (first <= k) {
                ans -= 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}