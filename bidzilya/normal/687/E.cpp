#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

#include <cassert>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<vector<int>> rg;

vector<int> cmp;
int cmpCount;

vector<bool> used;

vector<vector<int>> cmpVerts;

vector<int> cmpId;

void BuildTopSort(int v, vector<int>& top) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u]) {
            BuildTopSort(u, top);
        }
    }
    top.push_back(v);
}

void BuildSCCDfs(int v) {
    cmp[v] = cmpCount;
    for (int u : rg[v]) {
        if (cmp[u] == -1) {
            BuildSCCDfs(u);
        }
    }
}

void BuildSCC() {
    used.assign(n, false);
    vector<int> top;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            BuildTopSort(i, top);
        }
    }
    reverse(top.begin(), top.end());
    cmp.assign(n, -1);
    cmpCount = 0;
    for (int i = 0; i < n; ++i) {
        int v = top[i];
        if (cmp[v] == -1) {
            BuildSCCDfs(v);
            ++cmpCount;
        }
    }
    cmpVerts.resize(cmpCount);
    for (int i = 0; i < n; ++i) {
        cmpVerts[cmp[i]].push_back(i);
    }
    cmpId.resize(n);
    for (int c = 0; c < cmpCount; ++c) {
        for (int i = 0; i < (int) cmpVerts[c].size(); ++i) {
            cmpId[cmpVerts[c][i]] = i;
        }
    }
}

const int INF = 1e9;

int GetMinCycleLength(const vector<int>& verts) {
    const int cn = verts.size();
    int result = INF;
    for (int sv : verts) {
        queue<int> q;
        vector<int> dist(cn, INF);
        dist[cmpId[sv]] = 0;
        q.push(sv);
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int u : g[v]) {
                int iv = cmpId[v];
                int iu = cmpId[u];

                if (dist[iu] == INF) {
                    dist[iu] = dist[iv] + 1;
                    q.push(u);
                }
            }
        }

        for (int u : rg[sv]) {
            if (cmp[u] != cmp[sv]) {
                continue;
            }
            int iu = cmpId[u];
            if (dist[iu] != INF) {
                result = min(result, dist[iu] + 1);
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    g.resize(n);
    rg.resize(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        rg[v2].push_back(v1);
    }

    BuildSCC();

    vector<int> out(cmpCount, 0);
    for (int v = 0; v < n; ++v) {
        for (int u : g[v]) {
            int cv = cmp[v];
            int cu = cmp[u];

            if (cv != cu) {
                ++out[cv];
            }
        }
    }

    int result = 0;
    for (int c = 0; c < cmpCount; ++c) {
        if (out[c] == 0) {
            int cycleLen = GetMinCycleLength(cmpVerts[c]);

            if (cycleLen != INF) {
                ++result;
                result += 998 * cycleLen;
            }
        }
    }

    result += n;

    cout << result << endl;

    return 0;
}