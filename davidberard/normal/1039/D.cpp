#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;

int f[N];
int g[N];
vector<int> adj[N];
int n;
int ans[N];
int cc;

struct max2 {
    int first, second;
    max2() :first(0), second(0) {}
    void insert(const int& x) {
        if (x > first) {
            second = first;
            first = x;
        } else if (x > second) {
            second = x;
        }
    }
    int sum() const {
        return first + second;
    }
};
clock_t t1;

vector<pii> db;
vector<int> ord;

void dfs_build(int u, int p, int h=1) {
    db.emplace_back(h, u);
    for (int i=0; i<adj[u].size(); ++i) {
        if (adj[u][i] == p) {
            adj[u].erase(adj[u].begin() + i);
            --i;
        } else {
            dfs_build(adj[u][i], u, h+1);
        }
    }
}

void dfs(int u, int k) {
    f[u] = 0;
    max2 m2;
    for (auto& v : adj[u]) {
        //if (v == p) continue;
        dfs(v, k);
        f[u] += f[v];
        m2.insert(g[v]);
    }

    if (m2.sum()+1 >= k) {
        f[u]++;
        g[u] = 0;
    } else {
        g[u] = m2.first + 1;
    }
    //cerr << " " << u << " " << k << " : " << f[u] << " " << g[u] << endl;
}

inline void compute(int u, int k) {
    f[u] = 0;
    max2 m2;
    for (auto& v : adj[u]) {
        f[u] += f[v];
        m2.insert(g[v]);
    }

    if (m2.sum()+1 >= k) {
        f[u]++;
        g[u] = 0;
    } else {
        g[u] = m2.first + 1;
    }
}

int solve(int k) {
    for (auto& x : ord) {
        compute(x, k);
    }
    //dfs(1, k);
    return f[1];
}

void solve_range(int l, int r, int lo, int hi) {
    if (l > r) return;
    int m = (l+r)/2;
    int x = lo;
    if (lo != hi) {
        x = solve(m);
        ++cc;
        //cerr << " for " << m << " solving and get " << x << endl;
    }
    ans[m] = x;
    solve_range(l, m-1, x, hi);
    solve_range(m+1, r, lo, x);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    t1 = clock();
    cin >> n;
    for (int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs_build(1, -1);
    sort(db.begin(), db.end());
    for (int i=db.size()-1; i>=0; --i) {
        ord.push_back(db[i].second);
    }

    solve_range(1, n, 0, n);
    for (int i=1; i<=n; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}