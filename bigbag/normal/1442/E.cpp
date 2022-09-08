#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n];
int comps, num[max_n], num1[max_n];
vector<int> all[3], g[max_n];
vector<pair<int, int>> edges;

void clr() {
    edges.clear();
    all[0].clear();
    all[1].clear();
    all[2].clear();
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        num[i] = -1;
    }
}

void dfs(int v, int col) {
    num[v] = comps;
    for (int to : g[v]) {
        if (num[to] == -1 && (a[to] == col || a[to] == 0)) {
            dfs(to, col);
        }
    }
}

int find_comps(int col) {
    comps = 0;
    for (int v : all[0]) {
        num[v] = -1;
    }
    for (int v : all[col]) {
        if (num[v] == -1) {
            dfs(v, col);
            ++comps;
        }
    }
    return comps;
}

int h[max_n];

void dfs2(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        h[to] = h[v] + 1;
        dfs2(to, v);
    }
}

int find_furthest(int v, int n) {
    h[v] = 1;
    dfs2(v, -1);
    return max_element(h, h + n) - h;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        clr();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            all[a[i]].push_back(i);
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if (all[1].empty() || all[2].empty()) {
            puts("1");
            continue;
        }
        const int c1 = find_comps(1);
        copy(num, num + n, num1);
        const int c2 = find_comps(2);
        for (int v : all[1]) {
            for (int to : g[v]) {
                if (a[to] == 2) {
                    edges.push_back({num[v], c1 + num[to]});
                }
            }
        }
        for (int v : all[0]) {
            if (num[v] != -1 && num1[v] != -1) {
                edges.push_back({num1[v], c1 + num[v]});
            }
        }
        sort(edges.begin(), edges.end());
        edges.erase(unique(edges.begin(), edges.end()), edges.end());
        for (int i = 0; i < c1 + c2; ++i) {
            g[i].clear();
        }
        for (auto p : edges) {
            //cout << p.first << " -> " << p.second << endl;
            g[p.first].push_back(p.second);
            g[p.second].push_back(p.first);
        }
        //cout << "c1 = " << c1 << " " << c2 << endl;
        int v = find_furthest(0, c1 + c2);
        v = find_furthest(v, c1 + c2);
        int d = h[v];
        //cout << "$" << d << endl;
        int ans = d / 2 + 1;
        printf("%d\n", ans);
    }
    return 0;
}