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

const int max_n = 111111, inf = 1111111111;

int n, p[max_n], sz[max_n], dp[max_n];
long long ans;
vector<int> g[max_n], f[max_n];

bool ok(int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

void dfs(int v) {
    sz[v] = 1;
    dp[v] = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (sz[g[v][i]] == 0) {
            dfs(g[v][i]);
            p[g[v][i]] = v;
            sz[v] += sz[g[v][i]];
            if (f[v][i]) {
                dp[v] += sz[g[v][i]];
            } else {
                dp[v] += dp[g[v][i]];
            }
        }
    }
}

void get_ans(int v, int last) {
    long long x = n - sz[last];
    x += dp[last];
    //cout << v << " " << x << "  " << dp[v]<< endl;
    ans += x * (x - 1);
    for (int i = 0; i < g[v].size(); ++i) {
        if (p[v] != g[v][i]) {
            int nlast = last;
            if (f[v][i]) {
                nlast = g[v][i];
            }
            get_ans(g[v][i], nlast);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        d = ok(d);
        g[u].push_back(v);
        g[v].push_back(u);
        f[u].push_back(d);
        f[v].push_back(d);
    }
    dfs(1);
    get_ans(1, 1);
    cout << ans << endl;
    return 0;
}