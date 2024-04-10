#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011111, inf = 1111111111;

int n, m, a[max_n], ans[max_n], used[max_n], comp[max_n];
vector<int> g[max_n], g2[max_n], res;
pair<int, int> b[max_n];

int num(int x, int y) {
    return x * m + y;
}

void add_edge(int u, int v) {
    //cout << u << " -> " << v << endl;
    g[u].push_back(v);
}

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i]);
        }
    }
    res.push_back(v);
}

void dfs2(int v, int c) {
    comp[v] = c;
    for (int i = 0; i < g2[v].size(); ++i) {
        if (comp[g2[v][i]] == 0) {
            dfs2(g2[v][i], c);
        }
    }
}

int proc() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[j] = make_pair(a[num(i, j)], num(i, j));
        }
        sort(b, b + m);
        for (int j = 0; j < m; ) {
            int poz = j;
            while (j < m && b[poz].first == b[j].first) {
                g2[b[poz].second].push_back(b[j].second);
                g2[b[j].second].push_back(b[poz].second);
                ++j;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            b[j] = make_pair(a[num(j, i)], num(j, i));
        }
        sort(b, b + n);
        for (int j = 0; j < n; ) {
            int poz = j;
            while (j < n && b[poz].first == b[j].first) {
                g2[b[poz].second].push_back(b[j].second);
                g2[b[j].second].push_back(b[poz].second);
                ++j;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n * m; ++i) {
        if (comp[i] == 0) {
            ++cnt;
            dfs2(i, cnt);
        }
    }
    return cnt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[num(i, j)]);
        }
    }
    int C = proc();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[j] = make_pair(a[num(i, j)], num(i, j));
        }
        sort(b, b + m);
        int poz = 0;
        for (int j = 0; j < m; ++j) {
            while (poz < m && b[j].first >= b[poz].first) {
                ++poz;
            }
            if (poz < m) {
                add_edge(comp[b[j].second], comp[b[poz].second]);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            b[j] = make_pair(a[num(j, i)], num(j, i));
        }
        sort(b, b + n);
        int poz = 0;
        for (int j = 0; j < n; ++j) {
            while (poz < n && b[j].first >= b[poz].first) {
                ++poz;
            }
            if (poz < n) {
                add_edge(comp[b[j].second], comp[b[poz].second]);
            }
        }
    }
    for (int i = 1; i <= C; ++i) {
        if (used[i] == 0) {
            dfs(i);
        }
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < g[res[i]].size(); ++j) {
            ans[g[res[i]][j]] = max(ans[g[res[i]][j]], ans[res[i]] + 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", ans[comp[num(i, j)]] + 1);
        }
        printf("\n");
    }
    return 0;
}