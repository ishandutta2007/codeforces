#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

#include <cassert>
using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<int>> g;

unordered_set<long long> edgeIds;

long long GetEdgeId(int v, int u) {
    return 1LL * v * n + u;
}

bool HasEdge(int v, int u) {
    return edgeIds.find(GetEdgeId(v, u)) != edgeIds.end();
}

void Clear() {
    edgeIds.clear();
    g.clear();
    g.resize(n);
}

void AddEdge(int v, int u) {
    g[v].push_back(u);
    g[u].push_back(v);
    edgeIds.insert(GetEdgeId(v, u));
    edgeIds.insert(GetEdgeId(u, v));
}

vector<int> result;

void UpdateResult(vector<int> cur) {
    if (cur.empty()) {
        return;
    }
    if (result.empty() || cur.size() < result.size()) {
        result = std::move(cur);
    }
}

vector<int> CalcOpenedPath() {
    vector<int> dist(n, INF);
    dist[0] = 0;
    vector<int> pr(n, -1);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (dist[u] == INF) {
                dist[u] = dist[v] + 1;
                pr[u] = v;
                q.push(u);
            }
        }
    }
    if (dist[n - 1] == INF) {
        return {};
    }
    vector<int> path;
    for (int v = n - 1; v != -1; v = pr[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

vector<bool> GetOpened() {
    vector<bool> opened(n, false);
    for (int v : g[0]) {
        opened[v] = true;
    }
    return opened;
}

vector<int> CalcViaStartPath() {
    const auto opened = GetOpened();
    for (int v = 0; v < n; ++v) {
        for (int u : g[v]) {
            if (v == 0 || v == n - 1 || u == 0 || u == n - 1 || v == u) {
                continue;
            }
            if (opened[v] && !opened[u]) {
                return {0, v, u, 0, n - 1};
            }
        }
    }
    return {};
}

vector<int> cmp;
vector<vector<int>> cmpVs;
int cmpsCount;

void DfsCmp(int v, const vector<bool>& allowed) {
    cmp[v] = cmpsCount;
    cmpVs.back().push_back(v);
    for (int u : g[v]) {
        if (!allowed[u] || cmp[u] != -1) {
            continue;
        }
        DfsCmp(u, allowed);
    }
}

vector<bool> used;
vector<int> pr;

void DfsPath(int v, int p, const vector<bool>& allowed) {
    used[v] = true;
    pr[v] = p;
    for (int u : g[v]) {
        if (used[u] || !allowed[u]) {
            continue;
        }
        DfsPath(u, v, allowed);
    }
}

vector<int> BuildPath(int from, int to, const vector<bool>& allowed) {
    used.assign(n, false);
    pr.assign(n, -1);
    DfsPath(from, -1, allowed);
    vector<int> path;
    assert(used[to]);
    for (int v = to; v != -1; v = pr[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

vector<int> ShrinkPath(vector<int> path) {
    const auto v = path[0];
    while (true) {
        assert(path.size() >= 3);
        const auto w = path[path.size() - 2];
        if (HasEdge(v, w)) {
            return {0, v, w, path.back(), v, n - 1};
        }
        path.pop_back();
    }
    assert(false);
}

vector<int> CalcViaTrianglePath() {
    const auto opened = GetOpened();
    cmp.assign(n, -1);
    cmpVs.clear();
    cmpsCount = 0;
    for (int i = 0; i < n; ++i) {
        if (!opened[i] || cmp[i] != -1) {
            continue;
        }
        cmpVs.push_back(vector<int>());
        DfsCmp(i, opened);
        ++cmpsCount;
    }
    for (int c = 0; c < cmpsCount; ++c) {
        const auto& vs = cmpVs[c];
        for (int v : vs) {
            for (int u : vs) {
                if (v == u || HasEdge(v, u)) {
                    continue;
                }
                return ShrinkPath(BuildPath(v, u, opened));
            }
        }
    }
    return {};
}

void Solve() {
    result.clear();
    UpdateResult(CalcOpenedPath());
    UpdateResult(CalcViaStartPath());
    UpdateResult(CalcViaTrianglePath());
    if (result.empty()) {
        cout << -1 << endl;
    } else {
        cout << result.size() - 1 << endl;
        for (int x : result) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
}

bool Read() {
    if (!(cin >> n >> m)) {
        return false;
    }
    Clear();
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        AddEdge(v, u);
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}