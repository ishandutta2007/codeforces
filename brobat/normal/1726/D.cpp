#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    int n;
    vector <int> p, sz;

    DSU(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.resize(n, 1);
    }

    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(sz[c] < sz[d]) swap(c, d);
            p[d] = c;
            sz[c] += sz[d];
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m);
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            v[i] = {x - 1, y - 1, i};
        }
        vector <int> ans(m, -1);
        while(true) {
            ans.assign(m, -1);
            shuffle(v.begin(), v.end(), rng);
            DSU a(n), b(n);
            bool pos = true;
            for(int i = 0; i < m; i++) {
                if(a.unite(v[i][0], v[i][1])) {
                    ans[v[i][2]] = 1;
                } else if(b.unite(v[i][0], v[i][1])) {
                    ans[v[i][2]] = 0;
                } else {
                    pos = false;
                    break;
                }
            }
            if(pos) break;
        }
        for(auto i : ans) cout << i;
        cout << '\n';
    }
    
    return 0;
}