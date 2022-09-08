/**
 *  created: 14/06/2022, 17:36:55
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<int> q(a, a + n);
        int ans = q.size();
        if (ans % 2 != n % 2) {
            --ans;
        }
        cout << ans << "\n";
    }
    return 0;
}