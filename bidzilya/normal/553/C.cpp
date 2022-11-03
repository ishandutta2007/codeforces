#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;

int n;
vector<vector<pair<int, int> > > g;
vector<bool> used;
vector<int> cmp;
vector<int> id;
vector<int> start;
int cmps;

void DFS(int v, int cl)
{
    cmp[v] = cmps - 1;
    used[v] = true;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i].first;
        if (!used[u]) {
            id[u] = g[v][i].second ^ cl;
            DFS(u, cl ^ (1 - g[v][i].second));
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        --v1;
        --v2;
        g[v1].push_back(make_pair(v2, c));
        g[v2].push_back(make_pair(v1, c));
    }

    cmps = 0;
    used.assign(n, false);
    cmp.resize(n);
    id.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++cmps;
            start.push_back(i);
            DFS(i, 0);
        }
    }

    for (int v = 0; v < n; ++v) {
        if (v == start[cmp[v]]) {
            continue;
        }
        for (int i = 0; i < (int) g[v].size(); ++i) {
            int u = g[v][i].first;

            if (u == start[cmp[v]]) {
                if (id[v] != g[v][i].second) {
                    cout << 0 << endl;
                    return 0;
                }
            } else {
                if ((id[v] == id[u] && g[v][i].second != 1) ||
                        (id[v] != id[u] && g[v][i].second != 0)) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }

    int res = 1;
    for (int i = 0; i + 1 < cmps; ++i) {
        res += res;
        if (res >= kMod) {
            res -= kMod;
        }
    }

    cout << res << endl;

    return 0;
}