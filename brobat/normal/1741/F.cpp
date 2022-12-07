#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define int long long

class SegTree {
public:
    // vector <multiset<int>> tree;
    vector <int> tree;
    vector<multiset<int>> z;
    int ID = -2E9;

    SegTree(int size) {
        z.resize(size, multiset<int>{ID});
        tree.resize(4*size, ID);
    }

    int func(int a, int b) {
        return max(a, b);
    }

    void update(int node, int start, int end, int pos, int val, bool add) {
        if(start == end) {
            if(add) z[start].insert(val);
            else z[start].erase(z[start].find(val));
            tree[node] = *(--z[start].end());
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update(node*2, start, mid, pos, val, add);
            } else {
                update(node*2 + 1, mid + 1, end, pos, val, add);
            }
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
            // tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if(l > r) {
            return ID;
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
        vector<vector<vector<int>>> v(n);
        // map<int, int> hash;
        unordered_map<long long, int, custom_hash> hash;
        vector <int> vals;
        set <int> temp;
        for(int i = 0; i < n; i++) {
            int l, r, c;
            cin >> l >> r >> c;
            --c;
            temp.insert(l);
            temp.insert(r);
            v[c].push_back({l, r, i});
        }
        for(auto i : temp) vals.push_back(i);
        for(int i = 0; i < (int)vals.size(); i++) {
            hash[vals[i]] = i;
        }
        int m = vals.size();
        SegTree st(m);
        multiset <int> left;
        left.insert(2E9);
        for(int i = 0; i < n; i++) {
            if(i > 0) for(auto j : v[i]) {
                st.update(1, 0, m - 1, hash[j[0]], j[1], true);
                left.insert(j[0]);
            }
        }
        vector <int> ans(n, 2E9);
        for(int i = 0; i < n; i++) {
            if(i > 0) for(auto j : v[i]) {
                st.update(1, 0, m - 1, hash[j[0]], j[1], false);
                left.erase(left.find(j[0]));
            }
            for(auto j : v[i]) {
                int x = st.query(1, 0, m - 1, 0, hash[j[1]]);
                ans[j[2]] = max(0ll, j[0] - x);
                ans[j[2]] = min((*left.lower_bound(j[1])) - j[1], ans[j[2]]);
            }
            if(i < n - 1) for(auto j : v[i]) {
                st.update(1, 0, m - 1, hash[j[0]], j[1], true);
                left.insert(j[0]);
            }
        }
        for(auto i : ans) cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}