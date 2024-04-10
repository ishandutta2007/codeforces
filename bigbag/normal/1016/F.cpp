#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333;
const long long inf = 1000111222000111222LL;

int n, m, to[max_n], sz[max_n], parent[max_n];
long long len[max_n], lento[max_n], dd[max_n], mx[max_n];
bool has[max_n];
vector<int> path;
vector<pair<int, int>> g[max_n];

bool dfs(int v, int p) {
    parent[v] = p;
    sz[v] = 1;
    for (const pair<int, int> &e : g[v]) {
        int nxt = e.first, d = e.second;
        if (nxt != p) {
            if (dfs(nxt, v)) {
                to[v] = nxt;
                len[v] = len[nxt] + d;
                dd[v] = d;
            }
            sz[v] += sz[nxt];
        }
    }
    if (v == n || to[v]) {
        path.push_back(v);
        return true;
    }
    return false;
}

bool ok() {
    for (int v : path) {
        if (sz[v] - sz[to[v]] > 2) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        g[u].push_back({v, d});
        g[v].push_back({u, d});
    }
    dfs(1, 0);
    /*for (int i = 1; i <= n; ++i) {
        cout << i << " " << to[i] << " " << len[i] << endl;
    }*/
    reverse(path.begin(), path.end());
    if (ok()) {
        for (int i = 0; i < m; ++i) {
            printf("%I64d\n", len[1]);
        }
        return 0;
    }
    long long cur = 0;
    for (int i = 0; i < path.size(); ++i) {
        lento[path[i]] = cur;
        cur += dd[path[i]];
    }
    mx[path.size()] = -inf;
    mx[path.size() + 1] = -inf;
    for (int i = path.size() - 1; i >= 0; --i) {
        int v = path[i];
        long long res = 0;
        for (const pair<int, int> &e : g[v]) {
            if (e.first != parent[v] && e.first != to[v]) {
                res = e.second;
                has[i] = true;
            }
        }
        res += len[v];
        mx[i] = res;
    }
    for (int i = path.size() - 1; i >= 0; --i) {
        mx[i] = max(mx[i], mx[i + 1]);
    }
    long long best = 0;
    for (int i = 0; i + 1 < path.size(); ++i) {
        int v = path[i];
        long long res = 0;
        for (const pair<int, int> &e : g[v]) {
            if (e.first != parent[v] && e.first != to[v]) {
                res = e.second;
            }
        }
        res += lento[v];
        //cout << i << " " << res << endl;
        if ((!has[i]) && (!has[i + 1])) {
            res += mx[i + 2];
        } else {
            res += mx[i + 1];
        }
        best = max(best, res);
        //cout << i << " " << res << endl;
    }
    while (m--) {
        int x;
        scanf("%d", &x);
        printf("%I64d\n", min(len[1], best + x));
    }
    return 0;
}