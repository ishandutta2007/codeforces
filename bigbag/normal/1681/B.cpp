/**
 *  created: 23/05/2022, 17:40:22
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n], m, b[max_n];

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
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        cout << a[accumulate(b, b + m, 0LL) % n] << "\n";
    }
    return 0;
}