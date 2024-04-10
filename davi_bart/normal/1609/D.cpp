#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct dsu {
    vector<int> parent;
    vector<int> dim;
    void init() {
        parent.resize(1010);
        dim.resize(1010);
        for (int i = 0; i < 1010; i++) {
            parent[i] = i;
            dim[i] = 1;
        }
    }
    int find(int pos) {
        if (parent[pos] != pos) {
            parent[pos] = find(parent[pos]);
        }
        return parent[pos];
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (dim[a] < dim[b]) swap(a, b);
        parent[b] = a;
        dim[a] += dim[b];
    }
} ss;
void solve() {
    int N, M;
    cin >> N >> M;
    ss.init();
    int vuote = 0;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        a = ss.find(a);
        b = ss.find(b);
        if (a == b) vuote++;
        ss.unite(a, b);
        int ma = 0;
        vector<int> p;
        vector<bool> vis(N + 1, 0);
        for (int j = 0; j < N; j++) {
            int x = ss.find(j);
            if (!vis[x]) {
                vis[x] = 1;
                p.pb(ss.dim[x]);
            }
        }
        sort(p.begin(), p.end(), greater<int>());
        for (int i = 0; i < min(1 + vuote, (int)p.size()); i++) {
            ma += p[i];
        }
        cout << ma - 1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}