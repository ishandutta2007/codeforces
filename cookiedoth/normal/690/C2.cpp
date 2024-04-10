#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

void dfs(int u, int p, const vector<vector<int>>& g, vector<int>& h) {
    for (int v : g[u]) {
        if (v != p) {
            h[v] = h[u] + 1;
            dfs(v, u, g, h);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    assert(m == n - 1);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    vector<int> h(n);
    dfs(0, -1, g, h);
    int s = max_element(h.begin(), h.end()) - h.begin();
    h.assign(n, 0);
    dfs(s, -1, g, h);
    cout << *max_element(h.begin(), h.end()) << endl;
}