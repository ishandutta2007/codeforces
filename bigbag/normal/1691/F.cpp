/**
 *  created: 31/05/2022, 18:39:57
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, mod = 1000000007;

inline void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

inline void dec(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

inline int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int a, int b) {
    int res = 1 % mod;
    while (b) {
        if (b % 2) {
            res = mul(res, a);
        }
        b /= 2;
        a = mul(a, a);
    }
    return res;
}

int inv(int x) {
    return power(x, mod - 2);
}

const int max_f = max_n;

int f[max_f], rf[max_f];

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_f; ++i) {
        f[i] = mul(i, f[i - 1]);
    }
    rf[max_f - 1] = inv(f[max_f - 1]);
    for (int i = max_f - 2; i > 0; --i) {
        rf[i] = mul(i + 1, rf[i + 1]);
    }
}

int get_c(int n, int k) {
    if (n < k) {
        return 0;
    }
    return mul(f[n], mul(rf[k], rf[n - k]));
}

int n, k, ans, sz[max_n];
vector<int> g[max_n];

int sum, sum2, val[max_n];

void dfs1(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to != p) {
            dfs1(to, v);
            sz[v] += sz[to];
            inc(sum, mul(sz[to], get_c(sz[to], k)));
            inc(val[v], get_c(sz[to], k));
        }
    }
    dec(sum2, mul(sz[v], val[v]));
}

void dfs2(int v, int p) {
    inc(ans, sum);
    inc(ans, sum2);
    for (int to : g[v]) {
        if (to != p) {
            int old_sum = sum, old_sum2 = sum2, val_v = val[v], val_to = val[to];
            inc(sum2, mul(sz[v], val[v]));
            dec(val[v], get_c(sz[to], k));
            sz[v] -= sz[to];
            dec(sum2, mul(sz[v], val[v]));
            dec(sum, mul(sz[to], get_c(sz[to], k)));
            inc(sum, mul(sz[v], get_c(sz[v], k)));
            inc(sum2, mul(sz[to], val[to]));
            sz[to] += sz[v];
            inc(val[to], get_c(sz[v], k));
            dec(sum2, mul(sz[to], val[to]));

            dfs2(to, v);

            sz[to] -= sz[v];
            sz[v] += sz[to];
            sum = old_sum;
            sum2 = old_sum2;
            val[v] = val_v;
            val[to] = val_to;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    get_all_f();
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = mul(n, mul(n, get_c(n, k)));
    dfs1(0, -1);
    dfs2(0, -1);
    cout << ans << "\n";
    return 0;
}