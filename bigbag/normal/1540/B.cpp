/**
 *  created: 25/06/2021, 18:46:14
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 222, mod = 1000000007;

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

string str_fraq(int x, int n = 20) {
    stringstream res;
    pair<int, int> best(x, 1);
    for (int j = 1; j < n; ++j) {
        best = min(best, {mul(x, j), j});
    }
    res << best.first << "/" << best.second;
    return res.str();
}

int n, ans, sz[max_n], dp[max_n][max_n];
int rn;
vector<int> g[max_n];

void calc_sz(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        calc_sz(to, v);
        sz[v] += sz[to];
    }
}

vector<int> all;

void dfs(int v, int p) {
    all.push_back(v);
    if (all.size() >= 2 && all[0] > v) {
        vector<int> szs;
        int last = 0;
        for (int i = all.size() - 1; i >= 0; --i) {
            szs.push_back(sz[all[i]] - last);
            assert(szs.back() >= 1);
            last = sz[all[i]];
        }
        reverse(szs.begin(), szs.end());
        for (int i = 0; i + 1 < szs.size(); ++i) {
            int p = mul(szs[i], rn);
            int coef = dp[i][szs.size() - i - 1];
            p = mul(p, coef);
            inc(ans, p);
        }
    }
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
    all.pop_back();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rn = inv(n);
    const int r2 = inv(2);
    for (int sum = 1; sum <= n + 2; ++sum) {
        for (int a = 0; a <= sum; ++a) {
            const int b = sum - a;
            if (a == 0) {
                dp[a][b] = 1;
            } else if (b == 0) {
                dp[a][b] = 0;
            } else {
                dp[a][b] = mul(r2, dp[a - 1][b]);
                inc(dp[a][b], mul(r2, dp[a][b - 1]));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        calc_sz(i, -1);
        dfs(i, -1);
    }
    printf("%d\n", ans);
    return 0;
}