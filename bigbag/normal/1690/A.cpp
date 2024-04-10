/**
 *  created: 07/06/2022, 17:36:32
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        int x = (n + 5) / 3;
        int y = x - 1, z = x - 2;
        while (x + y + z > n) {
            if (z > 1) {
                --z;
            } else {
                --y;
            }
        }
        cout << y << " " << x << " " << z << "\n";
    }
    return 0;
}