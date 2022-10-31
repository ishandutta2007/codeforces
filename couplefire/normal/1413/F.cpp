#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int N = 5e5 + 1;

struct SegmentTree {
    int n;
    vector<int> a;
    vector<int> b;

    int mod[4 * N];
    int t[4 * N][2];

    void pull(int v) {
        t[v][0] = max(t[2 * v + 1][0], t[2 * v + 2][0]);
        t[v][1] = max(t[2 * v + 1][1], t[2 * v + 2][1]);
    }

    void apply(int v) {
        swap(t[v][0], t[v][1]);
        mod[v] ^= 1;
    }

    void push(int v) {
        if (mod[v]) {
            apply(2 * v + 1);
            apply(2 * v + 2);
            mod[v] = 0;
        }
    }

    void build(int v, int l, int r) {
        if (l + 1 == r) {
            t[v][a[l] & 1] = b[l];
            t[v][1 ^ (a[l] & 1)] = -1;
        } else {
            int m = (r + l) >> 1;
            build(2 * v + 1, l, m);
            build(2 * v + 2, m, r);
            pull(v);
        }
    }


    void inv(int v, int l, int r, int ql, int qr) {
        if (r <= ql || qr <= l) {
            return;
        } else if (ql <= l && r <= qr) {
            apply(v);
        } else {
            push(v);
            int m = (r + l) >> 1;
            inv(2 * v + 1, l, m, ql, qr);
            inv(2 * v + 2, m, r, ql, qr);
            pull(v);
        }
    }

    void inv(int l, int r) {
        inv(0, 0, n, l, r);
    }

    int mx() {
        return t[0][0];
    }

    SegmentTree(vector<int> a_, vector<int> b_) {
        a = a_;
        b = b_;
        n = (int)a.size();
        for (int i = 0; i < 4 * n; i++) {
            mod[i] = 0;
            t[i][0] = -1;
            t[i][1] = -1;
        }
        build(0, 0, n);
    }
};

vector<tuple<int, int, int>> g[N];

void solve(int n, int root, vector<int> &md, vector<int> &ans) {
    vector<int> in(n);
    vector<int> out(n);
    vector<int> et;
    vector<int> eth;
    vector<int> v_id(n);
    function<void(int, int, int, int)> dfs = [&](int cur, int p, int c, int h) {
        in[cur] = (int)et.size();
        et.push_back(c);
        eth.push_back(h);
        for (auto C : g[cur]) {
            int u, t, i;
            tie(u, t, i) = C;
            if (u != p) {
                v_id[i] = u;
                dfs(u, cur, c ^ t, h + 1);
            }
        }
        out[cur] = (int)et.size();
    };
    dfs(root, -1, 0, 0);
    SegmentTree S(et, eth);
    for (int i = 0; i < (int)md.size(); i++) {
        int v = v_id[md[i]];
        S.inv(in[v], out[v]);
        ans[i] = max(ans[i], S.mx());
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i + 1 < n; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--;
        v--;
        g[u].push_back({v, t, i});
        g[v].push_back({u, t, i});
    }
    int mx = -1;
    int w = -1;
    function<void(int, int, int)> dfs = [&](int cur, int p, int d) {
        if (mx < d) {
            mx = d;
            w = cur;
        }
        for (auto C : g[cur]) {
            int u, t, i;
            tie(u, t, i) = C;
            if (u != p) {
                dfs(u, cur, d + 1);
            }
        }
    };
    dfs(0, -1, 0);
    int F = w;
    mx = -1;
    w = -1;
    dfs(F, -1, 0);
    int S = w;

    int q;
    cin >> q;
    vector<int> md(q);
    vector<int> ans(q, -1);
    for (auto &t : md) {
        cin >> t;
        t--;
    }
    solve(n, F, md, ans);
    solve(n, S, md, ans);
    for (auto t : ans) {
        cout << t << '\n';
    }
}