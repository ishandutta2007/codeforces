/**
 *  created: 05/01/2021, 17:31:10
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int t, n, m, ans[max_n], add[max_n];
vector<int> g[max_n], q;

void clr() {
    q.clear();
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}

bool solve() {
    for (int i = 0; i < n; ++i) {
        ans[i] = -1;
        add[i] = 0;
    }
    q.push_back(0);
    add[0] = 1;
    while (!q.empty()) {
        int v = q.back();
        q.pop_back();
        bool black = false;
        for (int to : g[v]) {
            black |= ans[to] == 1;
        }
        if (black) {
            ans[v] = 0;
        } else {
            ans[v] = 1;
        }
        for (int to : g[v]) {
            if (!add[to]) {
                add[to] = 1;
                q.push_back(to);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!add[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        while (m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (solve()) {
            puts("YES");
            vector<int> v;
            for (int i = 0; i < n; ++i) {
                if (ans[i] == 1) {
                    v.push_back(i);
                }
            }
            printf("%d\n", v.size());
            for (int x : v) {
                printf("%d ", x + 1);
            }
            puts("");
        } else {
            puts("NO");
        }
        clr();
    }
    return 0;
}