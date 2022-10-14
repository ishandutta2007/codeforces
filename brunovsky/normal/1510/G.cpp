#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

int N, K;
vector<int> depth, parent, max_depth, subsize, path;
vector<vector<int>> children;

void prep_dfs(int u) {
    max_depth[u] = depth[u];
    subsize[u] = 1;
    for (int v : children[u]) {
        depth[v] = depth[u] + 1;
        prep_dfs(v);
        subsize[u] += subsize[v];
        max_depth[u] = max(max_depth[u], max_depth[v]);
    }
}

void dfs_path(int u, int can, vector<int>& subpath) {
    subpath.push_back(u), can--;
    for (int v : children[u]) {
        if (can == 0)
            break;
        int subcan = min(can, subsize[v]);
        dfs_path(v, subcan, subpath);
        subpath.push_back(u);
        can -= subcan;
    }
    assert(can == 0);
}

auto solve() {
    cin >> N >> K, K--;
    depth.assign(N + 1, 0);
    parent.assign(N + 1, 0);
    max_depth.assign(N + 1, 0);
    subsize.assign(N + 1, 0);
    children.assign(N + 1, {});
    path.clear();
    depth[1] = 0;
    for (int i = 2; i <= N; i++) {
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }
    prep_dfs(1);
    int deepest = *max_element(begin(max_depth) + 1, end(max_depth));
    path.push_back(1);
    int u = 1;
    while (K > 0 && !children[u].empty()) {
        for (int v : children[u]) {
            if (max_depth[v] == deepest) {
                path.push_back(v), K--, u = v;
                break;
            }
        }
    }
    if (K > 0) {
        int i = path.size() - 1;
        while (K > 0) {
            int u = path[i - 1], w = path[i];
            for (int v : children[u]) {
                if (v != w && K != 0) {
                    int can = min(K, subsize[v]);
                    vector<int> subpath;
                    dfs_path(v, can, subpath);
                    subpath.push_back(u);
                    path.insert(begin(path) + i, begin(subpath), end(subpath));
                    K -= can;
                }
            }
            i--;
        }
    }
    cout << path.size() - 1 << endl;
    for (int u : path) {
        cout << u << ' ';
    }
    cout << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}