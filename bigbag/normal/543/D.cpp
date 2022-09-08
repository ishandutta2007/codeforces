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

const int max_n = 222222, mod = 1000000007;

int n, dp[max_n], q[max_n], ans[max_n];
vector<int> g[max_n], dp2[max_n], dp3[max_n];

void dfs(int v, int p) {
    dp[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        dp2[v].push_back(1);
        dp3[v].push_back(1);
        if (g[v][i] == p) {
            continue;
        }
        dfs(g[v][i], v);
        dp[v] = (1LL * dp[v] * (1 + dp[g[v][i]])) % mod;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            if (i) {
                dp2[v][i] = (dp2[v][i - 1]) % mod;
            }
            continue;
        }
        if (i == 0) {
            dp2[v][i] = (dp[g[v][i]] + 1) % mod;
        } else {
            dp2[v][i] = (1LL * dp2[v][i - 1] * (1 + dp[g[v][i]])) % mod;
        }
    }
    for (int i = g[v].size() - 1; i >= 0; --i) {
        if (g[v][i] == p) {
            if (i + 1 < g[v].size()) {
                dp3[v][i] = (dp3[v][i + 1]) % mod;
            }
            continue;
        }
        if (i + 1 == g[v].size()) {
            dp3[v][i] = (dp[g[v][i]] + 1) % mod;
        } else {
            dp3[v][i] = (1LL * dp3[v][i + 1] * (1 + dp[g[v][i]])) % mod;
        }
    }
}

int get(int v, int num) {
    if (g[v].size() == 1) {
        return 1;
    }
    if (num == 0) {
        return dp3[v][1];
    }
    if (num + 1 == g[v].size()) {
        return dp2[v][g[v].size() - 2];
    }
    return (1LL * dp2[v][num - 1] * dp3[v][num + 1]) % mod;
}

void get_ans(int v, int p) {
    ans[v] = (1LL * dp[v] * q[v]) % mod;
    //cout << v << " " << q[v] << endl;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        int y = (1 + 1LL * q[v] * get(v, i)) % mod;
        //int y = (1 + 1LL * dp[v] * power(x, mod - 2)) % mod;
        q[g[v][i]] = (1LL * y) % mod;
        get_ans(g[v][i], v);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        int p;
        scanf("%d", &p);
        g[p].push_back(i);
        g[i].push_back(p);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        q[i] = 1;
    }
    get_ans(1, -1);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}