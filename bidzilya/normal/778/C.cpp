#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

const int ALPH_SIZE = 26;

int n;
vector<vector<int>> g;

vector<int> depth, sz, decr;

void ClearVertex() {
    g.clear();
}

int GetVertex() {
    g.push_back(vector<int>(ALPH_SIZE, -1));
    return g.size() - 1;
}

vector<pair<int, int>> rollback;

void ClearRollback() {
    rollback.clear();
}

void Insert(int from, int to) {
    for (int i = 0; i < ALPH_SIZE; ++i) {
        if (g[from][i] != -1) {
            if (g[to][i] == -1) {
                g[to][i] = GetVertex();
                rollback.push_back(make_pair(to, i));
            }
            Insert(g[from][i], g[to][i]);
        }
    }
}

void DoRollback() {
    for (int i = 0; i < (int) rollback.size(); ++i) {
        const auto& p = rollback[i];
        g[p.first][p.second] = -1;
    }
    while (g.size() > n) {
        g.pop_back();
    }
}

void Dfs(int v, int pr) {
    if (pr == -1) {
        depth[v] = 0;
    } else {
        depth[v] = depth[pr] + 1;
    }
    sz[v] = 1;
    for (int i = 0; i < ALPH_SIZE; ++i) {
        if (g[v][i] != -1) {
            Dfs(g[v][i], v);
            sz[v] += sz[g[v][i]];
        }
    }
    int maxIdx = -1;
    for (int i = 0; i < ALPH_SIZE; ++i) {
        if (g[v][i] != -1 && (maxIdx == -1 || sz[g[v][i]] > sz[g[v][maxIdx]])) {
            maxIdx = i;
        }
    }
    if (maxIdx == -1) {
        decr[v] = 0;
        return;
    }
    ClearRollback();
    for (int i = 0; i < ALPH_SIZE; ++i) {
        if (g[v][i] != -1 && i != maxIdx) {
            Insert(g[v][i], g[v][maxIdx]);
        }
    }
    decr[v] = sz[v] - (sz[g[v][maxIdx]] + (int) rollback.size());
    DoRollback();
}

void Solve() {
    depth.resize(n);
    sz.resize(n);
    decr.resize(n);
    Dfs(0, -1);

    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[depth[i]] += decr[i];
    }

    int resultIdx = 0;
    for (int i = 1; i < n; ++i) {
        if (result[i] > result[resultIdx]) {
            resultIdx = i;
        }
    }

    cout << n - result[resultIdx] << endl;
    cout << resultIdx + 1 << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    ClearVertex();
    for (int i = 0; i < n; ++i) {
        GetVertex();
    }
    for (int i = 0; i + 1 < n; ++i) {
        int v, u;
        char c;
        cin >> v >> u >> c;
        --v;
        --u;
        g[v][c - 'a'] = u;
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