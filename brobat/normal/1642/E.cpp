#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size, 1000000000000000);
    }

    void update(int node, int start, int end, int pos, T val) {
        if(start == end) {
            tree[node] = min(tree[node], val); // Assign value here.
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update(node*2, start, mid, pos, val);
            } else {
                update(node*2 + 1, mid + 1, end, pos, val);
            }
            tree[node] = min(tree[node*2], tree[node*2 + 1]);
        }
    }

    T query(int node, int start, int end, int l, int r) {
        if(l > r) {
            return 1000000000000000; // Return appropriate value, for example INF for minimum.
        }
        if(l == start && r == end) {
            return tree[node];
        }
        int mid = (start + end)/2;
        return min(query(node*2, start, mid, l, min(mid, r)), query(node*2 + 1, mid + 1, end, max(l, mid + 1), r));
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    SegTree<int> st(4*(n + 2));
    set <int> s;
    for(int i = 0; i <= n + 1; i++) {
        s.insert(i);
    }
    for(int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if(a == 0) {
            int b, c, d;
            cin >> b >> c >> d;
            if(d == 0) {
                auto x = s.lower_bound(b);
                vector <int> e;
                while((*x) <= c) {
                    e.push_back(*x);
                    ++x;
                }
                for(auto i : e) {
                    s.erase(i);
                }
            } else {
                st.update(1, 0, n + 1, b, c);
            }
        } else {
            int x;
            cin >> x;
            if((*s.lower_bound(x)) != x) {
                cout << "NO" << endl;
            } else {
                int yr = *s.upper_bound(x);
                int yl = *(--s.lower_bound(x));
                if(st.query(1, 0, n + 1, yl + 1, yr - 1) < yr) {
                    cout << "YES" << endl;
                } else {
                    cout << "N/A" << endl;
                }
            }
        }
    }

    return 0;
}