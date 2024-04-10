#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <iomanip>
using namespace std;

const int ITR = 100;
const int MAX_LOG = 20;

#define next next18293

const long long INF = 1e18;

struct TEdge {
    int From;
    int To;
    long long Cap;
    long long Flow;
    int Rev;
};

int n, x;
vector<int> head;
vector<TEdge> buf;
vector<TEdge> edges;
vector<int> data;
vector<int> next;

int GetNewEdge(const TEdge& edge) {
    edges.push_back(edge);
    buf.push_back(edge);
    return edges.size() - 1;
}

void Init() {
    head.assign(n, -1);
}

void AddEdge(int from, int to, int cap) {
    int fwd = GetNewEdge(TEdge{from, to, cap, 0, -1});
    int bckw = GetNewEdge(TEdge{to, from, 0, 0, -1});

    edges[fwd].Rev = bckw;
    edges[bckw].Rev = fwd;

    next.push_back(head[from]);
    head[from] = next.size() - 1;
    data.push_back(fwd);

    next.push_back(head[to]);
    head[to] = next.size() - 1;
    data.push_back(bckw);
}

long long RelaxAlongPath(const vector<int>& path) {
    long long flow = INF;
    for (int x : path) {
        flow = min(flow, edges[x].Cap - edges[x].Flow);
    }
    for (int x : path) {
        edges[x].Flow += flow;
        edges[edges[x].Rev].Flow -= flow;
    }
    return flow;
}

long long FindFlow(int th) {
    vector<int> pr(n, -1);
    vector<bool> used(n);
    queue<int> q;
    q.push(0);
    used[0] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = head[v]; i != -1; i = next[i]) {
            const TEdge& edge = edges[data[i]];

            if (edge.Flow + (1 << th) <= edge.Cap && !used[edge.To]) {
                pr[edge.To] = data[i];
                q.push(edge.To);
                used[edge.To] = true;
            }
        }
    }
    if (!used[n - 1]) {
        return 0;
    }
    vector<int> path;
    for (int i = n - 1; i > 0; i = edges[pr[i]].From) {
        path.push_back(pr[i]);
    }
    return RelaxAlongPath(path);
}

void BuildGraph(double w) {
    for (int i = 0; i < (int) edges.size(); ++i) {
        edges[i].Flow = 0;
        edges[i].Cap = buf[i].Cap / w;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        int m;
        cin >> n >> m >> x;

        Init();
        for (int i = 0; i < m; ++i) {
            int from, to, cap;
            cin >> from >> to >> cap;
            --from;
            --to;
            AddEdge(from, to, cap);
        }
    }

    double w = 0.0;
    double wl = 0.0;
    double wr = INF;
    for (int i = 0; i < ITR; ++i) {
        double wm = (wl + wr) / 2.0;

        BuildGraph(wm);

        long long flow = 0;
        for (int j = MAX_LOG - 1; j >= 0; --j) {
            while (true) {
                int add = FindFlow(j);
                if (add > 0) {
                    flow += add;
                } else {
                    break;
                }
            }
            if (flow >= x) {
                break;
            }
        }

        if (flow >= x) {
            w = wm;
            wl = wm;
        } else {
            wr = wm;
        }
    }

    cout << fixed << setprecision(15) << w * x << endl;

    return 0;
}