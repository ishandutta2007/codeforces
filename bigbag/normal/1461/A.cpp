/**
 *  created: 11/12/2020, 16:36:06
**/

#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string ans;
        for (int i = 0; i < n; ++i) {
            ans += 'a' + i % 3;
        }
        cout << ans << "\n";
    }
    return 0;
}