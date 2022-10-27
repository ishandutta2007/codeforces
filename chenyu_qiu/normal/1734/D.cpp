#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<long long> pre(n + 2), suf(n + 2);
    for (int i = 1; i <= n; ++i) {
        pre[i] = min(0ll, pre[i - 1] + a[i]);
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = min(0ll, suf[i + 1] + a[i]);
    }

    int l = k, r = k;
    long long sum = a[k];

    int l1, r1;
    long long ml, mr, sl, sr;

    auto calc_l = [&](int l) {
        l1 = l - 1;
        sl = a[l - 1];
        ml = min(0, a[l - 1]);
        while (l1 > 1 && sl < 0) {
            --l1;
            sl += a[l1];
            ml = min(ml, sl);
        }
    };

    auto calc_r = [&](int r) {
        r1 = r + 1;
        sr = a[r + 1];
        mr = min(0, a[r + 1]);
        while (r1 < n && sr < 0) {
            ++r1;
            sr += a[r1];
            mr = min(mr, sr);
        }
    };

    calc_l(k);
    calc_r(k);

    while (l != 1 && r != n) {
        if (sum + pre[l - 1] >= 0 || sum + suf[r + 1] >= 0) {
            cout << "YES\n";
            return;
        }
        if (sl >= 0 && sum + ml >= 0) {
            sum += sl;
            l = l1;
            calc_l(l);
        } else if (sr >= 0 && sum + mr >= 0) {
            sum += sr;
            r = r1;
            calc_r(r);
        } else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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