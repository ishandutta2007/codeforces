#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_v = 333;
const long long inf = 1000111222000LL;

struct edge {
    int to;
    long long res_cap;

    edge(int to, long long res_cap): to(to), res_cap(res_cap) {
    }
};

vector<edge> edges;
vector<int> g[max_v];

void add_edge(int u, int v, long long cap) {
    g[u].push_back(edges.size());
    edges.push_back({v, cap});
    g[v].push_back(edges.size());
    edges.push_back({u, 0});
}

int h[max_v], num[max_v];

bool bfs(int s, int t) {
    queue<int> q;
    for (int i = 0; i <= t; ++i) {
        h[i] = -1;
    }
    q.push(s);
    h[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int id : g[v]) {
            const edge &e = edges[id];
            if (e.res_cap && h[e.to] == -1) {
                h[e.to] = h[v] + 1;
                q.push(e.to);
            }
        }
    }
    return h[t] != -1;
}

long long dfs(int v, int t, long long f) {
    if (v == t) {
        return f;
    }
    for (int &i = num[v]; i < g[v].size(); ++i) {
        const int id = g[v][i];
        if (edges[id].res_cap && h[v] + 1 == h[edges[id].to]) {
            long long x = dfs(edges[id].to, t, min(f, edges[id].res_cap));
            if (x) {
                edges[id].res_cap -= x;
                edges[id ^ 1].res_cap += x;
                return x;
            }
        }
    }
    return 0;
}

long long dinic(int s, int t) {
    long long res = 0;
    while (bfs(s, t)) {
        memset(num, 0, sizeof(num));
        while (long long x = dfs(s, t, inf)) {
            res += x;
        }
    }
    return res;
}

const int max_n = 55;

struct segment {
    int l, r;

    segment(int l, int r): l(l), r(r) {
    }

    int len() const {
        return r - l + 1;
    }

    bool is_in(int ll, int rr) const {
        return ll <= l && r <= rr;
    }
};

struct rect {
    int lx, ly, rx, ry;

    void read() {
        cin >> lx >> ly >> rx >> ry;
    }
};

int m, n;
vector<int> xs, ys;
rect r[max_n];

vector<segment> get_segments(vector<int> &x) {
    vector<segment> res;
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i = 0; i + 1 < x.size(); ++i) {
        res.push_back({x[i], x[i + 1] - 1});
    }
    return res;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        r[i].read();
        xs.push_back(r[i].lx);
        xs.push_back(r[i].rx + 1);
        ys.push_back(r[i].ly);
        ys.push_back(r[i].ry + 1);
    }
    vector<segment> seg_x = get_segments(xs);
    vector<segment> seg_y = get_segments(ys);
    int s = n + seg_x.size() + seg_y.size();
    int t = s + 1;
    for (int i = 0; i < seg_y.size(); ++i) {
        add_edge(s, i, seg_y[i].len());
        for (int j = 0; j < n; ++j) {
            if (seg_y[i].is_in(r[j].ly, r[j].ry)) {
                add_edge(i, seg_y.size() + seg_x.size() + j, inf);
            }
        }
    }
    for (int i = 0; i < seg_x.size(); ++i) {
        const int num = seg_y.size() + i;
        add_edge(num, t, seg_x[i].len());
        for (int j = 0; j < n; ++j) {
            if (seg_x[i].is_in(r[j].lx, r[j].rx)) {
                add_edge(seg_y.size() + seg_x.size() + j, num, inf);
            }
        }
    }
    long long ans = dinic(s, t);
    cout << ans << endl;
    return 0;
}