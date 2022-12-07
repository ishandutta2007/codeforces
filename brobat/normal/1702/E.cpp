#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU {
public:
    vector <int> p, sz;
    int n;

    DSU(int x) {
        n = x;
        p.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++) {
            sz[i] = 1;
            p[i] = i;
        }
    }

    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    void unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(sz[c] < sz[d]) swap(c, d);
            p[d] = c;
            sz[c] += sz[d];
        }
    }

    int size(int x) {
        return sz[find(x)];
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
        vector <int> cnt(n, 0);
        DSU d(n);
        bool pos = true;
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            if(x > y) swap(x, y);
            if(x == y) pos = false;
            d.unite(x, y);
            cnt[x]++;
            cnt[y]++;
            if(cnt[x] > 2) pos = false;
            if(cnt[y] > 2) pos = false;
        }
        for(int i = 0; i < n; i++) {
            if(d.size(i) % 2) pos = false;
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}