#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;

const int INF = 1e9;

class TFlowFinder {
public:
    TFlowFinder(const vector<int>& levelSizes, const pair<int, int>& start, const pair<int, int>& finish)
        : LevelSizes(levelSizes)
    {
        N = 0;
        for (int sz : levelSizes) {
            N += sz;
        }

        Head.assign(N, -1);

        for (int i = 1; i < (int) LevelSizes.size(); ++i) {
            LevelSizes[i] += LevelSizes[i - 1];
        }

        Start = GetVertex(start);
        Finish = GetVertex(finish);
    }

    void AddEdge(const pair<int, int>& v1, const pair<int, int>& v2, int cap) {
        AddEdge(GetVertex(v1), GetVertex(v2), cap);
    }

    int GetFlow() {
        int result = 0;
        while (Bfs()) {
            Ptr.resize(N);
            for (int i = 0; i < N; ++i) {
                Ptr[i] = Head[i];
            }
            while (true) {
                int curDfsFlow = Dfs(Start, INF);
                if (curDfsFlow == 0) {
                    break;
                } else {
                    result += curDfsFlow;
                }
            }
        }
        return result;
    }

private:
    struct TEdge {
        int From;
        int To;
        int Flow;
        int Cap;
        int Next;
    };

    int N;
    vector<int> LevelSizes;

    int Start;
    int Finish;

    vector<TEdge> Edges;
    vector<int> Head;

    vector<int> Ptr;

    vector<int> Dist;

    void AddEdge(int v1, int v2, int cap) {
        Edges.push_back(TEdge{v1, v2, 0, cap, Head[v1]});
        Head[v1] = (int) Edges.size() - 1;
        Edges.push_back(TEdge{v2, v1, 0, 0, Head[v2]});
        Head[v2] = (int) Edges.size() - 1;
    }

    inline int GetVertex(const pair<int, int>& v) {
        return (v.first == 0 ? 0 : LevelSizes[v.first - 1]) + v.second;
    }

    bool Bfs() {
        Dist.assign(N, INF);

        Dist[Start] = 0;

        queue<int> q;
        q.push(Start);
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int i = Head[v]; i != -1; i = Edges[i].Next) {
                const TEdge& e = Edges[i];

                if (Dist[e.To] == INF && e.Flow < e.Cap) {
                    Dist[e.To] = Dist[v] + 1;
                    q.push(e.To);
                }
            }
        }

        return Dist[Finish] < INF;
    }

    int Dfs(int v, int flow) {
        if (v == Finish) {
            return flow;
        }
        for (int& i = Ptr[v]; i != -1; i = Edges[i].Next) {
            const TEdge& e = Edges[i];

            if (Dist[e.To] == Dist[v] + 1 && e.Flow < e.Cap) {
                int resultFlow = Dfs(e.To, min(flow, e.Cap - e.Flow));

                if (resultFlow > 0) {
                    RelaxAlongEdge(i, resultFlow);
                    return resultFlow;
                }
            }
        }
        return 0;
    }

    void RelaxAlongEdge(int id, int flow) {
        Edges[id].Flow += flow;
        Edges[id ^ 1].Flow -= flow;
    }
};

struct TEdge {
    int From;
    int To;
    int Id;
    int Next;
};

int n;
vector<int> head;
vector<TEdge> edges;

vector<int> color;

vector<bool> inCycle;

void AddEdge(int v1, int v2, int id, int c) {
    color.push_back(c);
    edges.push_back(TEdge{v1, v2, id, head[v1]});
    head[v1] = (int) edges.size() - 1;
    edges.push_back(TEdge{v2, v1, id, head[v2]});
        head[v2] = (int) edges.size() - 1;
}

vector<vector<int>> cycles;

vector<int> used;

vector<int> pr;

void Dfs(int v) {
    used[v] = 1;
    for (int i = head[v]; i != -1; i = edges[i].Next) {
        const TEdge& e = edges[i];

        if (pr[v] != -1 && edges[pr[v]].Id == e.Id) {
            continue;
        }

        if (used[e.To] == 0) {
            pr[e.To] = i;
            Dfs(e.To);
        } else if (used[e.To] == 1) {
            cycles.push_back(vector<int>());
            int u = v;
            cycles.back().push_back(color[e.Id]);
            inCycle[e.Id] = true;
            while (u != e.To) {
                cycles.back().push_back(color[edges[pr[u]].Id]);
                inCycle[edges[pr[u]].Id] = true;
                u = edges[pr[u]].From;
            }
        }
    }
    used[v] = 2;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int m;
    scanf("%d%d", &n, &m);
    head.assign(n, -1);
    edges.reserve(2 * m);
    for (int i = 0; i < m; ++i) {
        int v1, v2, c;
        scanf("%d%d%d", &v1, &v2, &c);
        --v1;
        --v2;
        --c;
        AddEdge(v1, v2, i, c);
    }

    inCycle.assign(m, false);

    used.assign(n, 0);
    pr.assign(n, -1);
    Dfs(0);

    TFlowFinder ff({1, (int) cycles.size(), m, 1}, make_pair(0, 0), make_pair(3, 0));

    for (int cycleId = 0; cycleId < (int) cycles.size(); ++cycleId) {
        ff.AddEdge(make_pair(0, 0), make_pair(1, cycleId), (int) cycles[cycleId].size() - 1);

        for (int c : cycles[cycleId]) {
            ff.AddEdge(make_pair(1, cycleId), make_pair(2, c), 1);
        }
    }

    for (int i = 0; i < m; ++i) {
        if (!inCycle[i]) {
            const int c = color[i];

            ff.AddEdge(make_pair(0, 0), make_pair(2, c), 1);
        }
    }

    for (int c = 0; c < m; ++c) {
        ff.AddEdge(make_pair(2, c), make_pair(3, 0), 1);
    }

    printf("%d\n", ff.GetFlow());

    return 0;
}