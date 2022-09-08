#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, inf = 1000111222;

int n, m, a[max_n];
int cur, last[max_n];
vector<int> all[max_n], ans;
vector<int> g[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        all[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int v : all[i]) {
            ans.push_back(v);
        }
    }
    for (int v : ans) {
        ++cur;
        for (int to : g[v]) {
            last[a[to]] = cur;
        }
        for (int i = 0; ; ++i) {
            if (last[i] != cur) {
                if (i != a[v]) {
                    puts("-1");
                    return 0;
                }
                break;
            }
        }
    }
    for (int v : ans) {
        printf("%d ", v + 1);
    }
    puts("");
    return 0;
}