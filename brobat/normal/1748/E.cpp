#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = (int)1E9 + 7;

template <typename T>
struct SegTree {
    int n;
    vector<T> t;
    T ID = {0, -1}; // identity here

    T comb(T a, T b) {
        if(a.first > b.first) return a;
        if(a.first < b.first) return b;
        if(a.second < b.second) return a;
        return b;
    }

    SegTree(int _n) : n(_n) {
        t.resize(4*n, ID);
    } 

    void pull(int node) {
        t[node] = comb(t[node*2], t[node*2 + 1]);
}

    void build(int node, int tl, int tr, vector<int>& v) {
        if(tl == tr) {
            t[node] = {v[tl], tl}; // assign here
        } else {
            int tm = (tl + tr)/2;
            build(node*2, tl, tm, v);
            build(node*2+1, tm+1, tr, v);
            pull(node);
        }
    }

    T query(int node, int tl, int tr, int l, int r) {
        if(l > r) return ID;
        if(l == tl && r == tr) return t[node];
        int tm = (tl + tr)/2;
        return comb(query(node*2, tl, tm, l, min(tm, r)), query(node*2 + 1, tm+1, tr, max(l, tm + 1), r));
    }
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int node, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            t[node] = val; // update here
        } else {
            int tm = (tl + tr)/2;
            if(pos <= tm) update(node*2, tl, tm, pos, val);
            else update(node*2 + 1, tm+1, tr, pos, val);
            pull(node);
        }
    }
    void update(int pos, int val) { update(1, 0, n - 1, pos, val); }
};

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        SegTree<pair<int, int>> st(n);
        st.build(1, 0, n - 1, v);
        vector<pair<int, int>> r;
        auto REC = y_combinator([&](auto self, int i, int j) -> void {
            // number of ways to populate the subarray [i...j] assuming max value allowed <= k.
            if(i > j) return;
            r.push_back({i, j});
            auto p = st.query(i, j);
            self(i, p.second - 1);
            self(p.second + 1, j);
        });
        REC(0, n - 1);
        sort(r.begin(), r.end(), [&](pair<int, int> a, pair<int, int> b) {
            return (a.second - a.first) < (b.second - b.first);
        });
        vector<vector<int>> ans(r.size(), vector<int>(m + 1, 0));
        map<pair<int, int>, int> mem;
        for(int i = 0; i < (int)r.size(); i++) {
            mem[r[i]] = i;
        }
        int it = -1;
        for(auto [i, j] : r) {
            it++;
            if(i == j) {
                for(int k = 0; k <= m; k++) {
                    ans[it][k] = k;
                }
                continue;
            }
            auto p = st.query(i, j);
            if(p.second == i) {
                int p2 = mem[{p.second + 1, j}];
                for(int k = 1; k <= m; k++) {
                    ans[it][k] = ans[p2][k] + ans[it][k - 1];
                    ans[it][k] %= MOD;
                }
            } else if(p.second == j) {
                int p1 = mem[{i, p.second - 1}];
                for(int k = 1; k <= m; k++) {
                    ans[it][k] = ans[p1][k - 1] + ans[it][k - 1];
                    ans[it][k] %= MOD;
                }
            } else {
                int p1 = mem[{i, p.second - 1}];
                int p2 = mem[{p.second + 1, j}];
                for(int k = 1; k <= m; k++) {
                    ans[it][k] = (ans[p1][k - 1] * ans[p2][k]) % MOD;
                    ans[it][k] += ans[it][k - 1];
                    ans[it][k] %= MOD;
                }
            }
        }
        cout << ans.back()[m] << '\n';
        // int z = 0;
        // for(auto j : ans.back()) {
        //     z = (z + j) % MOD;
        // }
        // cout << z << '\n';
    }
    
    return 0;
}