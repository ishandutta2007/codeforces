/**
 *  created: 27/01/2022, 16:56:40
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, k, a[max_n];
int cnt[max_n];

int get_sum(int l, int r) {
    return cnt[r] - cnt[l - 1];
}

pair<int, int> check(int d) {
    for (int x = 1; x + d - 1 <= n; ++x) {
        int c1 = get_sum(x, x + d - 1);
        int c2 = n - c1;
        if (c1 - c2 >= k) {
            return {x, x + d - 1};
        }
    }
    return {-1, -1};
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        fill(cnt, cnt + n + 1, 0);
        for (int i = 0; i < n; ++i) {
            ++cnt[a[i]];
        }
        for (int i = 1; i <= n; ++i) {
            cnt[i] += cnt[i - 1];
        }
        int l = -1, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid).first != -1) {
                r = mid;
            } else {
                l = mid;
            }
        }
        auto [x, y] = check(r);
        cout << x << " " << y << "\n";
        int bal = 0;
        vector<int> v{-1};
        for (int i = 0; i < n; ++i) {
            if (x <= a[i] && a[i] <= y) {
                ++bal;
            } else {
                --bal;
            }
            if (bal > 0) {
                v.push_back(i);
                bal = 0;
            }
        }
        while (v.size() > k + 1) {
            v.pop_back();
        }
        assert(v.size() == k + 1);
        v.back() = n - 1;
        for (int i = 0; i + 1 < v.size(); ++i) {
            cout << v[i] + 2 << " " << v[i + 1] + 1 << "\n";
        }
    }
    return 0;
}