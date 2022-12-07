#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = (int)1E9 + 7;

template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size);
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
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> pos(n);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pos[x] = i;
        }
        int left = pos[0];
        int right = pos[0];
        int ans = 1;
        SegTree<int> st(4*n);
        st.update(1, 0, n - 1, pos[0], 1);
        for(int i = 1; i < n; i++) {
            if(pos[i] >= left && pos[i] <= right) {
                ans = ans * (right - left + 1 - st.query(1, 0, n - 1, left, right)) % MOD;
            }
            st.update(1, 0, n - 1, pos[i], 1);
            left = min(left, pos[i]);
            right = max(right, pos[i]);
        }
        cout << ans << '\n';
    }
    
    return 0;
}