/**
 *  created: 31/05/2022, 17:37:38
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, a[max_n];

vector<int> solve() {
    vector<int> res;
    for (int i = 0; i < n; ) {
        int pos = i;
        vector<int> cur;
        while (i < n && a[i] == a[pos]) {
            ++i;
            cur.push_back(i);
        }
        if (cur.size() == 1) {
            return {-1};
        }
        rotate(cur.begin(), cur.begin() + 1, cur.end());
        res.insert(res.end(), cur.begin(), cur.end());
    }
    return res;
}

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
        }
        auto ans = solve();
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}