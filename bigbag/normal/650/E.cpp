#include <bits/stdc++.h>

using namespace std;

const int max_n = 555555;

int n, ans, p[max_n], parent[max_n];
vector<int> g[max_n], all;
vector<pair<int, int> > a[max_n];
set<pair<int, int> > q, q2;

void dfs(int v, int pp) {
    p[v] = pp;
    all.push_back(v);
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != pp) {
            dfs(g[v][i], v);
        }
    }
}

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (a[v1].size() < a[v2].size()) {
        swap(v1, v2);
    }
    copy(a[v2].begin(), a[v2].end(), back_inserter(a[v1]));
    a[v2].clear();
    parent[v2] = v1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < n; ++j) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u > v) {
                swap(u, v);
            }
            if (i == 0) {
                q.insert(make_pair(u, v));
                g[u].push_back(v);
                g[v].push_back(u);
            } else {
                q2.insert(make_pair(u, v));
                if (!q.count(make_pair(u, v))) {
                    ++ans;
                    a[u].push_back(make_pair(u, v));
                    a[v].push_back(make_pair(u, v));
                }
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    dfs(1, -1);
    q.clear();
    for (int i = all.size() - 1; i > 0; --i) {
        int v1 = all[i];
        int v2 = p[v1];
        if (v1 > v2) {
            swap(v1, v2);
        }
        if (q2.count(make_pair(v1, v2))) {
            union_set(v1, v2);
        } else {
            int v = find_set(all[i]);
            pair<int, int> p;
            while (true) {
                p = a[v].back();
                a[v].pop_back();
                if (p.first > p.second) {
                    swap(p.first, p.second);
                }
                if (!q.count(p)) {
                    break;
                }
            }
            q.insert(p);
            printf("%d %d %d %d\n", v1, v2, p.first, p.second);
            union_set(p.first, p.second);
        }
    }
    return 0;
}