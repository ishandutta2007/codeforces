#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector<int> sz;
vector<vector<int>> g;
vector<double> result;
vector<int> pr;

void BuildSz(int v) {
    sz[v] = 1;
    for (int i : g[v]) {
        BuildSz(i);
        sz[v] += sz[i];
    }
}

void BuildResult(int v) {
    if (v == 0) {
        result[v] = 1.0;
    } else {
        int s = sz[pr[v]] - 1;

        result[v] = result[pr[v]] + 1.0 + 1.0 / 2.0 * (s - sz[v]);
    }

    for (int u : g[v]) {
        BuildResult(u);
    }
}

int main() {
    scanf("%d", &n);
    sz.resize(n);
    g.resize(n);
    pr.resize(n);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &pr[i]);
        --pr[i];
        g[pr[i]].push_back(i);
    }
    pr[0] = -1;

    BuildSz(0);

    result.resize(n);
    BuildResult(0);

    for (int i = 0; i < n; ++i) {
        printf("%.15lf ", result[i]);
    }
    printf("\n");

    return 0;
}