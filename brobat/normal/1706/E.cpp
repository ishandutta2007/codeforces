#include <bits/stdc++.h>
using namespace std;
// #define int long long

class DSU {
public:
    int n;
    vector <int> p, sz;
    vector<set<pair<int, int>>> s;
    vector<vector<int>> r; // ranges formed {l, r, k}

    DSU(int _n) {
        n = _n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.resize(n, 1);
        s.resize(n);
        for(int i = 0; i < n; i++) {
            s[i].insert({-5, -5});
            s[i].insert({i, i});
            s[i].insert({n + 5, n + 5});
        }
    }

    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    void unite(int a, int b, int k) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(sz[c] < sz[d]) swap(c, d);
            p[d] = c;
            sz[c] += sz[d];
            merge(s[c], s[d], k);
        }
    }

    void merge(set <pair<int, int>> &a, set <pair<int, int>> &b, int k) {
        for(auto it : b) {
            // 4 cases.
            // don't merge, just insert
            // merge with former
            // merge with latter
            // merge with both former and latter
            int x = it.first;
            int y = it.second;
            if(x == -5 || x == n + 5) continue;
            auto nx = a.upper_bound(it);
            auto prev = nx;
            prev--;
            bool first = (*prev).second + 1 == x;
            bool sec = (*nx).first == y + 1;
            if(first) {
                if(sec) {
                    int f = (*prev).first;
                    int s = (*nx).second;
                    a.erase(prev);
                    a.erase(nx);
                    r.push_back({f, s, k});
                    a.insert({f, s});
                } else {
                    int f = (*prev).first;
                    a.erase(prev);
                    r.push_back({f, y, k});
                    a.insert({f, y});
                }
            } else {
                if(sec) {
                    int s = (*nx).second;
                    a.erase(nx);
                    r.push_back({x, s, k});
                    a.insert({x, s});
                } else {
                    a.insert({x, y});
                }
            }
            // b.erase(it);
        }
        b.clear();
    }
};

const int INF = (int)1E9;

template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size, INF);
    }

    T func(T a, T b) {
        // return a + b; // Segment tree for the sum
        return min(a, b); // Segment tree for the minimum
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
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    T query(int node, int start, int end, int l, int r) {
        if(l > r) {
            return INF; // Return appropriate value, for example INF for minimum.
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
        int n, m, q;
        cin >> n >> m >> q;
        vector<vector<int>> range;
        {
            DSU d(n);
            for(int i = 0; i < m; i++) {
                int a, b;
                cin >> a >> b;
                --a; --b;
                d.unite(a, b, i);
            }
            range = d.r;
        }
        sort(range.begin(), range.end(), [&](vector<int> a, vector<int> b) {
            return a[0] > b[0];
        });
        vector<vector<int>> query;
        for(int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            query.push_back({a, b, i});
        }
        sort(query.begin(), query.end(), [&](vector <int> a, vector <int> b) {
            return a[0] > b[0];
        });
        vector <int> ans(q);
        SegTree <int> st(4*n);
        while(!query.empty()) {
            int l = query.back()[0];
            int r = query.back()[1];
            int k = query.back()[2];
            // auto [l, r, k] = query.front();
            query.pop_back();
            if(l == r) {
                ans[k] = -1;
                continue;
            }
            while(!range.empty() && range.back()[0] <= l) {
                st.update(1, 0, n - 1, range.back()[1], range.back()[2]);
                range.pop_back();
            }
            ans[k] = st.query(1, 0, n - 1, r, n - 1);
        }
        for(auto i : ans) cout << i + 1 << " ";
        cout << '\n';
    }
    
    return 0;
}