/**
 *  created: 10/06/2022, 19:41:05
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }
        if (n == 1) {
            cout << "-1\n";
            continue;
        }
        vector<int> used(n);
        for (int i = 0; i + 2 < n; ++i) {
            for (int x = 0; x < n; ++x) {
                if (!used[x] && x != a[i]) {
                    used[x] = 1;
                    cout << x + 1 << " ";
                    break;
                }
            }
        }
        vector<int> v;
        for (int x = 0; x < n; ++x) {
            if (!used[x]) {
                v.push_back(x);
            }
        }
        if (a[n - 2] == v[0] || a[n - 1] == v[1]) {
            swap(v[0], v[1]);
        }
        if (a[n - 2] == v[0] || a[n - 1] == v[1]) {
            exit(47);
        }
        cout << v[0] + 1 << " " << v[1] + 1 << "\n";
    }
    return 0;
}