/**
 *  created: 23/05/2022, 17:36:35
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        vector<int> mx;
        for (int i = 0; i < 2; ++i) {
            cin >> n;
            for (int j = 0; j < n; ++j) {
                cin >> a[j];
            }
            mx.push_back(*max_element(a, a + n));
        }
        if (mx[0] >= mx[1]) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
        if (mx[0] > mx[1]) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    return 0;
}