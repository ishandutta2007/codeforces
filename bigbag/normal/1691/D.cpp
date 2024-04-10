/**
 *  created: 31/05/2022, 17:51:10
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

template<typename T>
struct segment_tree {
    T f[4 * max_n];
    T mn[4 * max_n];

    void build(int v, int l, int r) {
        f[v] = 0;
        if (l == r) {
            mn[v] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            mn[2 * v] += f[v];
            mn[2 * v + 1] += f[v];
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] += value;
            mn[v] += value;
            return;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    T get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mn[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int t, n, a[max_n];
segment_tree<long long> st;

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
        vector<pair<int, int>> v{{inf, -1}};
        st.build(1, 0, n - 1);
        string ans = "YES";
        for (int i = 0; i < n; ++i) {
            while (v.size() > 1 && a[i] >= v.back().first) {
                st.update(1, 0, n - 1, v[v.size() - 2].second + 1, v.back().second, a[i] - v.back().first);
                v.pop_back();
            }
            v.push_back({a[i], i});
            if (i) {
                st.update(1, 0, n - 1, 0, i - 1, -a[i]);
            }
            if (st.mn[1] < 0) {
                ans = "NO";
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}