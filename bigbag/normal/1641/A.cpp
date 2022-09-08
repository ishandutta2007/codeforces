/**
 *  created: 23/02/2022, 12:13:57
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;

int t, n, y, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> y;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        multiset<int> q(a, a + n);
        int ans = 0;
        while (!q.empty()) {
            int x = *q.rbegin();
            q.erase(q.find(x));
            if (x % y == 0 && q.find(x / y) != q.end()) {
                q.erase(q.find(x / y));
                ans += 2;
            }
        }
        cout << n - ans << "\n";
    }
    return 0;
}