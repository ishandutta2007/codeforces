#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int t, n, m, used[max_n], p[max_n], pid[max_n], sz[max_n], taken[max_n];
vector<int> id[max_n], g[max_n], leafs;

void clr() {
    for (int i = 1; i <= 3 * n; ++i) {
        g[i].clear();
        id[i].clear();
        used[i] = 0;
        p[i] = -1;
        sz[i] = 0;
        taken[i] = 0;
    }
    leafs.clear();
}

void dfs(int v) {
    //cout << "in " << v << endl;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        const int to = g[v][i];
        if (!used[to]) {
            p[to] = v;
            pid[to] = id[v][i];
            dfs(to);
            ++sz[v];
        }
    }
    //cout << v << ": " << sz[v] << endl;
    if (!sz[v]) {
        leafs.push_back(v);
    }
}

void del(int v) {
    --sz[p[v]];
    if (!sz[p[v]]) {
        leafs.push_back(p[v]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        clr();
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            id[u].push_back(i + 1);
            id[v].push_back(i + 1);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= 3 * n; ++i) {
            if (!used[i]) {
                dfs(i);
            }
        }
        if (leafs.size() >= n) {
            puts("IndSet");
            for (int i = 0; i < n; ++i) {
                printf("%d ", leafs[i]);
            }
            puts("");
            continue;
        }
        vector<int> ans;
        while (!leafs.empty() && ans.size() < n) {
            int v = leafs.back();
            //cout << "v = " << v << endl;
            leafs.pop_back();
            if (p[v] == -1) {
                continue;
            }
            del(v);
            if (taken[v]) {
                continue;
            }
            if (!taken[p[v]]) {
                taken[p[v]] = 1;
                taken[v] = 1;
                ans.push_back(pid[v]);
                //cout << "add " << p[v] << " " << v << endl;
                continue;
            }
        }
        if (ans.size() == n) {
            puts("Matching");
            for (int id : ans) {
                printf("%d ", id);
            }
            puts("");
        } else {
            puts("Impossible");
        }
    }
    return 0;
}