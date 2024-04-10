#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;

int n, rt, fa[N];
vector<int> vec[N];
vector<pii> e[N];
vector<tuple<int, int, int>> ans;

void addEdge(int u, int v, int w) {
    e[u].emplace_back(make_pair(v, w));
}
void modifyPath(int u, int x) {
    if (vec[u].size() == 1u) {
        ans.emplace_back(rt, u, x);
        return;
    }
    int l1 = vec[u][0], l2 = vec[u][1];
    ans.emplace_back(rt, l1, x / 2);
    ans.emplace_back(rt, l2, x / 2);
    ans.emplace_back(l1, l2, -x / 2);
}
void modifyEdge(int u, int x) {
    if (fa[u] == rt) {
        modifyPath(u, x);
    } else {
        modifyPath(u, x);
        modifyPath(fa[u], -x);
    }
}
void dfs(int u, int p) {
    fa[u] = p;
    for (auto [v, w]: e[u]) {
        if (v == p) continue;
        dfs(v, u);
        vec[u].emplace_back(vec[v].front());
    }
    if (vec[u].size() == 0u) vec[u].emplace_back(u);
}
void solve(int u, int p) {
    for (auto [v, w]: e[u]) {
        if (v == p) continue;
        modifyEdge(v, w);
        solve(v, u);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w), addEdge(v, u, w);
    }
    for (int i = 1; i <= n; i++) {
        if (e[i].size() == 2u) {
            printf("NO\n");
            return 0;
        }
    }
    for (rt = 1; e[rt].size() != 1u; rt++);
    dfs(rt, 0);
    solve(rt, 0);
    printf("YES\n%d\n", (int)ans.size());
    for (auto x : ans) {
        printf("%d %d %d\n", get<0>(x), get<1>(x), get<2>(x));
    }
    return 0;
}