#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int INF = 2e9;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2, l;
        scanf("%d%d%d", &v1, &v2, &l);
        --v1;
        --v2;
        g[v1].push_back(make_pair(v2, l));
        g[v2].push_back(make_pair(v1, l));
    }

    vector<bool> good(n, false);
    for (int i = 0; i < k; ++i) {
        int v;
        scanf("%d", &v);
        --v;
        good[v] = true;
    }

    int result = INF;
    for (int i = 0; i < n; ++i) {
        for (const pair<int, int>& p : g[i]) {
            if (good[i] && !good[p.first]) {
                result = min(result, p.second);
            }
        }
    }

    if (result == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}