/**
 *  created: 03/01/2022, 17:21:31
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200111, inf = 1000111222;

int t, n, m, a[max_n], ans[max_n], start[max_n];
long long sum[max_n];
vector<int> all[max_n];

bool proc(int l, int r, multiset<int> &q) {
    for (int i = l; i <= r; ++i) {
        auto it = q.lower_bound((sum[i] + all[i].size() - 1) / all[i].size());
        if (it == q.end()) {
            return false;
        }
        q.erase(it);
    }
    return true;
}

void solve(int l, int r, bool bad, multiset<int> q) {
    if (bad) {
        for (int i = l; i <= r; ++i) {
            for (int j = start[i]; j < start[i] + all[i].size(); ++j) {
                ans[j] = 0;
            }
        }
        return;
    }
    if (l == r) {
        for (int i = start[r]; i < start[r] + all[r].size(); ++i) {
            int val = (sum[r] - all[r][i - start[r]] + all[r].size() - 2) / (all[r].size() - 1);
            if (q.lower_bound(val) != q.end()) {
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        }
        return;
    }
    int mid = (l + r) / 2;
    auto q1 = q;
    if (proc(l, mid, q1)) {
        solve(mid + 1, r, 0, q1);
    } else {
        solve(mid + 1, r, 1, q1);
    }

    if (proc(mid + 1, r, q)) {
        solve(l, mid, 0, q);
    } else {
        solve(l, mid, 1, q);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int cur_start = 0;
        for (int i = 0; i < m; ++i) {
            int k;
            cin >> k;
            all[i].resize(k);
            sum[i] = 0;
            for (int &x : all[i]) {
                cin >> x;
                sum[i] += x;
            }
            start[i] = cur_start;
            cur_start += k;
        }
        sort(a, a + n);
        multiset<int> q;
        q.insert(a, a + n);
        solve(0, m - 1, 0, q);
        for (int i = 0; i < cur_start; ++i) {
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}