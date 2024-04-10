#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> d1(n), d2(n);
    for (int i = 0; i < n; ++i) {
        cin >> d1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> d2[i];
    }

    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());

    vector<int> type(n);
    int D = -1;

    auto check = [&](int d) {
        multiset<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(d2[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i64(d) + d1[i] <= 2e9 && s.count(d1[i] + d)) {
                type[i] = 0;
                s.erase(s.find(d1[i] + d));
            } else if (d1[i] > d && s.count(d1[i] - d)) {
                type[i] = 1;
                s.erase(s.find(d1[i] - d));
            } else {
                auto it = s.find(d - d1[i]);
                if (it == s.end()) {
                    return false;
                }
                type[i] = 2;
                s.erase(it);
            }
        }
        D = d;
        return true;
    };

    for (int i = 0; i < n; ++i) {
        if (check(abs(d1[0] - d2[i]))) {
            break;
        }
        if (check(abs(d1[0] + d2[i]))) {
            break;
        }
    }

    if (D == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int p1 = 0, p2 = D;
        vector<int> h;
        for (int i = 0; i < n; ++i) {
            if (type[i] == 0) {
                h.push_back(p1 - d1[i]);
            } else if (type[i] == 2) {
                h.push_back(p1 + d1[i]);
            } else {
                h.push_back(p1 + d1[i]);
            }
        }
        sort(h.begin(), h.end());

        int x = min(0, h[0]);
        for (int i = 0; i < n; ++i) {
            cout << h[i] - x << " \n"[i == n - 1];
        }
        cout << p1 - x << " " << p2 - x << "\n";
    }

} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) { 
        solve();
    }

    return 0;
}