#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = (int)1E18;



template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size);
        for(int i = 0; i < size; i++) {
            tree[i] = -INF;
        }
    }

    T func(T a, T b) {
        return max(a, b); // Segment tree for the sum
        // return min(a, b); // Segment tree for the minimum
    }

    void update(int node, int start, int end, int pos, T val) {
        if(start == end) {
            tree[node] = max(tree[node], val); // Assign value here.
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
            return -INF; // Return appropriate value, for example INF for minimum.
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
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector <int> p(n);
        p[0] = v[0];
        for(int i = 1; i < n; i++) {
            p[i] = p[i - 1] + v[i];
        }
        sort(p.begin(), p.end());
        unordered_map<int, int> h; // map prefix sums to smaller values
        int temp = 1;
        h[p[0]] = 0;
        for(int i = 1; i < n; i++) {
            if(p[i] != p[i - 1]) {
                h[p[i]] = temp++;
            }
        }
        p[0] = v[0];
        for(int i = 1; i < n; i++) {
            p[i] = p[i - 1] + v[i];
        }
        // for(int i = 0; i < n; i++) {
        //     cout << i << " " << p[i] << " " << h[p[i]] << "\n";
        // }
        vector<int> eq(n, -INF); // answer for equal pref sum values
        vector<int> dp(n, -INF); 
        dp[0] = (v[0] > 0 ? 1 : (v[0] == 0 ? 0 : -1));
        eq[h[v[0]]] = dp[0];
        SegTree<int> st(4*temp);
        st.update(1, 0, temp - 1, h[v[0]], dp[0] - 1);
        for(int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] - 1, eq[h[p[i]]]);
            dp[i] = max(dp[i], st.query(1, 0, temp - 1, 0, h[p[i]] - 1) + i + 1);
            if(p[i] > 0) dp[i] = max(dp[i], i + 1);
            if(p[i] == 0) dp[i] = max(dp[i], 0ll);
            eq[h[p[i]]] = max(eq[h[p[i]]], dp[i]);
            st.update(1, 0, temp - 1, h[p[i]], dp[i] - i - 1);
        }
        cout << dp[n - 1] << '\n';
        // for(int i = 0; i < n; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << "\n\n";
    }
    
    return 0;
}