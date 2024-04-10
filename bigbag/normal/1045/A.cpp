#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 5055, inf = 1000111222;

const int max_v = 5 * max_n;

struct edge {
    int to, residual_capacity;

    edge(int to, int residual_capacity): to(to), residual_capacity(residual_capacity) {
    }
};

vector<edge> edges;
vector<int> g[max_v];

void add_edge(int u, int v, int f) {
    g[u].push_back(edges.size());
    edges.push_back({v, f});
    g[v].push_back(edges.size());
    edges.push_back({u, 0});
}

int h[max_v], num[max_v];

bool bfs(int s, int t) {
    for (int i = 0; i <= t; ++i) {
        h[i] = -1;
    }
    queue<int> q;
    q.push(s);
    h[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int id : g[v]) {
            if (edges[id].residual_capacity && h[edges[id].to] == -1) {
                h[edges[id].to] = h[v] + 1;
                q.push(edges[id].to);
            }
        }
    }
    return h[t] != -1;
}

bool dfs(int v, int t) {
    if (v == t) {
        return true;
    }
    for (int &i = num[v]; i < g[v].size(); ++i) {
        const int id = g[v][i];
        if (edges[id].residual_capacity && h[edges[id].to] == h[v] + 1 && dfs(edges[id].to, t)) {
            edges[id].residual_capacity -= 1;
            edges[id ^ 1].residual_capacity += 1;
            return true;
        }
    }
    return false;
}

int dinic(int s, int t) {
    int res = 0;
    while (bfs(s, t)) {
        for (int i = 0; i <= t; ++i) {
            num[i] = 0;
        }
        while (dfs(s, t)) {
            ++res;
        }
    }
    return res;
}

vector<int> path;

bool find_path(int v, int t) {
    if (v == t) {
        path.push_back(t);
        return true;
    }
    for (int &i = num[v]; i < g[v].size(); ++i) {
        const int id = g[v][i];
        if (id % 2 == 0 && edges[id ^ 1].residual_capacity && find_path(edges[id].to, t)) {
            path.push_back(v);
            ++edges[id].residual_capacity;
            --edges[id ^ 1].residual_capacity;
            return true;
        }
    }
    return false;
}

int n, m;
int tp[max_n], l[max_n], r[max_n], num_ship[max_v];
vector<int> ids[max_n];
int s, t, rev[max_n];
vector<int> taken[max_n];

void build(int v, int l, int r) {
    if (l == r) {
        add_edge(v, t, 1);
        num_ship[v] = l;
        return;
    }
    int mid = (l + r) / 2;
    add_edge(v, 2 * v, inf);
    add_edge(v, 2 * v + 1, inf);
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
}

void rec(int v, int tl, int tr, int l, int r, int from) {
    if (tl == l && tr == r) {
        add_edge(from, v, 1);
        return;
    }
    int mid = (tl + tr) / 2;
    if (r <= mid) {
        rec(2 * v, tl, mid, l, r, from);
    } else if (l > mid) {
        rec(2 * v + 1, mid + 1, tr, l, r, from);
    } else {
        rec(2 * v, tl, mid, l, mid, from);
        rec(2 * v + 1, mid + 1, tr, mid + 1, r, from);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tp[i]);
        if (tp[i] == 0) {
            int k;
            scanf("%d", &k);
            ids[i].resize(k);
            for (int &x : ids[i]) {
                scanf("%d", &x);
            }
        } else if (tp[i] == 1) {
            scanf("%d%d", &l[i], &r[i]);
        } else {
            ids[i].resize(3);
            for (int &x : ids[i]) {
                scanf("%d", &x);
            }
        }
    }
    const int sd = 4 * m + 5;
    s = sd + n;
    t = s + 1;
    build(1, 1, m);
    for (int i = 0; i < n; ++i) {
        if (tp[i] == 2) {
            add_edge(s, sd + i, 2);
        } else {
            add_edge(s, sd + i, 1);
        }
        if (tp[i] == 1) {
            rec(1, 1, m, l[i], r[i], sd + i);
        } else {
            for (int id : ids[i]) {
                rec(1, 1, m, id, id, sd + i);
            }
        }
    }
    int ans = dinic(s, t);
    printf("%d\n", ans);
    memset(num, 0, sizeof(num));
    while (find_path(s, t)) {
        reverse(path.begin(), path.end());
        int a = path[1] - sd;
        int b = num_ship[path[path.size() - 2]];
        taken[a].push_back(b);
        rev[b] = a;
        path.clear();
    }
    for (int i = 0; i < n; ++i) {
        if (tp[i] == 2 && taken[i].size() == 1) {
            int x = ids[i][0];
            if (x == taken[i][0]) {
                x = ids[i][1];
            }
            taken[rev[x]].pop_back();
            rev[x] = i;
            taken[i].push_back(x);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int id : taken[i]) {
            printf("%d %d\n", i + 1, id);
        }
    }
    return 0;
}

/*
1 4
2 1
2 5
3 3

*/