/**
 *  created: 16/12/2020, 12:08:50
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, mod = 1000000007;

int n, ans;
long long x[max_n];
vector<int> g[max_n];

map<long long, int> update(const map<long long, int> &all, long long x) {
    map<long long, int> res;
    for (const auto &p : all) {
        res[__gcd(x, p.first)] += p.second;
    }
    return res;
}

void dfs(int v, int p, map<long long, int> all) {
    ++all[x[v]];
    all = update(all, x[v]);
    for (const auto &p : all) {
        ans += 1LL * p.first * p.second % mod;
        ans %= mod;
    }
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v, all);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &x[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1, {});
    printf("%d\n", ans);
    return 0;
}