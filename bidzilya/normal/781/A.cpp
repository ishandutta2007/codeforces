#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int n;
vector<vector<int>> g;

vector<int> color;

void Build(int v, int pr) {
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }

        int last = -1;
        for (int w : g[u]) {
            if (w == v) {
                continue;
            }

            ++last;
            while (last == color[u] || last == color[v]) {
                ++last;
            }

            color[w] = last;
        }
    }
    for (int u : g[v]) {
        if (u != pr) {
            Build(u, v);
        }
    }
}

void Solve() {
    int colorsCount = 0;
    for (int i = 0; i < n; ++i) {
        colorsCount = max(colorsCount, 1 + (int) g[i].size());
    }
    color.resize(n);
    {
        color[0] = 0;
        int last = 0;
        for (int i : g[0]) {
            color[i] = ++last;
        }
    }
    Build(0, -1);
    cout << colorsCount << endl;
    for (int i = 0; i < n; ++i) {
        cout << color[i] + 1 << " ";
    }
    cout << endl;
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