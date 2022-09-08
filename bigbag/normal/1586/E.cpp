/**
 *  created: 17/10/2021, 14:57:15
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, m, q, used[max_n], a[max_n], h[max_n], p[max_n];
vector<int> g[max_n], ng[max_n];
int U[max_n], V[max_n];
int bad;

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (used[to]) {
            continue;
        }
        h[to] = h[v] + 1;
        p[to] = v;
        dfs(to);
        ng[v].push_back(to);
    }
}

void dfs2(int v) {
    for (int to : ng[v]) {
        dfs2(to);
        a[v] ^= a[to];
    }
    if (a[v]) {
        ++bad;
        a[v] = 0;
    }
}

void write_path(int a, int b) {
    vector<int> path1, path2;
    while (a != b) {
        if (h[a] > h[b]) {
            path1.push_back(a);
            a = p[a];
        } else {
            path2.push_back(b);
            b = p[b];
        }
    }
    path1.push_back(a);
    reverse(path2.begin(), path2.end());
    path1.insert(path1.end(), path2.begin(), path2.end());
    cout << path1.size() << "\n";
    for (int v : path1) {
        cout << v + 1 << " ";
    }
    cout << "\n";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int root = 0;
    dfs(root);
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> U[i] >> V[i];
        --U[i];
        --V[i];
        a[U[i]] ^= 1;
        a[V[i]] ^= 1;
    }
    dfs2(root);
    if (!bad) {
        cout << "YES\n";
        for (int i = 0; i < q; ++i) {
            write_path(U[i], V[i]);
        }
    } else {
        cout << "NO\n";
        cout << (bad + 1) / 2 << "\n";
    }
    return 0;
}