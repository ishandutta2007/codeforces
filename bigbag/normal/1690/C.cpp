/**
 *  created: 07/06/2022, 17:44:31
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;

int t, n, a[max_n], b[max_n];

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
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, a[i]);
            cout << b[i] - mx << " ";
            mx = max(mx, b[i]);
        }
        cout << "\n";
    }
    return 0;
}