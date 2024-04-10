#include <iostream>
#include <vector>
#include <iomanip>

#include <cstdio>
using namespace std;

const int MAX_LOG = 20;

int n;
vector<vector<int>> g;
vector<int> tin, tout;
int timer;
vector<int> downCount;
vector<int> upCount;
vector<vector<int>> up;

vector<long long> downDist;
vector<long long> upDist;

vector<int> distFromRoot;

bool IsAncestor(int ancestor, int vertex) {
    return tin[ancestor] <= tin[vertex] && tout[ancestor] >= tout[vertex];
}

int GetLCA(int v, int u) {
    if (IsAncestor(v, u)) {
        return v;
    }
    if (IsAncestor(u, v)) {
        return u;
    }
    for (int i = MAX_LOG - 1; i >= 0; --i) {
        if (!IsAncestor(up[v][i], u)) {
            v = up[v][i];
        }
    }
    return up[v][0];
}

inline int GetDist(int v, int u, int lca) {
    return distFromRoot[v] + distFromRoot[u] - 2 * distFromRoot[lca];
}

inline int GetDist(int v, int u) {
    return GetDist(v, u, GetLCA(v, u));
}

void DFS(int v, int p) {
    tin[v] = timer++;
    up[v].resize(MAX_LOG);
    if (p == -1) {
        for (int i = 0; i < MAX_LOG; ++i) {
            up[v][i] = v;
        }
        distFromRoot[v] = 0;
    } else {
        up[v][0] = p;
        for (int i = 1; i < MAX_LOG; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        distFromRoot[v] = distFromRoot[p] + 1;
    }
    downCount[v] = 1;
    downDist[v] = 0;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        DFS(u, v);
        downCount[v] += downCount[u];
        downDist[v] += downCount[u];
        downDist[v] += downDist[u];
    }
    upCount[v] = n - downCount[v] + 1;
    tout[v] = timer++;
}

void CalcUpDist(int v, int p) {
    if (p == -1) {
        upDist[v] = 0;
    } else {
        upDist[v] += (upCount[v] - 1);
        upDist[v] += upDist[p];
    }
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        upDist[u] += (downDist[v] - (downDist[u] + downCount[u]));
        CalcUpDist(u, v);
    }
}

double GetResult(int v, int u) {
    int g = GetLCA(v, u);
    if (g == u) {
        swap(v, u);
    }
    long long score = 0;
    if (g == v) {
        int w = u;
        for (int i = MAX_LOG - 1; i >= 0; --i) {
            if (!IsAncestor(up[w][i], v)) {
                w = up[w][i];
            }
        }
        int curUpCount = upCount[w] - 1;
        long long curUpDist = upDist[w] - curUpCount;
        score += 1LL * (GetDist(v, u, g) + 1) * downCount[u] * curUpCount;
        score += 1LL * downCount[u] * curUpDist;
        score += 1LL * curUpCount * downDist[u];
        return 1.0 * score / (1LL * downCount[u] * curUpCount);
    } else {
        score += 1LL * (GetDist(v, u, g) + 1) * downCount[v] * downCount[u];
        score += 1LL * downCount[v] * downDist[u];
        score += 1LL * downCount[u] * downDist[v];
        return 1.0 * score / (1LL * downCount[v] * downCount[u]);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    tin.resize(n);
    tout.resize(n);
    timer = 0;
    downCount.resize(n);
    upCount.resize(n);
    downDist.resize(n);
    upDist.resize(n);
    up.resize(n);
    distFromRoot.resize(n);
    DFS(0, -1);
    CalcUpDist(0, -1);
    /*
    for (int v = 0; v < n; ++v) {
        cout << v << ": " << endl;
        cout << "  tin = " << tin[v] << endl;
        cout << "  tout = " << tout[v] << endl;
        cout << "  downCount = " << downCount[v] << endl;
        cout << "  upCount = " << upCount[v] << endl;
        cout << "  downDist = " << downDist[v] << endl;
        cout << "  upDist = " << upDist[v] << endl;
        cout << "  distFromRoot = " << distFromRoot[v] << endl;
        cout << endl;
    }
    */
    cout << fixed << setprecision(15);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        cout << GetResult(v1, v2) << '\n';
    }
    cout.flush();

    return 0;
}