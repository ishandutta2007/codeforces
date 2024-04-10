/**
 *  created: 10/06/2022, 20:43:11
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;
const int max_b = 31;

int t, n, a[max_n];
int cnt[max_b][max_b];

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void add(int x, int sign) {
    for (int i = 0; i < max_b; ++i) {
        if (get_bit(x, i)) {
            for (int j = i + 1; j < max_b; ++j) {
                if (get_bit(x, j)) {
                    cnt[i][j] += sign;
                    cnt[j][i] += sign;
                }
            }
        }
    }
}

void dfs(int v, int &used) {
    used |= 1 << v;
    for (int i = 0; i < max_b; ++i) {
        if (cnt[v][i] && !get_bit(used, i)) {
            dfs(i, used);
        }
    }
}

bool check() {
    int full = 0;
    for (int i = 0; i < n; ++i) {
        if (!a[i]) {
            return false;
        }
        full |= a[i];
    }
    int id = __builtin_ctz(full);
    int res = 0;
    dfs(id, res);
    return res == full;
}

int solve() {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
        add(a[i], 1);
    }
    if (check()) {
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int x = -1; x <= 1; x += 2) {
            add(a[i], -1);
            a[i] += x;
            add(a[i], 1);
            if (check()) {
                return 1;
            }
            add(a[i], -1);
            a[i] -= x;
            add(a[i], 1);
        }
    }
    for (int mx = max_b; mx >= 0; --mx) {
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (a[i] % (1 << mx) == 0) {
                v.push_back(i);
            }
        }
        if (v.size()) {
            assert(mx);
            assert(v.size() >= 2);
            --a[v[0]];
            ++a[v[1]];
            return 2;
        }
    }
    assert(0);
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
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!a[i]) {
                ++a[i];
                ++ans;
            }
        }
        ans += solve();
        cout << ans << "\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}