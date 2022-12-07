#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<vector<int>> parent;
vector<vector<int>> sz;

int find(int b, int x) {
    if(x==parent[b][x]) return x;
    return parent[b][x] = find(b, parent[b][x]);
}

void unite(int bit, int a, int b) {
    int c = find(bit, a);
    int d = find(bit, b);
    if(d!=c) {
        if(sz[bit][d] > sz[bit][c]) swap(c, d);
        parent[bit][d] = c;
        sz[bit][c] += sz[bit][d];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m;
    cin >> n >> m;
    // vector<vector<pair<int, int>>> adj(n);
    parent.resize(60, vector<int>(n));
    sz.resize(60, vector<int>(n));
    vector<vector<int>> pos(30, vector<int>(n, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 60; j++) {
            parent[j][i] = i;
            sz[j][i] = 1;
        }
    }
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        --t1; --t2;
        // adj[t1].push_back({t2, t3});
        // adj[t2].push_back({t1, t3});
        for(int j = 0; j < 30; j++) {
            if((t3 >> j) & 1) {
                unite(j, t1, t2);
            }
        }
        for(int j = 1; j < 30; j++) {
            int x = (t3 >> j) & 1;
            int y = t3 % 2;
            if(!(x == 0 && y == 1)) {
                bool t = pos[j][find(30 + j, t1)] || pos[j][find(30 + j, t2)];
                unite(30 + j, t1, t2);
                if(y == 0 || t) {
                    pos[j][find(30 + j, t1)] = true;
                    pos[j][find(30 + j, t2)] = true;
                }
            }
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        bool zero = false;
        for(int j = 0; j < 30; j++) {
            if(find(j, a) == find(j, b)) {
                zero = true;
                break;
            }
        }
        if(zero) {
            cout << 0 << '\n';
            continue;
        }
        bool one = false;
        for(int j = 1; j < 30; j++) {
            if(pos[j][find(30 + j, a)]) {
                one = true;
                break;
            }
        }
        cout << (one ? 1 : 2) << '\n';
    }
    
    return 0;
}