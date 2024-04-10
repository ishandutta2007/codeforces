#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int n, used[max_n], sz[max_n];
vector<int> g[max_n];
int root;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
}

void answer(int x) {
    cout << "! " << x << endl;
    exit(0);
}

void find_root(int v, int p) {
    int cnt = 0;
    for (int to : g[v]) {
        cnt += !used[to];
        if (to == p || used[to]) {
            continue;
        }
        find_root(to, v);
    }
    if (cnt > 1) {
        root = v;
    }
}

void calc_sz(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p || used[to]) {
            continue;
        }
        calc_sz(to, v);
        sz[v] += sz[to];
    }
}

void solve(int v) {
    root = -1;
    find_root(v, -1);
    if (root != -1) {
        v = root;
    }
    calc_sz(v, -1);
    for (int to : g[v]) {
        if (used[to]) {
            continue;
        }
        if (sz[to] >= 2) {
            if (query(v, to) == to) {
                used[v] = 1;
                solve(to);
                return;
            }
            used[to] = 1;
            solve(v);
            return;
        }
    }
    vector<int> all;
    for (int to : g[v]) {
        if (used[to]) {
            continue;
        }
        all.push_back(to);
    }
    while (all.size() > 1) {
        int a = all.back();
        all.pop_back();
        int b = all.back();
        all.pop_back();
        int res = query(a, b);
        if (res == a || res == b) {
            answer(res);
        }
    }
    if (all.empty()) {
        answer(v);
    }
    answer(query(v, all[0]));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    solve(1);
    return 0;
}