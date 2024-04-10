#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map <int, int> m1;
        bool ans = false;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            if (m1.count(x - k))
                ans = true;
            if (m1.count(x + k))
                ans = true;
            m1[x] = 1;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}