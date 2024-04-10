#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct TEdge {
    int From;
    int To;
    int Id;
};

int n, m;
vector<vector<TEdge>> g;

vector<bool> goodVertex;
vector<int> degree;

vector<int> ptr;

vector<bool> usedEdge;

vector<pair<int, int>> edges;

inline int Get(int v) {
    while (ptr[v] < (int) g[v].size() && usedEdge[g[v][ptr[v]].Id]) {
        ++ptr[v];
    }
    return ptr[v];
}

void Dfs(int v, int start, bool rev) {
    if (v == start && !rev) {
        return;
    }

    if (Get(v) == (int) g[v].size()) {
        if (!rev) {
            int p = Get(start);

            usedEdge[g[start][p].Id] = true;
            edges[g[start][p].Id] = make_pair(g[start][p].To, g[start][p].From);
            Dfs(g[start][p].To, start, true);
        }
        return;
    }

    const TEdge& e = g[v][Get(v)];
    usedEdge[e.Id] = true;

    if (rev) {
        edges[e.Id] = make_pair(e.To, e.From);
    } else {
        edges[e.Id] = make_pair(e.From, e.To);
    }

    Dfs(e.To, start, rev);
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        cin >> n >> m;

        g.clear();
        g.resize(n);
        degree.assign(n, 0);
        for (int i = 0; i < m; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            --v1;
            --v2;
            g[v1].push_back(TEdge{v1, v2, i});
            g[v2].push_back(TEdge{v2, v1, i});
            ++degree[v1];
            ++degree[v2];
        }

        goodVertex.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (degree[i] & 1) {
                goodVertex[i] = true;
            }
        }

        usedEdge.assign(m, false);
        ptr.assign(n, 0);
        edges.resize(m);
        for (int i = 0; i < n; ++i) {
            if (!goodVertex[i]) {
                while (true) {
                    int p = Get(i);
                    if (p == (int) g[i].size()) {
                        break;
                    } else {
                        edges[g[i][p].Id] = make_pair(g[i][p].From, g[i][p].To);
                        usedEdge[g[i][p].Id] = true;
                        Dfs(g[i][p].To, i, false);
                    }
                }
            }
        }

        for (int v = 0; v < n; ++v) {
            for (const TEdge& e : g[v]) {
                if (!usedEdge[e.Id]) {
                    edges[e.Id] = make_pair(e.From, e.To);
                    usedEdge[e.Id] = true;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (!goodVertex[i]) {
                ++result;
            }
        }

        cout << result << '\n';
        for (int i = 0; i < m; ++i) {
            cout << edges[i].first + 1 << " " << edges[i].second + 1 << '\n';
        }
        cout.flush();
    }


    return 0;
}