/**
 *  created: 06/02/2022, 16:39:15
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int t, n, x, a[max_n];
long long y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            x ^= a[i];
        }
        if (x % 2 == y % 2) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    return 0;
}