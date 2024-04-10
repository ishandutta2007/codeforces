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
        cout << min_element(a.begin(), a.end()) - a.begin() + 1 << ' ' << max_element(a.begin(), a.end()) - a.begin() + 1 << endl;
    }
}