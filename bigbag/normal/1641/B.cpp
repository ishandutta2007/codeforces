/**
 *  created: 23/02/2022, 13:04:29
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 505, inf = 1000111222;

int t, n, a[max_n];

bool bad() {
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i]];
    }
    for (auto [x, c] : cnt) {
        if (c % 2) {
            return true;
        }
    }
    return false;
}

vector<pair<int, int>> ops;
vector<int> ans;

void solve(vector<int> v, int shift) {
    if (v.empty()) {
        return;
    }
    int pos = 1;
    while (v[0] != v[pos]) {
        ++pos;
    }
    for (int i = 1; i < pos; ++i) {
        ops.push_back({pos + i + shift, v[i]});
    }
    ans.push_back(2 * pos);
    v.erase(v.begin() + pos);
    v.erase(v.begin());
    reverse(v.begin(), v.begin() + (pos - 1));
    solve(v, shift + 2 * pos);
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
        if (bad()) {
            cout << "-1\n";
        } else {
            ops.clear();
            ans.clear();
            solve({a, a + n}, 0);
            cout << ops.size() << "\n";
            for (auto [x, y] : ops) {
                cout << x << " " << y << "\n";
            }
            cout << ans.size() << "\n";
            for (int len : ans) {
                cout << len << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}