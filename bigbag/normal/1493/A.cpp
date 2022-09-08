/**
 *  created: 06/03/2021, 16:06:15
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << n - max(1, (k + 1) / 2) << "\n";
        for (int i = max(1, (k + 1) / 2); i <= n; ++i) {
            if (i != k) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}