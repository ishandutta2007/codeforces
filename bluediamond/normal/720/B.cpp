/// Cactusophobia :>

#include <bits/stdc++.h>

using namespace std;

const int N = 10000 + 7;
int n;
int m;

struct Edge {
        int to;
        int id;
};

vector<Edge> g[N];
int dep[N];
int v[2 * N];
int col[2 * N];
int cur;
vector<int> edges;
int sz[N];
vector<int> colors[N];

void dfs(int a) {
        for (auto &it : g[a]) {
                int b = it.to;
                if (dep[b] == -1) {
                        dep[b] = 1 + dep[a];
                        edges.push_back(it.id);
                        dfs(b);
                        edges.pop_back();
                } else {
                        if (dep[b] < dep[a] - 1) {
                                cur++;
                                sz[cur]++;
                                col[it.id] = cur;
                                colors[cur].push_back(v[it.id]);
                                for (int j = 1; j <= dep[a] - dep[b]; j++) {
                                        col[edges[(int) edges.size() - j]] = cur;
                                        colors[cur].push_back(v[edges[(int) edges.size() - j]]);
                                        sz[cur]++;
                                }

                        }
                }
        }
}


class Dinic {
    struct Edge {
        int to, flow, next;
    };
    vector <Edge> edges;
    vector <int> adia, act, h;
    int S, D;

    bool bfs() {
        fill(h.begin(), h.end(), -1);
        h[S] = 0;
        vector <int> q = { S };

        for (int it = 0; it < (int)q.size(); it++) {
            int nod = q[it];
            for (int i = adia[nod]; i != -1; i = edges[i].next)
                if (h[edges[i].to] == -1 && edges[i].flow)
                    h[edges[i].to] = 1 + h[nod], q.push_back(edges[i].to);
        }

        return h[D] != -1;
    }

    int dfs(int nod, int cap_max) {
        if (cap_max == 0 || nod == D)
            return cap_max;

        while (act[nod] != -1) {
            Edge& e = edges[act[nod]];
            int d;
            if (h[e.to] == 1 + h[nod] && (d = dfs(e.to, min(cap_max, e.flow))) != 0) {
                e.flow -= d;
                edges[act[nod] ^ 1].flow += d;
                return d;
            }
            act[nod] = edges[act[nod]].next;
        }
        return 0;
    }

public:
    Dinic(int n, int S, int D) : adia(n + 1, -1), h(n + 1), S(S), D(D) { }

    int flow() {
        int ans = 0, d;
        while (bfs()) {
            act = adia;
            while ((d = dfs(S, 1e9)) != 0)
                ans += d;
        }
        return ans;
    }

    void add(int a, int b, int c) {
        edges.push_back({ b, c, (int)edges.size() });
        swap(edges.back().next, adia[a]);
        edges.push_back({ a, 0, (int)edges.size() });
        swap(edges.back().next, adia[b]);
    }
};


int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
                int x, y;
                cin >> x >> y >> v[i];
                g[x].push_back({y, i});
                g[y].push_back({x, i});
        }
        for (int i = 1; i <= n; i++) {
                dep[i] = -1;
        }
        dep[1] = 0;
        dfs(1);
        int init = cur;
        for (int i = 1; i <= m; i++) {
                if (col[i] == 0) {
                        col[i] = ++cur;
                        colors[cur].push_back(v[i]);
                }
        }
        Dinic d(2 + cur + m, 1, 2 + cur + m);
        for (int i = 1; i <= init; i++) {
                d.add(1, i + 1, sz[i] - 1);
        }
        for (int i = init + 1; i <= cur; i++) {
                d.add(1, i + 1, 1);
        }
        for (int i = 1; i <= cur; i++) {
                for (auto &j : colors[i]) {
                        d.add(i + 1, j + cur + 1, 1);
                }
        }
        for (int j = 1; j <= m; j++) {
                d.add(j + cur + 1, 2 + cur + m, 1);
        }
        cout << d.flow() << "\n";
}