/**
 *  created: 01/08/2021, 17:39:27
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, q, ans, a[max_n];
set<int> g[max_n];

void check(int v) {
    ans -= a[v];
    a[v] = g[v].empty() || *g[v].rbegin() < v;
    ans += a[v];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    ans = n;
    fill(a, a + n, 1);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].insert(v);
        g[v].insert(u);
        check(u);
        check(v);
    }
    scanf("%d", &q);
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 3) {
            printf("%d\n", ans);
        } else {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            if (tp == 1) {
                g[u].insert(v);
                g[v].insert(u);
            } else {
                g[u].erase(v);
                g[v].erase(u);
            }
            check(u);
            check(v);
        }
    }
    return 0;
}