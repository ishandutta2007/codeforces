/**
 *  created: 30/10/2021, 18:00:48
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, x, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x > y) {
            cout << x + y << "\n";
        } else {
            cout << y - (y % x) / 2 << "\n";
        }
    }

    return 0;
}