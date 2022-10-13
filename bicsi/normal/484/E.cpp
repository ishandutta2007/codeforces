#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct SegmTree {
    struct Node {
        int pref, suff, dp;
        bool full;
    };

    int n;
    vector<Node> T;
    SegmTree(int n) : n(n), T(4 * n, Node{0, 0, 0, 0}) {}

    Node combine(Node a, Node b) {
        Node ret;
        ret.dp = max(a.dp, b.dp);
        ret.dp = max(ret.dp, a.suff + b.pref);
        ret.pref = (a.full ? a.pref + b.pref : a.pref);
        ret.suff = (b.full ? b.suff + a.suff : b.suff);
        ret.full = (a.full & b.full);
        return ret;
    }
    
    void insert(int node, int b, int e, int pos) {
        if (b == e) {
            assert(b == pos);
            T[node] = Node{1, 1, 1, 1};
        } else {
            int m = (b + e) / 2;
            if (pos <= m) insert(node * 2, b, m, pos);
            else insert(node * 2 + 1, m + 1, e, pos);
            T[node] = combine(T[node * 2], T[node * 2 + 1]);
        }
    }
    void Insert(int pos) {
        insert(1, 0, n - 1, pos);
    }

    Node query(int node, int b, int e, int l, int r) {
        if (l > r) return Node{0, 0, 0, 0};
        if (b == l && e == r) return T[node];
        int m = (b + e) / 2;
        return combine(
            query(node * 2, b, m, l, min(m, r)),
            query(node * 2 + 1, m + 1, e, max(m + 1, l), r)
        );
    }
    int Query(int l, int r) {
        return query(1, 0, n - 1, l, r).dp;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;

    vector<pair<int, int>> V(n);
    for (int i = 0; i < n; ++i) {
        cin >> V[i].first;
        V[i].second = i;
    }

    sort(V.rbegin(), V.rend());
    
    int q; cin >> q;
    vector<tuple<int, int, int>> queries;
    vector<int> ans(q, -1);
    vector<int> order(q);

    for (int i = 0; i < q; ++i) {
        int l, r, w; cin >> l >> r >> w; --l; --r;
        queries.emplace_back(l, r, w);  
    }

    for (int step = (1 << 20); step; step /= 2) {
        vector<pair<int, int>> order;
        for (int i = 0; i < q; ++i) {
            if (ans[i] + step < n) {
                order.emplace_back(ans[i] + step, i);
            }
        }
        sort(order.begin(), order.end());

        SegmTree st(n);
        int at = 0;
        for (auto x : order) {
            while (at < n && at <= x.first) {
                st.Insert(V[at++].second);
            }
            int l, r, w;
            tie(l, r, w) = queries[x.second];
            
            int have = st.Query(l, r);
            if (have < w)
                ans[x.second] += step;
        }
    }

    for (auto x : ans) {
        cout << V[x + 1].first << '\n';
    }


    return 0;
}