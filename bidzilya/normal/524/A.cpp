#include <bits/stdc++.h>
using namespace std;

map<int, int> v_to_id;
vector<int> id_to_v;
int m, k, n;
vector<vector<int> > g;
vector<int> v1, v2;

void AddV(int v)
{
    if (v_to_id.find(v) == v_to_id.end()) {
        id_to_v.push_back(v);
        v_to_id[v] = n;
        ++n;
    }
}

int main()
{
    scanf("%d%d", &m, &k);
    n = 0;

    v1.resize(m);
    v2.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> v1[i] >> v2[i];
        AddV(v1[i]);
        AddV(v2[i]);
    }

    g.assign(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        v1[i] = v_to_id[v1[i]];
        v2[i] = v_to_id[v2[i]];
        g[v1[i]][v2[i]] = g[v2[i]][v1[i]] = 1;
    }
    vector<int> all(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] && i != j) {
                ++all[i];
            }
        }
    }
    for (map<int, int>::iterator itr = v_to_id.begin(); itr != v_to_id.end(); ++itr) {
        printf("%d: ", (*itr).first);
        int v = (*itr).second;
        vector<int> ans;
        for (int u = 0; u < n; ++u) {
            if (u != v && !g[v][u]) {
                int t = 0;
                for (int w = 0; w < n; ++w) {
                    if (g[v][w] && g[u][w]) {
                        ++t;
                    }
                }
                if (100 * t >= all[v] * k) {
                    ans.push_back(id_to_v[u]);
                }
            }
        }
        sort(ans.begin(), ans.end());
        printf("%d", ans.size());
        for (int i = 0; i < (int) ans.size(); ++i) {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }

    return 0;
}