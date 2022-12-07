#include <bits/stdc++.h>
using namespace std;
#define int long long

struct dat {
    int sum, pref, suff, ans;
};

template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size);
    }

    T func(T l, T r) {
        dat res;
        res.sum = l.sum + r.sum;
        res.pref = max(l.pref, l.sum + r.pref);
        res.suff = max(r.suff, r.sum + l.suff);
        res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
        return res;
    }

    T make_dat(int val) {
        dat res;
        res.sum = val;
        res.pref = res.suff = res.ans = max(0ll, val);
        return res;
    }

    // T func(T a, T b) {
    //     return a + b; // Segment tree for the sum
    //     // return min(a, b); // Segment tree for the minimum
    // }

    void build(int node, int start, int end, vector <int> &v) {
        if(start == end) {
            // tree[node] = v[start];
            tree[node] = make_dat(v[start]);
        } else {
            int mid = (start + end)/2;
            build(2*node, start, mid, v);
            build(2*node + 1, mid + 1, end, v);
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    void update(int node, int start, int end, int pos, int val) {
        if(start == end) {
            tree[node] = make_dat(val); // Assign value here.
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
            return make_dat(0); // Return appropriate value, for example INF for minimum.
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
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<pair<int, int>> order(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            order[i] = {v[i], i};
        }
        sort(order.begin(), order.end(), greater<pair<int, int>>());
        SegTree<dat> st(4*n);
        st.build(1, 0, n - 1, v);
        set <int> s;
        s.insert(-1);
        s.insert(n);
        bool pos = true;
        for(int i = 0; i < n; i++) {
            int curr = order[i].second;
            int prev = *(--s.upper_bound(curr));
            int nx = *(s.upper_bound(curr));
            int a = st.query(1, 0, n - 1, prev + 1, curr - 1).suff;
            int b = st.query(1, 0, n - 1, curr + 1, nx - 1).pref;
            if(a > 0 || b > 0) {
                pos = false;
                break;
            }
            s.insert(curr);
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}