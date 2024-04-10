/**
 *  created: 17/03/2021, 16:35:36
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        set<int> q1;
        multiset<int> q2;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (q1.count(a[i])) {
                q2.insert(a[i]);
            } else {
                q1.insert(a[i]);
            }
        }
        for (int x : q1) {
            cout << x << " ";
        }
        for (int x : q2) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}