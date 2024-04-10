#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n], cur_tm, last[max_n], parent[max_n], sz[max_n];
long long cur, ans[max_n], c2[max_n];
vector<pair<int, int>> g[max_n];

int find_set(int v) {
    if (last[v] < cur_tm) {
        last[v] = cur_tm;
        sz[v] = 1;
        parent[v] = v;
    }
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    cur -= c2[sz[v1]];
    cur -= c2[sz[v2]];
    if (sz[v1] < sz[v2]) {
        swap(v1, v2);
    }
    parent[v2] = v1;
    sz[v1] += sz[v2];
    cur += c2[sz[v1]];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        c2[i] = (1LL * i * (i - 1)) / 2;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[__gcd(a[u], a[v])].push_back({u, v});
    }
    for (int i = 1; i < max_n; ++i) {
        ++cur_tm;
        cur = 0;
        for (int j = i; j < max_n; j += i) {
            for (const pair<int, int> &p : g[j]) {
                union_set(p.first, p.second);
            }
        }
        ans[i] = cur;
    }
    for (int i = max_n - 1; i >= 1; --i) {
        for (int j = 2 * i; j < max_n; j += i) {
            ans[i] -= ans[j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        ++ans[a[i]];
    }
    for (int i = 1; i < max_n; ++i) {
        if (ans[i]) {
            printf("%d %I64d\n", i, ans[i]);
        }
    }
    return 0;
}