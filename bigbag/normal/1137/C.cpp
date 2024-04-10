#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int max_d = 55;

int n, m, d, comp, used[max_n], eu[max_n], ev[max_n], root[max_n], dp[max_n][max_d];
char s[max_n][max_d], can[max_n][max_d];
bitset<max_d> b1, b2;
vector<int> g[max_n], rg[max_n], order, order2;
vector<pair<int, int>> nxt[max_n];

void dfs1(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs1(to);
        }
    }
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = comp;
    for (int to : rg[v]) {
        if (used[to] == -1) {
            dfs2(to);
        }
    }
}

void get_all_can() {
    queue<pair<int, int>> q;
    for (int i = 0; i < comp; ++i) {
        q.push({root[i], 0});
        can[root[i]][0] = 1;
    }
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int v = p.first, t = p.second;
        t = (t + 1) % d;
        for (int to : g[v]) {
            if (!can[to][t]) {
                can[to][t] = 1;
                q.push({to, t});
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &eu[i], &ev[i]);
        --eu[i];
        --ev[i];
        g[eu[i]].push_back(ev[i]);
        rg[ev[i]].push_back(eu[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    reverse(order.begin(), order.end());
    memset(used, -1, sizeof(used));
    for (int v : order) {
        if (used[v] == -1) {
            dfs2(v);
            root[comp] = v;
            ++comp;
        }
    }
    root[used[0]] = 0;
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        rg[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        if (used[eu[i]] == used[ev[i]]) {
            g[eu[i]].push_back(ev[i]);
        }
    }
    get_all_can();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            b1[j] = s[i][j] - '0';
            b2[j] = can[i][j];
        }
        for (int j = 0; j < d; ++j) {
            if ((b1 & b2).count()) {
                ++dp[used[i]][j];
            }
            b2 <<= 1;
            b2[0] = b2[d];
        }
    }

    for (int i = 0; i < m; ++i) {
        if (used[eu[i]] != used[ev[i]]) {
            int v = eu[i], to = used[ev[i]];
            for (int j = 0; j < d; ++j) {
                if (can[v][j]) {
                    nxt[used[v]].push_back({to, (j + 1) % d});
                }
            }
        }
    }
    for (int i = comp - 1; i >= 0; --i) {
        for (int st = 0; st < d; ++st) {
            int pl = 0;
            for (const pair<int, int> &to : nxt[i]) {
                pl = max(pl, dp[to.first][(st + to.second) % d]);
            }
            dp[i][st] += pl;
        }
    }
    printf("%d\n", dp[used[0]][0]);
    return 0;
}