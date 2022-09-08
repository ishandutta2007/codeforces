#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 333333, inf = 1000000007;

long long n, m, dist[max_n], used[max_n];
vector<int> g[max_n], q;
pair<int, int> o[max_n];

void dfs(int v, int len) {
    q.push_back(v);
    dist[v] = len;
    used[v] = 1;
    o[v].first = q.size();
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i], len + 1);
        }
    }
    o[v].second = q.size();
}

struct tree {
    long long a[7 * max_n], f[7 * max_n];
    tree() {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
    }
    void push(int v, int l, int r) {
        if (f[v] != 0) {
            f[2 * v] = f[2 * v] + f[v];
            f[2 * v + 1] = f[2 * v + 1] + f[v];
            int mid = (l + r) / 2;
            a[2 * v] = a[2 * v] + (mid - l + 1) * f[v];
            a[2 * v + 1] = a[2 * v + 1] + (r - mid) * f[v];
            a[v] = a[2 * v] + a[2 * v + 1];
            f[v] = 0;
        }
    }
    void update(int v, int tl, int tr, int l, int r, long long value) {
        if (tl == l && tr == r) {
            a[v] = (a[v] + (r - l + 1) * value) % inf;
            f[v] = (f[v] + value) % inf;
            return;
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        a[v] = (a[2 * v] + a[2 * v + 1]) % inf;
    }
    long long get_sum(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

tree t1, t2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    dfs(1, 1);
    int BRED = 0;
    for (int i = 1; i <= n; ++i) {
        --dist[i];
        ++BRED;
        //cout << o[i].first << ' ' << o[i].second << endl;
    }
    BRED *= 0;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int v, x, k;
            cin >> v >> x >> k;
            t1.update(1, 1, n, o[v].first, o[v].second, (x + dist[v] * k) % inf);
            t2.update(1, 1, n, o[v].first, o[v].second, k);
        }
        if (t == 2) {
            int v;
            cin >> v;
            v += BRED;
            cout << BRED + ((t1.get_sum(1, 1, n, o[v].first, o[v].first) - dist[v] * t2.get_sum(1, 1, n, o[v].first, o[v].first)) % inf + inf) % inf << endl << "";
        }
    }
    return 0;
}