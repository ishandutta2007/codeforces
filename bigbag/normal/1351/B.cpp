#include <bits/stdc++.h>

using namespace std;

int t, a[2], b[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> b[0] >> b[1];
        string ans = "No";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (a[1] == b[1] && a[0] + b[0] == a[1]) {
                    ans = "Yes";
                }
                swap(a[0], a[1]);
            }
            swap(b[0], b[1]);
        }
        cout << ans << "\n";
    }
    return 0;
}