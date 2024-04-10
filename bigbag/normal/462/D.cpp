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

const int max_n = 111111, inf = 1000000007;

int n, col[max_n];
long long dp[max_n][2];
vector<int> g[max_n];

long long power(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power((a * a) % inf, b / 2);
    }
    return (a * power(a, b - 1)) % inf;
}

void dfs(int v, int p) {
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs(g[v][i], v);
        }
    }
    if (g[v].size() == 1 && v) {
        dp[v][0] = 1;
        dp[v][1] = 1;
        if (col[v] == 0) {
            dp[v][1] = 0;
        }
        return;
    }
    if (col[v] == 1) {
        dp[v][1] = 1;
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] != p) {
                dp[v][1] = (dp[v][1] * dp[g[v][i]][0]) % inf;
            }
        }
    } else {
        vector<long long> a, b;
        int f = 0, poz;
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] != p) {
                a.push_back(dp[g[v][i]][0]);
                b.push_back(dp[g[v][i]][1]);
            }
        }
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == 0) {
                ++f;
                poz = i;
            }
        }
        if (f >= 2) {
            dp[v][1] = 0;
        } else if (f == 1) {
            long long x = b[poz];
            for (int i = 0; i < poz; ++i) {
                if (g[v][i] != p) x = (x * a[i]) % inf;
            }
            for (int i = poz + 1; i < a.size(); ++i) {
                if (g[v][i] != p) x = (x * a[i]) % inf;
            }
            dp[v][1] = x;
        } else {
            long long x = 1;
            for (int i = 0; i < a.size(); ++i) {
                x = (x * a[i]) % inf;
            }
            dp[v][1] = 0;
            for (int i = 0; i < a.size(); ++i) {
                dp[v][1] = (dp[v][1] + ((x * power(a[i], inf - 2)) % inf * b[i]) % inf) % inf;
            }
        }
    }
    dp[v][0] = dp[v][1];
    if (col[v] == 0) {
        long long x = 1;
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] != p) {
                x = (x * dp[g[v][i]][0]) % inf;
            }
        }
        dp[v][0] = (dp[v][0] + x) % inf;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int p;
        scanf("%d", &p);
        g[i].push_back(p);
        g[p].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &col[i]);
    }
    dfs(0, -1);
    printf("%d\n", dp[0][1] % inf);
    return 0;
}