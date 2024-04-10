/**
 *  created: 25/06/2022, 17:54:03
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 255555, inf = 1000111222;

template<typename T>
struct segment_tree {
    T mn[4 * max_n];

    void build(int v, int l, int r) {
        if (l == r) {
            mn[v] = inf;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, T value) {
        if (l == r) {
            mn[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, value);
        } else {
            update(2 * v + 1, mid + 1, r, pos, value);
        }
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    T get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mn[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int t, n, a[max_n], dp[max_n];
segment_tree<int> st_inc, st_dec;

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
        vector<int> v{a[0]};
        for (int i = 1; i < n; ++i) {
            if (v.back() != a[i]) {
                v.push_back(a[i]);
            }
        }
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        st_inc.build(1, 0, v.size());
        st_dec.build(1, 0, v.size());
        vector<pair<int, int>> dec, inc;
        dec.push_back({inf, -1});
        inc.push_back({-inf, -1});
        dec.push_back({v[0], 0});
        inc.push_back({v[0], 0});

        st_inc.update(1, 0, v.size(), 0, 0);
        st_dec.update(1, 0, v.size(), 0, 0);

        for (int i = 1; i < v.size(); ++i) {
            while (inc.back().first > v[i]) {
                st_inc.update(1, 0, v.size(), inc.back().second, inf);
                inc.pop_back();
            }
            while (dec.back().first < v[i]) {
                st_dec.update(1, 0, v.size(), dec.back().second, inf);
                dec.pop_back();
            }
            if (v[i] < v[i - 1]) {
                dp[i] = 1 + st_dec.get_min(1, 0, v.size(), inc.back().second + 1, v.size());
            } else {
                dp[i] = 1 + st_inc.get_min(1, 0, v.size(), dec.back().second + 1, v.size());
            }
            inc.push_back({v[i], i});
            dec.push_back({v[i], i});
            st_inc.update(1, 0, v.size(), i, dp[i]);
            st_dec.update(1, 0, v.size(), i, dp[i]);
            //cout << i << ": " << dp[i] << endl;
        }
        cout << max(1, dp[v.size() - 1]) << "\n";
    }
    return 0;
}