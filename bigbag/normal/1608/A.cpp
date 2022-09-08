/**
 *  created: 11/12/2021, 12:05:26
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000000000;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cout << inf - n + i << " ";
        }
        cout << "\n";
    }
    return 0;
}