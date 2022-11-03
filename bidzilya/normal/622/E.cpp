#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void FormDist(int v, const vector<vector<int>>& g, int curDist, vector<bool>& used, vector<int>& dist) {
    used[v] = true;
    bool isLeaf = true;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (used[u]) {
            continue;
        }
        isLeaf = false;
        FormDist(u, g, curDist + 1, used, dist);
    }
    if (isLeaf) {
        dist.push_back(curDist);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    vector<bool> used(n, false);
    used[0] = true;

    int result = 0;
    for (int i = 0; i < (int) g[0].size(); ++i) {
        vector<int> dist;
        FormDist(g[0][i], g, 0, used, dist);
        sort(dist.begin(), dist.end());
        reverse(dist.begin(), dist.end());
        int curResult = 0;
        for (int i = 0; i < (int) dist.size(); ++i) {
            curResult = max(curResult, dist[i] + i + 1);
        }
        result = max(result, curResult);
    }

    cout << result << endl;

    return 0;
}