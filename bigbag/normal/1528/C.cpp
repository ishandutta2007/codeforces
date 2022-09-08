/**
 *  created: 24/05/2021, 18:05:33
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int t, n, tin[max_n], tout[max_n], curt;
vector<int> g[2][max_n];

void dfs(int v) {
    tin[v] = ++curt;
    for (int to : g[1][v]) {
        dfs(to);
    }
    tout[v] = curt;
}

set<pair<int, int>> segm;
set<int> q;

int ans;

bool ok_segm(int l, int r) {
    auto it = q.lower_bound(l);
    return it == q.end() || *it > r;
}

void solve(int v) {
    pair<int, int> del{-1, -1};
    pair<int, int> add{-1, -1};
    if (ok_segm(tin[v], tout[v])) {
        auto it = segm.upper_bound({tin[v], inf});
        if (it != segm.begin()) {
            --it;
        }
        if (it != segm.end() && it->first <= tin[v] && tin[v] <= it->second) {
            del = *it;
            q.erase(it->first);
            segm.erase(it);
        }
        add = {tin[v], tout[v]};
        segm.insert({tin[v], tout[v]});
        q.insert(tin[v]);
    }
    ans = max(ans, (int) q.size());
    for (int to : g[0][v]) {
        solve(to);
    }
    if (add.first != -1) {
        segm.erase(add);
        q.erase(add.first);
    }
    if (del.first != -1) {
        segm.insert(del);
        q.insert(del.first);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < 2; ++i) {
            for (int v = 1; v < n; ++v) {
                int p;
                scanf("%d", &p);
                --p;
                g[i][p].push_back(v);
            }
        }
        curt = -1;
        dfs(0);

        ans = 0;
        q.clear();
        segm.clear();
        solve(0);

        printf("%d\n", ans);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j].clear();
            }
        }
    }
    return 0;
}