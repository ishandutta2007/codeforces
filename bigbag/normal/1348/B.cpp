#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> v(a, a + n);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if (v.size() > k) {
            cout << "-1\n";
            continue;
        }
        while (v.size() < k) {
            v.push_back(1);
        }
        vector<int> ans;
        int cur = 0;
        for (int i = 0; cur < n; ++i) {
            ans.push_back(v[i % v.size()]);
            if (ans.back() == a[cur]) {
                ++cur;
            }
        }
        cout << ans.size() << "\n";
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}