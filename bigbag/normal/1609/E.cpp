/**
 *  created: 28/11/2021, 17:05:05
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

struct Node {
    Node() {
        memset(cnt, 0, sizeof(cnt));
    }

    Node(char c) {
        memset(cnt, 0, sizeof(cnt));
        ans = 0;
        suf = 0;
        pref = 0;
        ++cnt[c - 'a'];
    }

    int ans, cnt[3], suf, pref;
};

Node merge(const Node &a, const Node &b) {
    Node res;
    for (int i = 0; i < 3; ++i) {
        res.cnt[i] = a.cnt[i] + b.cnt[i];
    }
    res.ans = min({a.ans + b.cnt[2], b.ans + a.cnt[0], a.suf + b.pref});
    res.suf = min(b.suf + a.cnt[0], a.suf + b.cnt[1]);
    res.pref = min(a.pref + b.cnt[2], b.pref + a.cnt[1]);
    return res;
}

struct segment_tree {
    Node a[4 * max_n];

    void build(int v, int l, int r, const string &s) {
        if (l == r) {
            a[v] = Node(s[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, s);
        build(2 * v + 1, mid + 1, r, s);
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, char c) {
        if (l == r) {
            a[v] = Node(c);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, c);
        } else {
            update(2 * v + 1, mid + 1, r, pos, c);
        }
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }
};

int n, q;
string s;
segment_tree st;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q >> s;
    st.build(1, 0, n - 1, s);
    while (q--) {
        int pos;
        char c;
        cin >> pos >> c;
        --pos;
        st.update(1, 0, n - 1, pos, c);
        cout << st.a[1].ans << "\n";
    }
    return 0;
}