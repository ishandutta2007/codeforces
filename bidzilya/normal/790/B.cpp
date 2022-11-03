#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

#define count count123123
#define distance distance123123

using TValue = array<long long, 5>;

int n, k;
vector<vector<int>> g;

vector<TValue> countDown;
vector<TValue> count;

vector<TValue> distanceDown;
vector<TValue> distance;

void Dfs(int v, int pr) {
    countDown[v].fill(0);
    countDown[v][0] = 1;
    count[v].fill(0);
    count[v][0] = 1;
    distanceDown[v].fill(0);
    distance[v].fill(0);
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }
        Dfs(u, v);
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                count[v][(i + j + 1) % k] += countDown[v][i] * countDown[u][j];
                distance[v][(i + j + 1) % k] += distanceDown[v][i] * countDown[u][j]
                    + (distanceDown[u][j] + countDown[u][j]) * countDown[v][i];
            }
        }
        for (int i = 0; i < k; ++i) {
            countDown[v][(i + 1) % k] += countDown[u][i];
            distanceDown[v][(i + 1) % k] += (distanceDown[u][i] + countDown[u][i]);
        }
    }
}

void Solve() {
    countDown.resize(n);
    count.resize(n);
    distanceDown.resize(n);
    distance.resize(n);
    Dfs(0, -1);
    long long result = 0;
    for (int v = 0; v < n; ++v) {
        result += distance[v][0] / k;
        for (int i = 1; i < k; ++i) {
            assert((distance[v][i] - count[v][i] * i) % k == 0);
            result += (distance[v][i] - count[v][i] * i) / k;
            result += count[v][i];
        }
    }
    cout << result << endl;
}

bool Read() {
    if (!(cin >> n >> k)) {
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