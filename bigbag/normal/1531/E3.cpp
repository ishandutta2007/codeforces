/**
 *  created: 24/05/2021, 13:23:40
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

string s;
int pos;

vector<int> solve(int l, int r) {
    if (r - l <= 1) {
        return {0};
    }
    int m = (l + r) / 2;
    auto v1 = solve(l, m);
    auto v2 = solve(m, r);
    if (v1.empty() || v2.empty()) {
        return {};
    }
    vector<int> all1, all2;
    int i = l, j = m, k = 0;
    while (i < m && j < r) {
        if (pos == s.size()) {
            return {};
        }
        if (s[pos++] == '0') {
            ++i;
            all1.push_back(k++);
        } else {
            ++j;
            all2.push_back(k++);
        }
    }
    while (i < m) {
        ++i;
        all1.push_back(k++);
    }
    while (j < r) {
        ++j;
        all2.push_back(k++);
    }
    for (int &x : v1) {
        x = all1[x];
    }
    for (int &x : v2) {
        x = all2[x];
        v1.push_back(x);
    }
    return v1;
}

vector<int> solve(int len) {
    pos = 0;
    return solve(0, len);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int l = 0, r = 100011;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (solve(mid).empty()) {
            r = mid;
        } else {
            l = mid;
        }
    }
    auto ans = solve(l);
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x + 1 << " ";
    }
    cout << "\n";
    return 0;
}