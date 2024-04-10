#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

const int N = 200666;
vector<int> tree[N];
int cnt[1 << 20];
ll result[N];
int mx_sz[N];
int used[N];
int sz[N];
string s;
ll cheburek = 0;

void dfs_size(int v, int p) {
    sz[v] = 1;
    mx_sz[v] = -1;
    for (int u : tree[v]) {
        if (u == p) {
            continue;
        }
        if (used[u]) {
            continue;
        }
        dfs_size(u, v);
        sz[v] += sz[u];
        if (mx_sz[v] == -1 || sz[mx_sz[v]] < sz[u]) {
            mx_sz[v] = u;
        }
    }
}

void dfs_add(int v, int p, int mask) {
    mask ^= (1 << (s[v] - 'a'));
    ++cnt[mask];
    for (int u : tree[v]) {
        if (u == p || used[u]) {
            continue;
        }
        dfs_add(u, v, mask);
    }
}

void dfs_del(int v, int p, int mask) {
    mask ^= (1 << (s[v] - 'a'));
    --cnt[mask];
    for (int u : tree[v]) {
        if (u == p || used[u]) {
            continue;
        }
        dfs_del(u, v, mask);
    }
}

ll dfs_ans(int v, int p, int mask) {
    mask ^= (1 << (s[v] - 'a'));
    ll res = cnt[mask];
    for (ll i = 0; i < 20; ++i) {
        res += cnt[mask ^ (1 << i)];
    }
    for (int u : tree[v]) {
        if (u == p || used[u]) {
            continue;
        }
        res += dfs_ans(u, v, mask);
    }
    result[v] += res;
    return res;
}

void dfs_find(int v) {
    dfs_size(v, -1);
    int m = sz[v];
    while (mx_sz[v] != -1 && sz[mx_sz[v]] * 2 > m) {
        v = mx_sz[v];
    }
    used[v] = true;
    dfs_add(v, -1, 0);
    int mask = (1 << (s[v] - 'a'));
    ll delta = cnt[0];
    for (ll u : tree[v]) {
        if (used[u]) {
            continue;
        }
        dfs_del(u, -1, mask);
        delta += dfs_ans(u, -1, 0);
        dfs_add(u, -1, mask);
    }
    for (ll i = 0; i < 20; ++i) {
        delta += cnt[1 << i];
    }
    result[v] += delta / 2;
    dfs_del(v, -1, 0);
    for (ll u : tree[v]) {
        if (used[u]) {
            continue;
        }
        dfs_find(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int v, u;
        cin >> v >> u;
        tree[v - 1].emplace_back(u - 1);
        tree[u - 1].emplace_back(v - 1);
    }
    cin >> s;
    dfs_find(0);
    for (int i = 0; i < n; ++i) {
        cout << result[i] + 1 << " ";  
    }
    cout << endl;

    return 0;
}