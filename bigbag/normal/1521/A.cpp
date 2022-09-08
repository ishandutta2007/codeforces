/**
 *  created: 07/05/2021, 17:37:21
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (b == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if (b == 2) {
                cout << a << " " << 1LL * a * 3 << " " << 1LL * a * 4 << "\n";
            } else {
                cout << a << " " << 1LL * a * (b - 1) << " " << 1LL * a * b << "\n";
            }
        }
    }
    return 0;
}