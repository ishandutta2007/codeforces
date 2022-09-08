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

const int max_n = 333333, inf = 1111111111;

int n, q, used[max_n], ans[max_n], sz[max_n], mx[max_n];
int c, num[max_n], p[max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    sz[v] = 1;
    mx[v] = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        dfs(g[v][i], v);
        sz[v] += sz[g[v][i]];
        mx[v] = max(mx[v], sz[g[v][i]]);
    }
}

int dfs2(int v, int p, int all) {
    if (max(mx[v], all - sz[v]) * 2 <= all) {
        return v;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p || used[g[v][i]]) {
            continue;
        }
        int res = dfs2(g[v][i], v, all);
        if (res != -1) {
            return res;
        }
    }
    return -1;
}

void rec(int v, int all) {
    int root = dfs2(v, -1, all);
    //cout << v << " " << root << " " << all << endl;
    vector<int> q;
    ++c;
    int R = root;
    while (true) {
        q.push_back(root);
        used[root] = 1;
        if (root == v) {
            break;
        }
        root = p[root];
    }
    reverse(q.begin(), q.end());
    root = q.back();
    //cout << v << " " << all << " root = " << root << endl;
    for (int i = 0; i < q.size(); ++i) {
        all = sz[q[i]];
        while (max(mx[root], all - sz[root]) * 2 > all) {
            //cout << "#" << endl;
            for (int j = 0; j < g[root].size(); ++j) {
                int to = g[root][j];
                //if (max(mx[to], all - sz[to]) <= all || all - sz[to] <= all)
                if ((all - sz[to]) * 2 <= all) {
                    root = to;
                    break;
                }
            }
        }
        ans[q[i]] = root;
        //cout << q[i] << " " << root << "   " << all << " " << mx[root] << " " << sz[root] << endl;
    }
    for (int j = 0; j < q.size(); ++j) {
        root = q[j];
        for (int i = 0; i < g[root].size(); ++i) {
            if (used[g[root][i]]) {
                continue;
            }
            rec(g[root][i], sz[g[root][i]]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &p[i]);
        g[p[i]].push_back(i);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        //cout << i << " " << sz[i] << " " << mx[i] << endl;
    }
    rec(1, n);
    /*for (int i = 1; i <= n; ++i) {
        printf("%d %d\n", i, ans[i]);
    }*/
    //return 0;
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}