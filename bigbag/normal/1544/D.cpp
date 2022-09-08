/**
 *  created: 17/07/2021, 18:00:16
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n], ans[max_n], used[max_n];

bool check(const vector<int> &ids) {
    fill(ans, ans + n, -1);
    for (int id : ids) {
        ans[id] = a[id];
    }
    vector<int> pos, val;
    for (int i = 0; i < n; ++i) {
        if (!used[i] && ans[i] == -1) {
            pos.push_back(i);
            val.push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i] && ans[i] == -1) {
        } else if (!used[i]) {
            val.push_back(i);
        } else if (ans[i] == -1) {
            pos.push_back(i);
        }
    }
    assert(val.size() == pos.size());
    if (pos.empty()) {
        return true;
    }
    rotate(val.begin(), val.begin() + 1, val.end());
    for (int i = 0; i < pos.size(); ++i) {
        ans[pos[i]] = val[i];
    }
    for (int i = 0; i < n; ++i) {
        assert(ans[i] != -1);
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == i) {
            return false;
        }
    }
    return true;
}

void solve() {
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    for (int it = 0; it < 2; ++it) {
        fill(used, used + n, 0);
        vector<int> ids;
        for (int i : order) {
            if (!used[a[i]]) {
                used[a[i]] = 1;
                ids.push_back(i);
            }
        }
        if (check(ids)) {
            return;
        }
        reverse(order.begin(), order.end());
    }
    assert(false);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            --a[i];
        }
        solve();
        int tot = 0;
        for (int i = 0; i < n; ++i) {
            tot += a[i] == ans[i];
        }
        printf("%d\n", tot);
        for (int i = 0; i < n; ++i) {
            printf("%d ", ans[i] + 1);
        }
        puts("");
    }
    return 0;
}