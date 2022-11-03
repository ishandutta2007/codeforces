#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > g;
vector<int> d, lf, mn, mx, am;

void DFS(int v, int pr)
{
    if (pr == -1) {
        d[v] = 0;
    } else {
        d[v] = 1 - d[pr];
    }
    lf[v] = 1;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != pr) {
            lf[v] = 0;
            DFS(u, v);
        }
    }
    if (lf[v]) {
        am[v] = 1;
    } else {
        am[v] = 0;
        for (int i = 0; i < (int) g[v].size(); ++i) {
            int u = g[v][i];
            if (u != pr) {
                am[v] += am[u];
            }
        }
    }
    // mx
    mx[v] = 0;
    if (!d[v]) {
        for (int i = 0; i < (int) g[v].size(); ++i) {
            int u = g[v][i];
            if (u != pr) {
                mx[v] = max(mx[v], am[v] - am[u] + mx[u]);
            }
        }   
    } else {
        for (int i = 0; i < (int) g[v].size(); ++i) {
            int u = g[v][i];
            if (u != pr) {
                mx[v] += mx[u];
            }
        }
    }
    // mn
    mn[v] = am[v] - 1;
    if (!d[v]) {
        for (int i = 0; i < (int) g[v].size(); ++i) {
            int u = g[v][i];
            if (u != pr) {
                mn[v] -= (am[u] - 1 - mn[u]);
            }
        }
    } else {
        for (int i = 0; i < (int) g[v].size(); ++i) {
            int u = g[v][i];
            if (u != pr) {
                mn[v] = min(mn[v], mn[u]);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1; --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    d.resize(n);
    lf.resize(n);
    mn.resize(n);
    mx.resize(n);
    am.resize(n);
    DFS(0, -1);
    cout << mx[0] + 1 << " " << mn[0] + 1 << endl;
 
    return 0;
}