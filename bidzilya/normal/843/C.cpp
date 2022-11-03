#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

int n;
vector<vector<int>> g;

vector<int> sizes;

struct TResult {
    int X;
    int Y1;
    int Y2;

    explicit TResult(int x = 0, int y1 = 0, int y2 = 0)
        : X(x)
        , Y1(y1)
        , Y2(y2)
    {
    }
};

vector<TResult> result;

void BuildSizes(int v, int pr) {
    sizes[v] = 1;
    for (int u : g[v]) {
        if (u != pr) {
            BuildSizes(u, v);
            sizes[v] += sizes[u];
        }
    }
}

void RebuildFromRoot(int v, int pr, int centroid, int root, int& curRoot) {
    for (int u : g[v]) {
        if (u != pr) {
            RebuildFromRoot(u, v, centroid, root, curRoot);
        }
    }
    if (v != root) {
        result.emplace_back(
            centroid, curRoot, v
        );
        curRoot = v;
        result.emplace_back(
            v, pr, root
        );
    }
}

void RebuildFromCentroid(int centroid, int otherCentroid) {
    for (int root : g[centroid]) {
        if (root != otherCentroid) {
            int curRoot = root;
            RebuildFromRoot(root, centroid, centroid, root, curRoot);
            if (curRoot != root) {
                result.emplace_back(
                    centroid, curRoot, root
                );
            }
        }
    }
}

void FindCentroidsAndRebuild(int v, int pr) {
    bool onlyOne = true;
    if (pr != -1) {
        onlyOne &= (n < 2 * sizes[v]);
    }
    for (int u : g[v]) {
        if (u != pr) {
            onlyOne &= (2 * sizes[u] < n);
        }
    }
    if (onlyOne) {
        RebuildFromCentroid(v, -1);
        return;
    }
    for (int u : g[v]) {
        if (u != pr) {
            if (2 * sizes[u] == n) {
                RebuildFromCentroid(v, u);
                RebuildFromCentroid(u, v);
                return;
            }
            if (2 * sizes[u] > n) {
                FindCentroidsAndRebuild(u, v);
                return;
            }
        }
    }
    assert(false);
}

void Solve() {
    sizes.assign(n, 0);
    BuildSizes(0, -1);
    result.clear();
    FindCentroidsAndRebuild(0, -1);
    cout << result.size() << endl;
    for (const auto& r : result) {
        cout << r.X + 1 << " " << r.Y1 + 1 << " " << r.Y2 + 1 << '\n';
    }
    cout.flush();
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    g.clear();
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
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