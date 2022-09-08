#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, k, dist[max_n];
string res;
vector<string> ans;
vector<int> g[max_n], num[max_n], ids[max_n];

void bfs() {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
            if (dist[to] == dist[v] + 1) {
                ids[to].push_back(num[v][i]);
            }
        }
    }
}

void write() {
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%s\n", ans[i].c_str());
    }
    exit(0);
}

void rec(int v) {
    if (v == n + 1) {
        ans.push_back(res);
        if (ans.size() == k) {
            write();
        }
        return;
    }
    for (int id : ids[v]) {
        res[id] = '1';
        rec(v + 1);
        res[id] = '0';
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        num[u].push_back(i);
        num[v].push_back(i);
    }
    bfs();
    for (int i = 0; i < m; ++i) {
        res += '0';
    }
    rec(2);
    write();
    return 0;
}