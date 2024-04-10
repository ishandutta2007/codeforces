#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
class SegTree {
public:
    vector <T> tree;
    vector <T> lazy;
    vector <int> sz;
    vector <int> mx;
 
    SegTree(int size) {
        tree.resize(size, 0);
        lazy.resize(size, 0);
        sz.resize(size);
        mx.resize(size, 0);
    }
 
    void build(int node, int start, int end) {
        if(start == end) {
            sz[node] = 1;
        } else {
            int mid = (start + end)/2;
            build(node*2, start, mid);
            build(node*2 + 1, mid + 1, end);
            sz[node] = end - start + 1;
        }
    }
 
    void push(int node) {
        for(int it = 0; it < 2; it++) {
            tree[node<<1|it] += (lazy[node] * sz[node<<1|it]);
            lazy[node<<1|it] += lazy[node];
            mx[node<<1|it] += lazy[node];
        }
        lazy[node] = 0;
    }
 
    void update_range(int node, int start, int end, int l, int r, T val) {
        // Add val to [l, r].
        if(start == end) {
            tree[node] += val;
            lazy[node] = 0;
            mx[node] += val;
            return;
        }
        if(l == start && r == end) {
            tree[node] += val * (end - start + 1);
            lazy[node] += val;
            mx[node] += val;
        } else {
            push(node);
            int mid = (start + end)/2;
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), val);
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
            mx[node] = max(mx[node<<1], mx[node<<1|1]);
        }
    }
 
    T query(int node, int start, int end, int l, int r) {
        if(start == end) {
            return tree[node];
        }
        if(l == start && r == end) {
            return tree[node];
        }
        push(node);
        int mid = (start + end)/2;
        int a = 0, b = 0;
        if(l <= mid) a = query(node * 2, start, mid, l, min(r, mid));
        if(r > mid) b = query(node * 2 + 1, mid + 1, end, max(l, mid + 1), r);
        return a + b;
    }

    int find_last_x(int node, int start, int end, int x) {
        // find the last index such that mx[node] is >= x.
        // updates will later be done on all values after this.
        if(start == end) {
            if(mx[node] < x) return -1;
            return start;
        }
        push(node);
        int mid = (start + end)/2;
        if(mx[node*2 + 1] >= x) return find_last_x(node * 2 + 1, mid + 1, end, x);
        return find_last_x(node * 2, start, mid, x);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        v[i] = c - '0';
    }
    SegTree <int> st(4*n);
    st.build(1, 0, n - 1);
    int ans = 0;
    int curr = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] == 0) {
            curr = 0;
        } else {
            curr++;
            int x = st.find_last_x(1, 0, n - 1, curr);
            st.update_range(1, 0, n - 1, x + 1, i, 1);
        }
        ans += st.query(1, 0, n - 1, 0, i);
    }
    cout << ans;
    
    return 0;
}