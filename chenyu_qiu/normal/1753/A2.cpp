#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), coef(n, 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % 2 != 0) {
        cout << "-1\n";
        return;
    }
    sum /= 2;

    if (sum > 0) {
        for (int i = 1; i < n; ++i) {
            if (a[i] == 1 && sum > 0) {
                coef[i] = -1;
                ++i;
                --sum;
            }
        }
    } else {
        for (int i = 1; i < n; ++i) {
            if (a[i] == -1 && sum < 0) {
                coef[i] = -1;
                ++i;
                ++sum;
            }
        }
    }

    if (sum) {
        cout << "-1\n";
        return;
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && coef[i + 1] == -1) {
            ans.push_back({i, i + 1});
            ++i;
        } else {
            ans.push_back({i, i});
        }
    }

    cout << ans.size() << "\n";
    for (auto it : ans) {
        cout << it.first + 1 << " " << it.second + 1 << "\n";
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