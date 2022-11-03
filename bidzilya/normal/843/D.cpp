#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

const long long INF = 1e18;

struct TEdge {
    int From;
    int To;
    int Weight;
};

struct TQuery {
    int Type;
    int Vertex;
    vector<int> Edges;
};

int n, m, q;
vector<TEdge> edges;
vector<vector<int>> g;
vector<TQuery> qs;

vector<long long> phi;

void Djkstra(const int start) {
    phi.assign(n, INF);
    phi[start] = 0;
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > q;
    q.push(make_pair(0, start));
    while (!q.empty()) {
        const auto dist = q.top().first;
        const auto v = q.top().second;
        q.pop();

        if (phi[v] < dist) {
            continue;
        }

        for (int eid : g[v]) {
            const auto& e = edges[eid];
            if (phi[e.From] + e.Weight < phi[e.To]) {
                phi[e.To] = phi[e.From] + e.Weight;
                q.push(make_pair(phi[e.To], e.To));
            }
        }
    }
}

static constexpr int BATCH_SIZE = 1000;

void UpdateDjkstra(const int start, const int lim) {
    static queue<int> q[BATCH_SIZE + 1];
    static vector<int> d;
    static constexpr int SMALL_INF = 1e9;
    d.assign(n, SMALL_INF);
    d[start] = 0;
    q[0].push(start);
    for (int i = 0; i <= lim; ++i) {
        while (!q[i].empty()) {
            const int v = q[i].front();
            q[i].pop();

            if (d[v] < i) {
                continue;
            }

            for (const int eid : g[v]) {
                const auto& e = edges[eid];
                const int dist = d[v] + e.Weight + phi[v] - phi[e.To];
                if (dist < d[e.To] && dist <= lim) {
                    d[e.To] = dist;
                    q[dist].push(e.To);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (d[i] != SMALL_INF) {
            phi[i] += d[i];
        }
    }
}

void Solve() {
    Djkstra(0);
    int edgesToUpdate = 0;
    for (int i = 0; i < q; ++i) {
        if (qs[i].Type == 1) {
            if (edgesToUpdate > 0) {
                UpdateDjkstra(0, edgesToUpdate);
                edgesToUpdate = 0;
            }
            const auto r = phi[qs[i].Vertex];
            if (r == INF) {
                printf("-1\n");
            } else {
                printf("%lld\n", r);
            }
        } else {
            for (int eid : qs[i].Edges) {
                ++edges[eid].Weight;
                ++edgesToUpdate;
                if (edgesToUpdate == BATCH_SIZE) {
                    UpdateDjkstra(0, edgesToUpdate);
                    edgesToUpdate = 0;
                }
            }
        }
    }
}

bool Read() {
    if (scanf("%d %d %d", &n, &m, &q) == EOF) {
        return false;
    }
    g.clear();
    g.resize(n);
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &edges[i].From, &edges[i].To, &edges[i].Weight);
        --edges[i].From;
        --edges[i].To;
        g[edges[i].From].push_back(i);
    }
    qs.clear();
    qs.resize(q);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &qs[i].Type);
        if (qs[i].Type == 1) {
            scanf("%d", &qs[i].Vertex);
            --qs[i].Vertex;
        } else {
            int s;
            scanf("%d", &s);
            qs[i].Edges.resize(s);
            for (int j = 0; j < s; ++j) {
                scanf("%d", &qs[i].Edges[j]);
                --qs[i].Edges[j];
            }
        }
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    while (Read()) {
        Solve();
    }

    return 0;
}