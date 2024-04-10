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

const int max_n = 55, max_m = 555, inf = 1111111;

int n, m, X, a[max_n][max_n], b[max_n][max_n], used[max_n];
int u[max_m], v[max_m], c[max_m];

bool dfs(int v, int f, int x) {
    if (v == f) {
        return true;
    }
    if (used[v]) {
        return false;
    }
    used[v] = 1;
    for (int i = 1; i <= n; ++i) {
        if (b[v][i] + x <= a[v][i] && dfs(i, f, x)) {
            b[v][i] += x;
            b[i][v] -= x;
            return true;
        }
    }
    return false;
}

bool check(long double x) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 0; i < m; ++i) {
        int q = min((long double) inf, c[i] / x);
        a[u[i]][v[i]] += q;
    }
    int q = inf, res = 0;
    while (q) {
        while (dfs(1, n, q)) {
            memset(used, 0, sizeof(used));
            res += q;
            if (res >= X) {
                return true;
            }
        }
        memset(used, 0, sizeof(used));
        q /= 2;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &X);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u[i], &v[i], &c[i]);
    }
    long double l = 0, r = inf;
    for (int i = 0; i < 111; ++i) {
        long double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.10f\n", (double) (l * X));
    return 0;
}