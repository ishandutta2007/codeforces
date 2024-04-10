/**
 *  created: 25/06/2022, 17:38:38
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
        int cnt = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cnt += a[i] == 0;
        }
        while (c1 < n && a[c1] == 0) {
            ++c1;
        }
        while (c2 < n && a[n - c2 - 1] == 0) {
            ++c2;
        }
        if (cnt == n) {
            cout << "0\n";
        } else if (cnt == c1 + c2) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    return 0;
}