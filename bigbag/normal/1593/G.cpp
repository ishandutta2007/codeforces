/**
 *  created: 13/10/2021, 18:32:38
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

struct node {
    int first, len;

    node() {
    }

    node(int first, int len): first(first), len(len) {
    }

    int get_last() const {
        return first ^ (len % 2) ^ 1;
    }

    int ones() const {
        int res = len / 2;
        if (first && len % 2) {
            ++res;
        }
        return res;
    }
};

node merge(const node &a, const node &b) {
    if (!a.len) {
        return b;
    }
    if (!b.len) {
        return a;
    }
    if (a.get_last() != b.first) {
        return {a.first, a.len + b.len};
    }
    if (a.len >= b.len) {
        return {a.first, a.len - b.len};
    }
    return {b.get_last() ^ 1 ^ ((b.len - a.len) % 2), b.len - a.len};
}

struct segment_tree {
    node a[4 * max_n];

    void build(int v, int l, int r, int tp[]) {
        if (l == r) {
            a[v] = {tp[l], 1};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, tp);
        build(2 * v + 1, mid + 1, r, tp);
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }

    node get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return merge(get_sum(2 * v, tl, mid, l, mid), get_sum(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int t, n, q, tp[max_n];
string s;
segment_tree st;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> s >> q;
        n = s.size();
        for (int i = 0; i < n; ++i) {
            tp[i] = 0;
            if (s[i] == '[' || s[i] == ']') {
                tp[i] = 1;
            }
        }
        st.build(1, 0, n - 1, tp);
        while (q--) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            auto ans = st.get_sum(1, 0, n - 1, l, r);
            cout << ans.ones() << "\n";
        }
    }
    return 0;
}