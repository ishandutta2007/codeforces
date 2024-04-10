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

const int INF = 1e9;

struct TEdge {
    int From;
    int To;
    bool In;
};

template <typename TEdge>
vector<vector<int>> BuildG(const vector<TEdge>& edges, const int n) {
    vector<vector<int>> g(n);
    for (int i = 0; i < edges.size(); ++i) {
        g[edges[i].From].push_back(i);
    }
    return g;
}

template <typename TAcceptEdgeFunc, typename TEdge>
std::pair<vector<int>, bool> GetPath(
    int from, int to,
    TAcceptEdgeFunc&& accept,
    const vector<TEdge>& edges,
    const vector<vector<int>>& g)
{
    if (from == to) {
        return make_pair(vector<int>(), true);
    }
    const int n = g.size();
    vector<int> pr(n, -1);
    queue<int> q;
    q.push(from);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int eid : g[v]) {
            const auto& e = edges[eid];
            if (accept(eid)) {
                if (e.To != from && pr[e.To] == -1) {
                    pr[e.To] = eid;
                    q.push(e.To);
                }
            }
        }
    }
    if (pr[to] == -1) {
        return make_pair(vector<int>(), false);
    }
    vector<int> path;
    for (int i = pr[to]; i != -1; i = pr[edges[i].From]) {
        path.push_back(i);
    }
    return make_pair(path, true);
}

int n, m, s, t;
vector<TEdge> edges;

vector<int> GetMinCut() {
    struct TEdge {
        int From;
        int To;
        int Flow;
        int Cap;
    };
    vector<TEdge> flowEdges;
    flowEdges.reserve(2 * m);
    for (int i = 0; i < m; ++i) {
        flowEdges.push_back({
            edges[i].From,
            edges[i].To,
            0,
            (edges[i].In ? 1 : INF)
        });
        flowEdges.push_back({
            edges[i].To,
            edges[i].From,
            0,
            0
        });
    }
    for (int i = 0; i < m; ++i) {
        if (!edges[i].In) {
            continue;
        }
        flowEdges.push_back({
            edges[i].To,
            edges[i].From,
            0,
            INF
        });
        flowEdges.push_back({
            edges[i].From,
            edges[i].To,
            0,
            0
        });
    }
    const auto acceptNotSaturatedEdge = [&flowEdges] (const int eid) {
        return flowEdges[eid].Flow < flowEdges[eid].Cap;
    };
    const auto relax = [&flowEdges] (const vector<int>& path) {
        int value = INF;
        for (int eid : path) {
            value = min(value, flowEdges[eid].Cap - flowEdges[eid].Flow);
        }
        assert(value > 0);
        for (int eid : path) {
            flowEdges[eid].Flow += value;
            flowEdges[eid ^ 1].Flow -= value;
        }
    };
    const auto g = BuildG(flowEdges, n);
    while (true) {
        const auto pathResult = GetPath(s, t, acceptNotSaturatedEdge, flowEdges, g);
        if (!pathResult.second) {
            break;
        }
        relax(pathResult.first);
    }
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        const auto pathResult = GetPath(s, i, acceptNotSaturatedEdge, flowEdges, g);
        used[i] = pathResult.second;
    }
    vector<int> cut;
    for (int i = 0; i < 2 * m; ++i) {
        if (flowEdges[i].Flow > 0 && used[flowEdges[i].From] && !used[flowEdges[i].To]) {
            assert(flowEdges[i].Flow == flowEdges[i].Cap);
            cut.push_back(i >> 1);
        }
    }
    return cut;
}

void Solve() {
    const auto g = BuildG(edges, n);
    vector<int> flow(m, 0);
    const auto relax = [&flow] (const vector<int>& path, const int value) {
        assert(value > 0);
        for (int eid : path) {
            flow[eid] += value;
        }
    };
    for (int i = 0; i < m; ++i) {
        if (!edges[i].In) {
            continue;
        }
        {
            const auto pathResult = GetPath(
                edges[i].To,
                edges[i].From,
                [i] (int eid) {
                    return eid != i && edges[eid].In;
                },
                edges,
                g
            );
            if (pathResult.second) {
                const auto& path = pathResult.first;
                relax(path, 1);
                relax({i}, 1);
                continue;
            }
        }
        {
            const auto pathFromSResult = GetPath(
                s,
                edges[i].From,
                [] (int eid) {
                    return edges[eid].In;
                },
                edges,
                g
            );
            const auto pathToTResult = GetPath(
                edges[i].To,
                t,
                [] (int eid) {
                    return edges[eid].In;
                },
                edges,
                g
            );
            assert(pathFromSResult.second && pathToTResult.second);
            relax(pathFromSResult.first, 1);
            relax(pathToTResult.first, 1);
            relax({i}, 1);
        }
    }
    vector<int> cap;
    cap.assign(m, INF);
    const auto cut = GetMinCut();
    for (int eid : cut) {
        assert(edges[eid].In);
        cap[eid] = flow[eid];
        assert(flow[eid] > 0);
    }
    cout << cut.size() << '\n';
    for (int i = 0; i < m; ++i) {
        cout << flow[i] << " " << cap[i] << '\n';
    }
    cout.flush();
}

bool Read() {
    if (!(cin >> n >> m >> s >> t)) {
        return false;
    }
    --s;
    --t;
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].From >> edges[i].To >> edges[i].In;
        --edges[i].From;
        --edges[i].To;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}