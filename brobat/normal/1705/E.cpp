#include <bits/stdc++.h>
using namespace std;

const int N = 200100;

template <typename T>
class SegTree {
public:
    vector <T> tree;
    vector <T> lazy;
    vector <int> sz;
 
    SegTree(int size) {
        tree.resize(size, 0);
        lazy.resize(size, 0);
        sz.resize(size, 0);
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
        tree[node*2] += (lazy[node] * sz[node*2]);
        tree[node * 2 + 1] += (lazy[node] * sz[node*2 + 1]);
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
        lazy[node] = 0;
    }
 
    void update_range(int node, int start, int end, int l, int r, T val) {
        // Add val to [l, r].
        if(start == end) {
            tree[node] += val;
            lazy[node] = 0;
            return;
        }
        if(l == start && r == end) {
            tree[node] += val * (end - start + 1);
            lazy[node] += val;
        } else {
            push(node);
            int mid = (start + end)/2;
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), val);
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
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

    T find_kth_zero(int node, int start, int end, int k) {
        if(start == end) {
            return start;
        }
        push(node);
        int mid = (start + end)/2;
        if((sz[node * 2] - tree[node * 2]) >= k) {
            return find_kth_zero(node * 2, start, mid, k);
        } else {
            return find_kth_zero(node * 2 + 1, mid + 1, end, k - sz[node * 2] + tree[node * 2]);
        }
    }

    T find_kth_one(int node, int start, int end, int k) {
        if(start == end) {
            return start;
        }
        push(node);
        int mid = (start + end)/2;
        if(tree[node * 2] >= k) {
            return find_kth_one(node * 2, start, mid, k);
        } else {
            return find_kth_one(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    SegTree <int> st(4*N);
    st.build(1, 0, N - 1);
    vector <int> v(n);
    multiset <int> ms;
    
    auto find_first_zero = [&](int x) -> int {

        // for(int i = 0; i < 8; i++) {
        //     cerr << st.query(1, 0, N - 1, i, i) << " ";
        // }
        // cerr << '\n';

        int prev_zeroes = x + 1 - st.query(1, 0, N - 1, 0, x);
        // cerr << x << " " << prev_zeroes << " " << st.find_kth_zero(1, 0, N - 1, prev_zeroes + 1) << '\n';
        return st.find_kth_zero(1, 0, N - 1, prev_zeroes + 1);

        // find the first value greater than x, which is 0. This means the rest will be 1.
        // use binary search.
        // int left = x + 1;
        // int right = N - 1;
        // int ans = -1;
        // while(left <= right) {
        //     int mid = (left + right)/2;
        //     // cerr << mid << " ";
        //     if(st.query(1, 0, N - 1, left, mid) != mid - left + 1) {
        //         ans = mid;
        //         right = mid - 1;
        //     } else {
        //         left = mid + 1;
        //     }
        // }
        // // cerr << '\n';
        // return ans;
    };

    auto find_first_one = [&](int x) -> int {

        int prev_ones = st.query(1, 0, N - 1, 0, x);
        
        return st.find_kth_one(1, 0, N - 1, prev_ones + 1);

        // find the first value greater than x, which is 1. 
        // int left = x + 1;
        // int right = N - 1;
        // int ans = -1;
        // while(left <= right) {
        //     int mid = (left + right)/2;
        //     // cerr << mid << " ";
        //     if(st.query(1, 0, N - 1, left, mid) != 0) {
        //         ans = mid;
        //         right = mid - 1;
        //     } else {
        //         left = mid + 1;
        //     }
        // }
        // // cerr << '\n';
        // return ans;
    };

    auto compute_max = [&]() -> int {

        int cnt = st.query(1, 0, N - 1, 0, N - 1);
        return st.find_kth_one(1, 0, N - 1, cnt);

        // int left = (*--ms.end());
        // int right = N - 1;
        // int ans = -1;
        // while(left <= right) {
        //     int mid = (left + right)/2;
        //     if(st.query(1, 0, N - 1, mid, right) != 0) {
        //         ans = mid;
        //         left = mid + 1;
        //     } else {
        //         right = mid - 1;
        //     }
        // }
        // return ans;
    };

    auto add_occ = [&](int y) -> void {
        ms.insert(y);
        int curr = st.query(1, 0, N - 1, y, y);
        if(curr == 0) {
            st.update_range(1, 0, N - 1, y, y, 1);
        } else {
            auto x = find_first_zero(y);
            // cerr << '\n' << x << " " << y << '\n';
            st.update_range(1, 0, N - 1, y, x - 1, -1);
            st.update_range(1, 0, N - 1, x, x, 1);
        }
    };

    auto remove_occ = [&](int y) -> void {
        ms.erase(y);
        int curr = st.query(1, 0, N - 1, y, y);
        if(curr == 1) {
            st.update_range(1, 0, N - 1, y, y, -1);
        } else {
            auto x = find_first_one(y);
            // cerr << '\n' << x << " " << y << '\n';
            st.update_range(1, 0, N - 1, y, x - 1, 1);
            st.update_range(1, 0, N - 1, x, x, -1);
        }
    };
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        add_occ(v[i]);
    }

    for(int i = 0; i < q; i++) {
        int ind, val;
        cin >> ind >> val;
        --ind;
        remove_occ(v[ind]);
        // cerr << "After removing occ of " << v[ind] << '\n';
        // for(int i = 1; i < 8; i++) {
        //     cerr << st.query(1, 0, N - 1, i, i) << " ";
        // }
        // cerr << '\n';
        v[ind] = val;
        add_occ(v[ind]);
        // cerr << "After adding occ of " << v[ind] << '\n';
        // for(int i = 1; i < 8; i++) {
        //     cerr << st.query(1, 0, N - 1, i, i) << " ";
        // }
        // cerr << '\n';
        cout << compute_max() << '\n';
    }
    
    return 0;
}