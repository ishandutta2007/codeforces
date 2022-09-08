#include <bits/stdc++.h>

using namespace std;

const int max_n = 8088, inf = 1000111222;

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
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            bool ok = 0;
            int l = 0, sum = 0;
            for (int j = 0; j < n && !ok; ++j) {
                sum += a[j];
                while (sum > a[i]) {
                    sum -= a[l++];
                }
                ok |= sum == a[i] && l < j;
            }
            ans += ok;
        }
        cout << ans << "\n";
    }
    return 0;
}