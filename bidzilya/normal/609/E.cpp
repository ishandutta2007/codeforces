#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

struct TEdge {
    int From;
    int To;
    int Cost;
    int Index;
};

bool operator < (const TEdge& lhs, const TEdge& rhs) {
    return lhs.Cost < rhs.Cost;
}

struct TDsu {
    void Init(int n) {
        Parent.resize(n);
        Rank.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            Parent[i] = i;
        }
    }

    int GetParent(int v) {
        if (Parent[v] != v) {
            Parent[v] = GetParent(Parent[v]);
        }
        return Parent[v];
    }

    bool Unite(int v1, int v2) {
        v1 = GetParent(v1);
        v2 = GetParent(v2);

        if (v1 == v2) {
            return false;
        }

        if (Rank[v2] > Rank[v1]) {
            swap(v1, v2);
        }

        Parent[v2] = v1;
        if (Rank[v1] == Rank[v2]) {
            ++Rank[v1];
        }

        return true;
    }

    vector<int> Parent;
    vector<int> Rank;
};

const int MAX_LOG = 20;
const int MIN_W = 1;
const int MAX_W = 1e9;

long long glCost;

vector<vector<TEdge>> gIn;
vector<vector<TEdge>> gOut;

vector<int> tIn;
vector<int> tOut;
vector<vector<int>> upMax;
vector<vector<int>> up;
int timer;

vector<long long> result;

bool IsParent(int parent, int vertex) {
    return tIn[parent] <= tIn[vertex] && tOut[parent] >= tOut[vertex];
}

int GetLca(int v1, int v2) {
    if (IsParent(v1, v2)) {
        return v1;
    }
    if (IsParent(v2, v1)) {
        return v2;
    }
    for (int i = MAX_LOG - 1; i >= 0; --i) {
        if (!IsParent(up[v1][i], v2)) {
            v1 = up[v1][i];
        }
    }
    return up[v1][0];
}

int GetMaxCommon(int v1, int v2) {
    int result = MIN_W;
    for (int i = MAX_LOG - 1; i >= 0; --i) {
        if (!IsParent(up[v2][i], v1)) {
            result = max(result, upMax[v2][i]);
            v2 = up[v2][i];
        }
    }
    return max(result, upMax[v2][0]);
}

int GetMax(int v1, int v2) {
    if (IsParent(v1, v2)) {
        return GetMaxCommon(v1, v2);
    }
    if (IsParent(v2, v1)) {
        return GetMaxCommon(v2, v1);
    }
    int lca = GetLca(v1, v2);
    return max(GetMaxCommon(lca, v1), GetMaxCommon(lca, v2));
}

void BuildAdditionalInfo(int v, const TEdge& prEdge) {
    tIn[v] = timer++;
    up[v].resize(MAX_LOG);
    upMax[v].assign(MAX_LOG, MIN_W);
    if (prEdge.Index != -1) {
        up[v][0] = prEdge.From;
        for (int i = 1; i < MAX_LOG; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        upMax[v][0] = prEdge.Cost;
        for (int i = 1; i < MAX_LOG; ++i) {
            upMax[v][i] = max(upMax[v][i - 1], upMax[up[v][i - 1]][i - 1]);
        }
    }
    for (const TEdge& edge : gIn[v]) {
        if (edge.To != prEdge.From) {
            BuildAdditionalInfo(edge.To, edge);
        }
    }
    tOut[v] = timer++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<TEdge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].From >> edges[i].To >> edges[i].Cost;
        --edges[i].From;
        --edges[i].To;
        edges[i].Index = i;
    }
    sort(edges.begin(), edges.end());

    TDsu dsu;
    dsu.Init(n);

    gIn.resize(n);
    gOut.resize(n);

    glCost = 0;
    for (int i = 0; i < m; ++i) {
        vector<vector<TEdge>>* g;
        if (dsu.Unite(edges[i].From, edges[i].To)) {
            glCost += edges[i].Cost;
            g = &gIn;
        } else {
            g = &gOut;
        }
        g->operator [](edges[i].From).push_back(edges[i]);
        g->operator [](edges[i].To).push_back(TEdge{edges[i].To, edges[i].From, edges[i].Cost, edges[i].Index});
    }

    tIn.resize(n);
    tOut.resize(n);
    up.resize(n);
    upMax.resize(n);
    timer = 0;
    BuildAdditionalInfo(0, TEdge{-1, -1, MIN_W, -1});

    result.resize(m);
    for (int i = 0; i < n; ++i) {
        for (const TEdge& edge : gIn[i]) {
            result[edge.Index] = glCost;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (const TEdge& edge : gOut[i]) {
            result[edge.Index] = glCost + edge.Cost - GetMax(edge.From, edge.To);
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << result[i] << '\n';
    }
    cout.flush();

    return 0;
}