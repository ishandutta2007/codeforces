#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 202222, inf = 1011111111;

int n, was, sz[max_n], p[max_n];
queue<int> q;
vector<int> g[max_n], all[max_n];

void dfs(int v, int pp) {
    //cout << v << " " << pp << endl;
    p[v] = pp;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != pp) {
            ++sz[v];
            dfs(g[v][i], v);
        }
    }
    if (sz[v] == 0) {
        q.push(v);
        all[v].push_back(0);
    }
}

int proc(int root) {
    //cout << "#" << root << endl;
    while (!q.empty()) {
        q.pop();
    }
    for (int i = 1; i <= n; ++i) {
        sz[i] = 0;
        all[i].clear();
    }
    dfs(root, -1);
    int last = 0;
    while (!q.empty()) {
        int v = q.front();
        //cout << v << endl;
        q.pop();
        sort(all[v].begin(), all[v].end());
        all[v].erase(unique(all[v].begin(), all[v].end()), all[v].end());
        if (all[v].size() == 2) {
            while (all[v].size() == 2 && all[v][0] % 2 == all[v][1] % 2) {
                int len = (all[v][1] - all[v][0]) / 2;
                all[v].pop_back();
                if (len) {
                    all[v].push_back(len);
                }
            }
        }
        if (v == root && all[v].size() == 2) {
            return all[v][0] + all[v][1];
        }
        if (all[v].size() > 2 || all[v].size() == 2) {// && all[v][0] % 2 != all[v][1] % 2)) {
            if (was) {
                printf("-1\n");
                exit(0);
            }
            was = 1;
            return proc(v);
        }
        if (v == root) {
            return all[v][0];
        }
        --sz[p[v]];
        if (sz[p[v]] == 0) {
            q.push(p[v]);
        }
        all[p[v]].push_back(all[v][0] + 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = proc(1);
    while (ans % 2 == 0) {
        ans /= 2;
    }
    printf("%d\n", ans);
    return 0;
}