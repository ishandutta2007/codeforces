/**
 *  created: 24/05/2021, 12:57:14
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

struct state {
    pair<int, string> a[2];
};

state merge(const state &a, const state &b) {
    state res;
    for (int i = 0; i < 2; ++i) {
        res.a[i] = b.a[a.a[i].first];
        if (res.a[i].second == "") {
            res.a[i].second = a.a[i].second;
        }
    }
    return res;
}

string tp[max_n];

struct segment_tree {
    state a[4 * max_n];

    void update_leaf(int v, int l, int r) {
        if (tp[l] == "lock") {
            a[v].a[0] = {0, ""};
            a[v].a[1] = {0, ""};
        } else if (tp[l] == "unlock") {
            a[v].a[0] = {1, ""};
            a[v].a[1] = {1, ""};
        } else {
            a[v].a[0] = {0, ""};
            a[v].a[1] = {1, tp[l]};
        }
    }

    void build(int v, int l, int r) {
        if (l == r) {
            update_leaf(v, l, r);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }

    void update(int v, int l, int r, int x) {
        if (l == r) {
            update_leaf(v, l, r);
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x);
        } else {
            update(2 * v + 1, mid + 1, r, x);
        }
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }
};

int n, q;
segment_tree st;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tp[i];
    }
    st.build(1, 0, n - 1);
    cin >> q;
    for (int i = 0; i <= q; ++i) {
        string ans = st.a[1].a[1].second;
        if (ans == "") {
            ans = "blue";
        }
        cout << ans << "\n";
        if (i < q) {
            int id;
            cin >> id;
            --id;
            cin >> tp[id];
            st.update(1, 0, n - 1, id);
        }
    }

    return 0;
}