#include <bits/stdc++.h>

using namespace std;

//Modified kactl implementation
struct TwoSat {
    int N, sz;
    vector<vector<int>> adj[2];
    vector<int> values;
    vector<int> comp;
    vector<int> ord;

    TwoSat(int n): N {n} {
        adj[0] = vector<vector<int>>(n<<1);
        adj[1] = vector<vector<int>>(n<<1);
    }

    void add_edge(int u, int v) {
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }

    void either(int x, int y) {
        add_edge(x^1, y);
        add_edge(y^1, x);
    }

    void set_value(int x) {
        either(x, x);
    }

    void add_vars(int t = 1) {
        N += t;
        adj[0].resize(N<<1);
        adj[1].resize(N<<1);
    }

    void at_most_one(const vector<int> &vars) { // to be tested XXX
        int t = vars.size();
        if (t <= 1) return;

        int prv_n = N;
        add_vars(t - 1);
        for (int i = 1; i < t; i++) {
            either(vars[i-1]^1, prv_n+i-1 << 1);
            if (i-1)
                either(prv_n+i-2 << 1 ^ 1, prv_n+i-1 << 1);
            either(prv_n+i-1 << 1 ^ 1, vars[i]^1);
        }
    }

    void dfs(int v) {
        for (int u: adj[0][v])
            if (comp[u] == -1)
                comp[u] = 1, dfs(u);
        ord[sz++] = v;
    }

    void rev_dfs(int v) {
        for (int u: adj[1][v])
            if (comp[u] == -1)
                comp[u] = comp[v], rev_dfs(u);
    }

    bool solve() {
        values.resize(N<<1, -1);
        comp.resize(N<<1, -1);
        ord.resize(N<<1, -1);
        sz = 0;
        for (int v = 0; v < N<<1; v++)
            if (comp[v] == -1)
                comp[v] = v, dfs(v);

        fill(comp.begin(), comp.end(), -1);
        for (int i = sz-1; ~i; i--)
            if (comp[ord[i]] == -1)
                comp[ord[i]] = i, rev_dfs(ord[i]);

        for (int var = 0; var < N; var++)
            if (comp[var<<1] == comp[var<<1^1])
                return false;
 
        for (int v: ord)
            values[v] = comp[v] < comp[v^1];
        return true;
    }
};

int n, m, k;

void set_not(int i, int x, TwoSat &ts) {
    if (x == 1)
        ts.set_value(i*k+1<<1);
    else if (x == k)
        ts.set_value(i*k+k-1<<1^1);
    else
        ts.either(i*k+x<<1, i*k+x-1<<1^1);
}

void solve() {
    cin >> n >> m >> k;
    TwoSat ts {n*k};
    for (int i = 0; i < n; i++) {
        ts.set_value(i*k<<1);
        for (int j = 1; j < k; j++)
            ts.either(i*k+j<<1^1, i*k+j-1<<1);
    }

    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j < k; j++)
            ts.either(i*k+j<<1^1, (i+1)*k+j<<1);

    while (m--) {
        int t; cin >> t;
        switch (t) {
            case 1: 
            {
                int i, x; cin >> i >> x, i--;
                set_not(i, x, ts);
                break;
            }

            case 2:
            {
                int i, j, x; cin >> i >> j >> x, i--, j--;
                for (int y = 1; y <= k; y++)
                    if (y >= x)
                        ts.set_value(i*k+y-1<<1^1);
                    else if (x - y < k) {
                        ts.either(i*k+y-1<<1^1, j*k + x-y<<1^1);
                    }
                break;
            }

            case 3:
            {
                int i, j, x; cin >> i >> j >> x, i--, j--;
                if (x > k)
                    ts.set_value(j*k+x-k-1<<1);
                for (int y = 1; y <= k; y++)
                    if (x-y+1 > k)
                        ts.set_value(i*k+y-1<<1);
                    else if (x-y+1 >= 1)
                        ts.either(i*k+y-1<<1, j*k+x-y<<1);
                break;
            }

            default:
                assert(0);
        }
    }

    if (!ts.solve())
        cout << "-1\n";
    else {
        for (int i = 0; i < n; i++)
            for (int j = k-1; ~j; j--)
                if (ts.values[i*k+j<<1]) {
                    cout << j+1 << " ";
                    break;
                }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te; cin >> te;
    while (te--)
        solve();
    return 0;
}