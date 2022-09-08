/**
 *  created: 23/02/2022, 12:31:06
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

template<typename T>
struct segment_tree {
    static const T default_value = -1012345678;

    T f[4 * max_n];
    T sum[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        f[v] = default_value;
        if (l == r) {
            sum[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    void push(int v, int l, int r, int mid) {
        if (f[v] != default_value) {
            sum[2 * v] = f[v] * (mid - l + 1);
            sum[2 * v + 1] = f[v] * (r - mid);
            f[2 * v] = f[v];
            f[2 * v + 1] = f[v];
            f[v] = default_value;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] = value;
            sum[v] = value * (r - l + 1);
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
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    T get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return sum[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }

    int get_first(int v, int tl, int tr, int pos) {
        if (sum[v] == tr - tl + 1) {
            return 0;
        }
        if (tl == tr) {
            return tl;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (pos <= mid) {
            return get_first(2 * v, tl, mid, pos);
        }
        int res = get_first(2 * v + 1, mid + 1, tr, pos);
        if (res == 0) {
            return get_first(2 * v, tl, mid, mid);
        }
        return res;
    }

    int get_last(int v, int tl, int tr, int pos) {
        if (sum[v] == tr - tl + 1) {
            return 0;
        }
        if (tl == tr) {
            return tl;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (pos > mid) {
            return get_last(2 * v + 1, mid + 1, tr, pos);
        }
        int res = get_last(2 * v, tl, mid, pos);
        if (res == 0) {
            return get_last(2 * v + 1, mid + 1, tr, mid + 1);
        }
        return res;
    }
};

int n, q;
set<pair<int, int>> bad;
segment_tree<int> st;

void add(int l, int r) {
    auto it = prev(bad.upper_bound({l, inf}));
    assert(it->first <= l);
    if (r <= it->second) {
        bad.erase(it);
        bad.insert({l, r});
        return;
    }
    auto start = bad.lower_bound({l, -inf});
    if (start->second <= r) {
        return;
    }
    bad.insert({l, r});
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bad.insert({-inf, -inf});
    bad.insert({inf, inf});
    cin >> n >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            if (x == 0) {
                st.update(1, 1, n, l, r, 1);
            } else {
                add(l, r);
            }
        } else {
            int id;
            cin >> id;
            if (st.get_sum(1, 1, n, id, id) == 1) {
                cout << "NO\n";
            } else {
                st.update(1, 1, n, id, id, 1);
                int l = st.get_first(1, 1, n, id);
                int r = st.get_last(1, 1, n, id);
                if (r == 0) {
                    r = n + 1;
                }
                ++l;
                --r;
                //cout << "#" << l << " " << r << endl;
                auto it = bad.lower_bound({l, -inf});
                //cout << "$" << it->first << " " << it->second <<  endl;
                if (it->second <= r) {
                    cout << "YES\n";
                } else {
                    cout << "N/A\n";
                }
                st.update(1, 1, n, id, id, 0);
            }
        }
        if (0) {
            for (auto [l, r] : bad) {
                cout << l << " " << r << "    ";
            }
            cout << endl;
        }
    }
    return 0;
}