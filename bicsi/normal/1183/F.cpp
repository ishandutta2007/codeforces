#include <bits/stdc++.h>

using namespace std;

vector<int> Remove(vector<int> v, int val) {
    vector<int> w;
    for (auto x : v) {
        if (x % val == 0 || val % x == 0) continue;
        w.push_back(x);
    }
    return w;
}

int Backtrack(vector<int> vals, vector<int> chosen) {
    if (vals.empty() || chosen.size() == 3) {
        int ans = 0;
        for (auto x : chosen) ans += x;
        return ans;
    }

    int ret = 0;
    for (int now : {vals[0], vals[0] / 2}) {
        if (find(vals.begin(), vals.end(), now) == vals.end()) continue;
        chosen.push_back(now);
        ret = max(ret, Backtrack(Remove(vals, now), chosen));
        chosen.pop_back();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.rbegin(), a.rend());
        cout << Backtrack(a, {}) << '\n';

        
    }
    return 0;
}