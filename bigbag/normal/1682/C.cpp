/**
 *  created: 22/05/2022, 18:04:12
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        map<int, int> cnt;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++cnt[a[i]];
        }
        vector<int> v;
        for (auto [x, y] : cnt) {
            for (int i = 0; i < min(2, y); ++i) {
                v.push_back(x);
            }
        }
        int ans = 0;
        for (int i = 0; i < v.size(); ) {
            int nxt = i;
            while (nxt < v.size() && v[i] == v[nxt]) {
                ++nxt;
            }
            ans = max<int>(ans, 1 + i / 2 + (v.size() - nxt) / 2);
            i = nxt;
        }
        cout << ans << "\n";
    }
    return 0;
}