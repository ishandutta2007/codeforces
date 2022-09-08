/**
 *  created: 04/01/2021, 16:35:44
**/

#include <bits/stdc++.h>

using namespace std;

int t, w, h, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> w >> h >> n;
        long long mx = 1LL << (__builtin_ctzll(1LL * w * h));
        if (mx >= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}