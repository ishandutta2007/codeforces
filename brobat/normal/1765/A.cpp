#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); i++)

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A,
vi& B) {
if (A[a] != L) return 0;
A[a] = -1;
for (int b : g[a]) if (B[b] == L + 1) {
B[b] = 0;
if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A
, B))
return btoa[b] = a, 1;
}
return 0;
}

int dfsMatching(vector<vi>& g, vi& btoa) {
int res = 0;
vi A(g.size()), B(btoa.size()), cur, next;
for (;;) {
fill(all(A), 0);
fill(all(B), 0);
cur.clear();
for (int a : btoa) if(a != -1) A[a] = -1;
rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
for (int lay = 1;; lay++) {
bool islast = 0;
next.clear();
for (int a : cur) for (int b : g[a]) {
if (btoa[b] == -1) {
B[b] = lay;
islast = 1;
}
else if (btoa[b] != a && !B[b]) {
B[b] = lay;
next.push_back(btoa[b]);
}
}
if (islast) break;
if (next.empty()) return res;
for (int a : next) A[a] = lay;
cur.swap(next);
}
rep(a,0,sz(g))
res += dfs(a, 0, g, btoa, A, B);
}
}



class DSU {
    vector <int> p;
    int n;
public:
    DSU (int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            p[d] = c;
            return true;
        }
        return false;
    }
};

vector<vector<int>> cmon_you_got_this(vector<vector<int>> &adj) {
    // Find minimum node-disjoint path cover.
    // Return the paths in the cover.
    int n = adj.size();
    vector<int> btoa(n, -1);
    dfsMatching(adj, btoa);
    // cout << n - flow << '\n';
    DSU d(n);
    for(int i = 0; i < n; i++) {
        if(btoa[i] != -1) {
            d.unite(i, btoa[i]);
        }
    }
    // cout << n - flow << '\n';
    // for(int i = 0; i < n; i++) {
    //     cout << i + 1 << ' ' << btoa[i] + 1 << '\n';
    // }
    vector<vector<int>> lol(n);
    for(int i = 0; i < n; i++) {
        lol[d.find(i)].push_back(i);
    }
    vector<vector<int>> group;
    for(int i = 0; i < n; i++) {
        if(!lol[i].empty()) {
            group.push_back(lol[i]);
        }
    }
    // for(int i = 0; i < (int)group.size(); i++) {
    //     cout << i << ':';
    //     for(auto j : group[i]) cout << j + 1 << ' ';
    //     cout << '\n';
    // }
    return group;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> mat(m, vector<int>(m, 0)); // adj. matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(i == j) continue;
            // check if document i is a subset of j.
            bool pos = true;
            bool equal = true;
            for(int k = 0; k < n; k++) {
                if(v[k][i] == '1' && v[k][j] == '0') {
                    pos = false;
                }
                if(v[k][i] != v[k][j]) equal = false;
            }
            if(pos) mat[i][j] = 1;
            if(equal && (j < i)) mat[i][j] = 0;
        }
    }
    vector<vector<int>> adj(m);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j]) {
                adj[i].push_back(j);
            }
        }
    }
    vector<vector<int>> group = cmon_you_got_this(adj);
    int g = group.size();
    cout << g << '\n';
    vector <int> access(m);
    for(int i = 0; i < g; i++) {
        for(auto j : group[i]) {
            access[j] = i;
        }
    }
    for(int i = 0; i < m; i++) {
        cout << access[i] + 1 << ' ';
    }
    cout << '\n';
    vector<int> doc(m, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '1') {
                doc[j]--;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        cout << doc[i] + 1 << ' ';
    }
    cout << '\n';
    vector<vector<int>> level(n, vector<int>(g, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '1') {
                level[i][access[j]] = max(level[i][access[j]], doc[j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < g; j++) {
            cout << level[i][j] + 1 << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}