/**
 *  created: 30/12/2020, 16:36:02
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<int> q;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                q.insert(a[j] - a[i]);
            }
        }
        cout << q.size() << "\n";
    }
    return 0;
}