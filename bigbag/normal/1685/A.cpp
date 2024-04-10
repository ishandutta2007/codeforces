/**
 *  created: 25/05/2022, 20:40:20
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

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
        if (n % 2) {
            cout << "NO\n";
        } else {
            sort(a, a + n);
            vector<int> ans;
            for (int i = 0; i < n / 2; ++i) {
                ans.push_back(a[i]);
                ans.push_back(a[n / 2 + i]);
            }
            bool ok = 1;
            for (int i = 0; i < n; ++i) {
                ok &= (ans[i] > ans[(i + n - 1) % n] && ans[i] > ans[(i + 1) % n]) ||
                      (ans[i] < ans[(i + n - 1) % n] && ans[i] < ans[(i + 1) % n]);
            }
            if (ok) {
                cout << "YES\n";
                for (int x : ans) {
                    cout << x << " ";
                }
                cout << "\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}