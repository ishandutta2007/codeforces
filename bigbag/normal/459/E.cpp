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

const int max_n = 333333, inf = 1111111111;

struct edge {
    int u, v, c;
    void read() {
        scanf("%d%d%d", &u, &v, &c);
    }
    bool operator < (const edge &e) const {
        return c < e.c;
    }
};

int n, m, dp[max_n], kdp[max_n];
edge e[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        e[i].read();
    }
    sort(e, e + m);
    for (int i = 0; i < m;) {
        int poz = i;
        while (i < m && e[poz].c == e[i].c) {
            kdp[e[i].v] = max(kdp[e[i].v], dp[e[i].u] + 1);
            ++i;
        }
        for (int j = poz; j < i; ++j) {
            dp[e[j].v] = kdp[e[j].v];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}