#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size, 0);
    }

    T func(T a, T b) {
        return a + b; // Segment tree for the sum
        // return min(a, b); // Segment tree for the minimum
    }

    void build(int node, int start, int end, vector <T> &v) {
        if(start == end) {
            tree[node] = v[start];
        } else {
            int mid = (start + end)/2;
            build(2*node, start, mid, v);
            build(2*node + 1, mid + 1, end, v);
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    void update(int node, int start, int end, int pos, T val) {
        if(start == end) {
            tree[node] = val; // Assign value here.
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update(node*2, start, mid, pos, val);
            } else {
                update(node*2 + 1, mid + 1, end, pos, val);
            }
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    T query(int node, int start, int end, int l, int r) {
        if(l > r) {
            return 0; // Return appropriate value, for example INF for minimum.
        }
        if(l == start && r == end) {
            return tree[node];
        }
        int mid = (start + end)/2;
        return func(query(node*2, start, mid, l, min(mid, r)), query(node*2 + 1, mid + 1, end, max(l, mid + 1), r));
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<SegTree<int>> st(m, 4*n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char x; cin >> x;
            if(x == '*') st[j].update(1, 0, n - 1, i, 1);
        }
    }
    for(int T = 0; T < q; T++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        int curr = st[b].query(1, 0, n - 1, a, a);
        curr = (curr == 0 ? 1 : 0);
        st[b].update(1, 0, n - 1, a, curr);
        int cnt = 0;
        for(int i = 0; i < m; i++) cnt += st[i].query(1, 0, n - 1, 0, n - 1);
        int full = cnt/n;
        int ok = 0;
        for(int i = 0; i < full; i++) ok += st[i].query(1, 0, n - 1, 0, n - 1);
        ok += st[full].query(1, 0, n - 1, 0, cnt - n*full - 1);
        cout << cnt - ok << '\n';
    }
    
    return 0;
}