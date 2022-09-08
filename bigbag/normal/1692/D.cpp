/**
 *  created: 14/06/2022, 17:42:03
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, h, m, x;

bool ok(int m) {
    vector<int> v;
    int h = m / 60;
    m %= 60;
    v.push_back(h / 10);
    v.push_back(h % 10);
    v.push_back(m / 10);
    v.push_back(m % 10);
    vector<int> rv = v;
    reverse(rv.begin(), rv.end());
    return v == rv;
}

int solve(int m, int x) {
    vector<int> used(1440);
    int ans = 0;
    while (!used[m]) {
        used[m] = 1;
        ans += ok(m);
        m = (m + x) % used.size();
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        char c;
        cin >> h >> c >> m >> x;
        cout << solve(h * 60 + m, x) << "\n";
    }
    return 0;
}