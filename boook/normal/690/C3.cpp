#include <bits/stdc++.h>
using namespace std;

#define maxn 200010

struct Set {
    int pa;
    int sz;
    int a, b;
}pa[maxn];

int findset(int x) {
    return pa[x].pa == x ? x : pa[x].pa = findset(pa[x].pa);
}

int p[maxn], depth[maxn], fa[maxn][25];
vector<int> G[maxn];

void dfs(int u) {
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa[u][0]) continue;
        fa[v][0] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    for(int i = 20; i >= 0; i--) {
        if(depth[fa[u][i]] >= depth[v]) {
            u = fa[u][i];
        }
    }

    if(u == v) return u;
    for(int i = 20; i >= 0; i--) {
        if(fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        scanf("%d", &p[i]);
        G[i].push_back(p[i]);
        G[p[i]].push_back(i);
    }

    depth[1] = 1;
    dfs(1);

    for(int i = 1; i < 21; i++) {
        for(int j = 1; j <= n; j++)
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
    }

    for(int i = 1; i <= n; i++) {
        pa[i].pa = i;
        pa[i].sz = 1;
        pa[i].a = i;
    }

    int best = 0;

    for(int i = 2; i <= n; i++) {
        int u = i, v = p[i];
        int x = findset(u), y = findset(v);
        vector<int> box;

        if(pa[x].sz == 1) box.push_back(pa[x].a);
        else {
            box.push_back(pa[x].a);
            box.push_back(pa[x].b);
        }

        if(pa[y].sz == 1) box.push_back(pa[y].a);
        else {
            box.push_back(pa[y].a);
            box.push_back(pa[y].b);
        }

        int ret = 0, node1, node2;
        for(int j = 0; j < box.size(); j++) {
            for(int i = 0; i < box.size(); i++) if(i != j) {
                if(dist(box[i], box[j]) > ret) {
                    ret = dist(box[i], box[j]);
                    node1 = box[i], node2 = box[j];
                }
            }
        }

        pa[y].pa = x;
        pa[x].sz += pa[y].sz;
        pa[x].a = node1, pa[x].b = node2;


        best = max(best, ret);

        if(i > 2) putchar(' ');
        printf("%d", best);
    }
    puts("");
    return 0;
}