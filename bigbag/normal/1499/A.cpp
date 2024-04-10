/**
 *  created: 18/03/2021, 16:51:08
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, k1, k2, w, b;

int get_cnt(int k1, int k2) {
    return min(k1, k2) + (max(k1, k2) - min(k1, k2)) / 2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k1 >> k2 >> w >> b;
        if (get_cnt(k1, k2) >= w && get_cnt(n - k1, n - k2) >= b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}