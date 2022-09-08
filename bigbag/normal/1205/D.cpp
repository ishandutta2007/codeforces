#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, sz[max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            sz[v] += sz[to];
        }
    }
}

int root;
long long best;

void rec(int v, int p) {
    int tot = n - 1;
    vector<int> szs;
    for (int to : g[v]) {
        if (to != p) {
            rec(to, v);
            tot -= sz[to];
            szs.push_back(sz[to]);
        }
    }
    if (tot) {
        szs.push_back(tot);
    }
    sort(szs.begin(), szs.end());
    tot = n - 1;
    int x = 0;
    for (int i = 0; i < szs.size(); ++i) {
        x += szs[i];
        int y = tot - x;
        if (best < (x + 1) * (y + 1)) {
            best = (x + 1) * (y + 1);
            root = v;
        }
    }
}

bool cmp(int u, int v) {
    return sz[u] < sz[v];
}

int first = 1, coef = 1;

void solve(int v, int p, int sum) {
    cout << p << " " << v << " " << coef * (first - sum) << endl;
    sum = first;
    ++first;
    for (int to : g[v]) {
        if (to != p) {
            solve(to, v, sum);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n == 1) {
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    rec(1, -1);
    //cout << root << " " << best << endl;
    dfs(root, -1);
    sort(g[root].begin(), g[root].end(), cmp);
    int x = 0;
    int pos = -1;
    for (int i = 0; i < g[root].size(); ++i) {
        x += sz[g[root][i]];
        int y = n - 1 - x;
        if (best == (x + 1) * (y + 1)) {
            pos = i + 1;
            break;
        }
    }
    assert(pos != -1);
    for (int i = 0; i < pos; ++i) {
        solve(g[root][i], root, 0);
    }
    //cout << "$" << first << "  " << best << endl;
    coef = first;
    first = 1;
    for (int i = pos; i < g[root].size(); ++i) {
        solve(g[root][i], root, 0);
    }
    return 0;
}