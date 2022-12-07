#include <bits/stdc++.h>
using namespace std;

class SegTree {
    int n;
    vector<vector<int>> cnt, flip;
    vector <int> sz;

public:
    SegTree(int _n) : n(_n) {
        cnt.resize(n<<2, vector<int>(20, 0));
        flip.resize(n<<2, vector<int>(20, 0));
        sz.resize(n<<2);
    }

    void push(int node) {
        for(int j = 0; j < 2; j++) {
            for(int i = 0; i < 20; i++) {
                if(flip[node][i] == 1) {
                    cnt[(node * 2)|j][i] = sz[(node * 2)|j] - cnt[(node * 2)|j][i];
                }
                flip[(node * 2)|j][i] ^= flip[node][i];
            }
        }
        for(int i = 0; i < 20; i++) {
            flip[node][i] = 0;
        }
    }

    void build(int node, int start, int end, vector<int> &v) {
        if(start == end) {
            for(int i = 0; i < 20; i++) {
                cnt[node][i] = v[start]>>i & 1;
            }
            sz[node] = 1;
        } else {
            int mid = (start + end)>>1;
            build((node * 2), start, mid, v);
            build((node * 2)|1, mid+1, end, v);
            for(int i = 0; i < 20; i++) {
                cnt[node][i] = cnt[(node * 2)][i] + cnt[(node * 2)|1][i];
            }
            sz[node] = sz[(node * 2)] + sz[(node * 2)|1];
        }
    }

    void XOR(int node, int start, int end, int l, int r, int x) {
        if(start == end) {
            for(int i = 0; i < 20; i++) {
                cnt[node][i] ^= x>>i & 1;
            }
        } else if(l == start && r == end) {
            for(int i = 0; i < 20; i++) {
                if(x >> i & 1) {
                    cnt[node][i] = sz[node] - cnt[node][i];
                    flip[node][i] ^= 1;
                }
            }
        } else {
            push(node);
            int mid = (start + end)>>1;
            if(l <= mid) XOR((node * 2), start, mid, l, min(mid, r), x);
            if(r > mid) XOR((node * 2)|1, mid+1, end, max(mid + 1, l), r, x);
            for(int i = 0; i < 20; i++) {
                cnt[node][i] = cnt[(node * 2)][i] + cnt[(node * 2)|1][i];
            }
        }
    }

    long long sum(int node, int start, int end, int l, int r) {
        if(start == end || (l == start && r == end)) {
            long long ans = 0;
            for(int i = 0; i < 20; i++) {
                ans += (long long)cnt[node][i]<<i;
            }
            return ans;
        }
        push(node);
        int mid = (start + end)>>1;
        long long ans1 = 0;
        long long ans2 = 0;
        if(l <= mid) ans1 = sum((node * 2), start, mid, l, min(mid, r));
        if(r > mid) ans2 = sum((node * 2)|1, mid + 1, end, max(mid + 1, l), r);
        return ans1 + ans2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    SegTree st(n);
    st.build(1, 0, n - 1, v);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            cout << st.sum(1, 0, n - 1, l, r) << '\n';
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            --l; --r;
            st.XOR(1, 0, n - 1, l, r, x);
        }
    }
    
    return 0;
}