#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        if (!count(a.begin(), a.end(), 1)) {
            cout << "YES\n";
        } else {
            if (count(a.begin(), a.end(), 0)) {
                cout << "NO\n";
            } else {
                bool ans = true;
                for (int i = 1; i < a.size(); ++i) {
                    if (a[i] - a[i - 1] == 1)
                        ans = false;
                }
                cout << (ans ? "YES\n" : "NO\n");
            }
        }
    }
}