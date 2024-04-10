#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, m, tp[max_n], has[max_n][2];
vector<int> g[max_n];

void clr() {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        tp[i] = 0;
        has[i][0] = 0;
        has[i][1] = 0;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        clr();
        while (m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            g[u].push_back(v);
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (has[i][1]) {
                tp[i] = 2;
            } else if (has[i][0]) {
                tp[i] = 1;
            }
            if (tp[i] == 2) {
                ans.push_back(i);
                continue;
            }
            for (int to : g[i]) {
                has[to][tp[i]] = 1;
            }
        }
        printf("%d\n", ans.size());
        for (int v : ans) {
            printf("%d ", v + 1);
        }
        puts("");
    }
    return 0;
}