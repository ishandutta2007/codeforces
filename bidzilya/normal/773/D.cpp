#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long INF = 1e18;

int n;
vector<vector<long long>> cost;
vector<long long> result;

struct TEdge {
    long long Cost;
    int From;
    int To;
};

vector<int> changedVertexes;
vector<long long> bufferDist;
vector<int> lastUsedTime;
int curTime;

void ChangeBufferDist(int v, long long value) {
    if (lastUsedTime[v] != curTime) {
        lastUsedTime[v] = curTime;
        changedVertexes.push_back(v);
        bufferDist[v] = value;
    } else {
        bufferDist[v] = min(bufferDist[v], value);
    }
}

void BuildDist(const int start, const vector<TEdge>& edges, vector<long long>& dist) {
    dist.assign(n, INF);
    dist[start] = 0;
    curTime = 0;
    bufferDist.resize(n);
    lastUsedTime.assign(n, 0);
    changedVertexes.reserve(n);
    for (int i = 0; i < (int) edges.size(); ++i) {
        ++curTime;
        changedVertexes.clear();
        int j = i;
        while (j + 1 < (int) edges.size() && edges[j + 1].Cost == edges[i].Cost) {
            ++j;
        }
        for (int t = i; t <= j; ++t) {
            const TEdge& e = edges[t];
            const long long cost = e.Cost;
            const int from = e.From;
            const int to = e.To;
            if (dist[from] != INF) {
                ChangeBufferDist(to, dist[from] + cost);
            }
            ChangeBufferDist(to, 2 * cost);
            if (dist[to] != INF) {
                ChangeBufferDist(from, dist[to] + cost);
            }
            ChangeBufferDist(from, 2 * cost);
        }
        i = j;
        for (int v : changedVertexes) {
            dist[v] = min(dist[v], bufferDist[v]);
        }
    }
}

void Solve() {
    int minX = 0;
    int minY = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (cost[i][j] < cost[minX][minY]) {
                minX = i;
                minY = j;
            }
        }
    }
    result.resize(n);
    const long long minCost = cost[minX][minY];
    result[minX] = minCost * (n - 1);
    result[minY] = result[minX];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                cost[i][j] -= minCost;
            }
        }
    }
    vector<TEdge> edges;
    edges.reserve(n * (n - 1) / 2);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.push_back(TEdge{cost[i][j], i, j});
        }
    }
    sort(edges.begin(), edges.end(), [] (const TEdge& lhs, const TEdge& rhs) {
        return lhs.Cost < rhs.Cost;
    });
    vector<long long> dist[2];
    BuildDist(minX, edges, dist[0]);
    BuildDist(minY, edges, dist[1]);
    for (int i = 0; i < n; ++i) {
        if (i != minX && i != minY) {
            result[i] = minCost * (n - 1) + min(dist[0][i], dist[1][i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << result[i] << '\n';
    }
    cout.flush();
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    cost.clear();
    cost.resize(n);
    for (int i = 0; i < n; ++i) {
        cost[i].resize(n);
    }
    for (int i = 0; i < n; ++i) {
        cost[i][i] = 0;
        for (int j = i + 1; j < n; ++j) {
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
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