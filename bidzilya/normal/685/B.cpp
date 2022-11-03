#include <vector>
#include <iostream>
#include <string>
using namespace std;

const int MAX_LOG = 20;

int n;
vector<vector<int>> g;
vector<int> tin;
vector<int> tout;
vector<vector<int>> up;
vector<int> vertCount;
vector<int> par;
int curTime;

void Dfs(int v, int pr) {
    up[v].resize(MAX_LOG);
    if (pr == -1) {
        for (int i = 0; i < MAX_LOG; ++i) {
            up[v][i] = v;
        }
    } else {
        up[v][0] = pr;
        for (int i = 1; i < MAX_LOG; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
    }
    vertCount[v] = 1;
    tin[v] = curTime++;
    for (int u : g[v]) {
        Dfs(u, v);
        vertCount[v] += vertCount[u];
    }
    tout[v] = curTime++;
}

inline bool IsParent(int vert, int par) {
    return tin[par] <= tin[vert] && tout[par] >= tout[vert];
}

vector<int> centroid;

void BuildCentroid(int v) {
    for (int u : g[v]) {
        BuildCentroid(u);
    }
    centroid[v] = v;
    for (int u : g[v]) {
        if (vertCount[u] * 2 > vertCount[v]) {
            centroid[v] = centroid[u];
            break;
        }
    }
    if (centroid[v] == v) {
        return;
    }

    int u = centroid[v];

    auto check = [&v] (int u) {
        int down = vertCount[u];
        int up = vertCount[v] - down;

        return up * 2 <= vertCount[v];
    };

    if (check(u)) {
        centroid[v] = u;
        return;
    }

    for (int i = MAX_LOG - 1; i >= 0; --i) {
        int nu = up[u][i];

        if (IsParent(nu, v) && !check(nu)) {
            u = nu;
        }
    }

    u = up[u][0];
    centroid[v] = u;
}

int main() {
    // freopen("input2.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int q;
    cin >> q;

    g.resize(n);
    par.resize(n);
    par[0] = -1;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i);
        par[i] = p;
    }

    tin.resize(n);
    tout.resize(n);
    up.resize(n);
    curTime = 0;
    vertCount.resize(n);
    Dfs(0, -1);

    centroid.resize(n);
    BuildCentroid(0);

    for (; q; --q) {
        int v;
        cin >> v;
        --v;

        cout << centroid[v] + 1 << '\n';
    }
    cout.flush();

    return 0;
}