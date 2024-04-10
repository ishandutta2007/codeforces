/**
 *  created: 07/06/2022, 17:38:58
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;

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
        int res = 0;
        for (int i = 0; i < k; ++i) {
            res += s[i] == 'W';
        }
        int ans = res;
        for (int i = k; i < n; ++i) {
            res -= s[i - k] == 'W';
            res += s[i] == 'W';
            ans = min(ans, res);
        }
        cout << ans << "\n";
    }
    return 0;
}