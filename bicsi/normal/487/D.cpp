#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    using Node = vector<pair<int, int>>;
    
    int n, m;
    vector<Node> T;
    vector<string> mat;

    SegmentTree(vector<string> mat) : 
        n(mat.size()), 
        m(mat[0].size()),
        T(4 * n), 
        mat(mat) { build(1, 1, n); }

    Node combine(Node hi, Node lo) {
        assert((int)lo.size() == m);
        assert((int)hi.size() == m);
        
        Node ret(m);
        for (int i = 0; i < m; ++i) {
            if (hi[i].first != 0) { 
                ret[i] = hi[i];
                continue;
            }
            ret[i] = lo[hi[i].second - 1];
        }
        return ret;
    }

    Node single(string str, int row) {
        assert((int)str.size() == m);

        Node ret(m, {-1, -1});
        for (int i = 0; i < m; ++i) {
            if (str[i] == '^') {
                ret[i] = {0, i + 1};
            }
        }

        if (str[0] == '<') ret[0] = {row, 0};
        for (int i = 1; i < m; ++i) {
            if (str[i] == '<') { 
                ret[i] = ret[i - 1]; 
            }
        }
        
        if (str[m - 1] == '>') ret[m - 1] = {row, m + 1};
        for (int i = m - 2; i >= 0; --i) {
            if (str[i] == '>') {
                ret[i] = ret[i + 1];
            }    
        }
        return ret;
    }
    
    void build(int node, int b, int e) {
        if (b == e) {
            T[node] = single(mat[b - 1], b);
        } else {
            int m = (b + e) / 2;
            build(node * 2, b, m);
            build(node * 2 + 1, m + 1, e);
            T[node] = combine(T[node * 2 + 1], T[node * 2]);   
        }
    }
    
    void update(int node, int b, int e, int pos) {
        if (b == e) {
            assert(b == pos);
            T[node] = single(mat[pos - 1], pos);
        } else {
            int m = (b + e) / 2;
            if (pos <= m) update(node * 2, b, m, pos);
            else update(node * 2 + 1, m + 1, e, pos);
            T[node] = combine(T[node * 2 + 1], T[node * 2]);
        }
    }
    void Update(int i, int j, char c) { 
        mat[i - 1][j - 1] = c; 
        update(1, 1, n, i);
    } 

    Node query(int node, int b, int e, int l) {
        if (b == e) {
            assert(b == l);
            return T[node];
        } else {
            int m = (b + e) / 2;
            if (l > m) {
                return combine(query(node * 2 + 1, m + 1, e, l), T[node * 2]);
            } else {
                return query(node * 2, b, m, l);
            }
        }
    }
    pair<int, int> Query(int i, int j) { return query(1, 1, n, i)[j - 1]; }
};

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<string> mat(n);
    for (auto& x : mat)
        cin >> x;
    SegmentTree st(mat);
    while (k--) {
        char c; int x, y; cin >> c >> x >> y;
        if (c == 'A') {
            auto ret = st.Query(x, y);
            cout << ret.first << " " << ret.second << endl;
        } else {
            char c; cin >> c;
            st.Update(x, y, c);
        }
    }
    return 0;
}