/**
 *  created: 11/12/2021, 12:37:57
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, mn_suf[max_n], mx_pref[max_n], ans[max_n];
pair<pair<int, int>, int> a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first.first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first.second;
            ans[i] = 0;
        }
        sort(a, a + n);
        mx_pref[0] = a[0].first.second;
        for (int i = 1; i < n; ++i) {
            mx_pref[i] = max(mx_pref[i - 1], a[i].first.second);
        }
        mn_suf[n - 1] = a[n - 1].first.second;
        for (int i = n - 2; i >= 0; --i) {
            mn_suf[i] = min(mn_suf[i + 1], a[i].first.second);
        }
        int pos = n - 1;
        while (pos && mx_pref[pos - 1] > mn_suf[pos]) {
            --pos;
        }
        for (int i = pos; i < n; ++i) {
            ans[a[i].second] = 1;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}