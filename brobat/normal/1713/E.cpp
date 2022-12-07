#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    int n;
    vector <int> p, sz;
    vector<set<pair<int, int>>> s; // {node, color}.

    DSU(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.resize(n, 1);
        s.resize(n);
        for(int i = 0; i < n; i++) {
            s[i].insert({i, 0});
        }
    }

    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    void unite(int a, int b, int x) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(sz[c] < sz[d]) {
                swap(c, d);
                swap(a, b);
            }
            p[d] = c;
            sz[c] += sz[d];

            // Now UNITE c and d, merging their colors. Use a and b.
            bool swap = 0;
            auto ff = s[c].lower_bound({a, -1});
            auto ss = s[d].lower_bound({b, -1});

            if((*ff).second == (*ss).second) {
                if(x == 1) swap = 1;
            } else {
                if(x == 0) swap = 1;
            }
            for(auto i : s[d]) {
                s[c].insert({i.first, i.second ^ swap});
            }
            s[d].clear();
        }
    }

    void update_color(int node, int col) {
        int root = find(node);
        s[root].erase(s[root].lower_bound({node, -1}));
        s[root].insert({node, col});
    }

    int color(int node) {
        int root = find(node);
        return (*s[root].lower_bound({node, -1})).second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        // vector <int> c(n, -1);
        DSU d(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(grid[i][j] > grid[j][i]) {
                    d.unite(i, j, 1);
                } else if(grid[i][j] < grid[j][i]) {
                    d.unite(i, j, 0);
                }
            }
        }
        auto g1 = grid;
        auto g2 = grid;
        for(int k = 0; k < n; k++) {
            if(d.color(k) == 1) {
                for(int i = 0; i < n; i++) {
                    swap(g1[i][k], g1[k][i]);
                }
            }
            if(d.color(k) == 0) {
                for(int i = 0; i < n; i++) {
                    swap(g2[i][k], g2[k][i]);
                }
            }
        }
        if(g1 > g2) swap(g1, g2);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << g1[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    
    return 0;
}