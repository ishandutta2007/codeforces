#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

struct edge {
    int a, b, used;
};

const int mx = 1000000;
int n, m, deg[mx], base_v[mx], deg1[mx];
vector<edge> e;
vector<int> g[mx];
vector<vector<int> > cmp;
bool used[mx];

void add_edge(int u, int v) {
    g[u].push_back(e.size());
    g[v].push_back(e.size() + 1);
    e.push_back({u, v, 0});
    e.push_back({v, u, 0});
}

void cmp_dfs(int v) {
    used[v] = 1;
    cmp.back().push_back(v);
    for (auto id : g[v]) {
        int to = e[id].b;
        if (!used[to])
            cmp_dfs(to);
    }
}

void color(int v, int en, int pv) {
    used[v] = 1;
    for (auto id : g[v]) {
        int to = e[id].b;
        if (!used[to])
            color(to, id, v);
    }
    if (deg1[v] % 2 != deg[v] && en > -1) {
        e[en].used = 1;
        e[en^1].used = 1;
        deg1[v]++;
        deg1[pv]++;
    }
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < n; ++i) {
        cin >> deg[i];
        base_v[i] = -1;
        used[i] = 0;
        deg1[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        add_edge(u-1, v-1);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cmp.push_back(vector<int> ());
            cmp_dfs(i);
        }
    }
    int cn = cmp.size();
    for (int i = 0; i < cn; ++i) {
        int sum = 0;
        for (auto v : cmp[i]) {
            if (deg[v] == -1) {
                sum = 0;
                base_v[i] = v;
                break;
            }
            else
                sum += deg[v];
        }
        if (sum % 2 == 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        used[i] = 0;
        if (deg[i] == -1)
            deg[i] = 0;
    }
    for (int i = 0; i < cn; ++i) {
        if (base_v[i] == -1)
            color(cmp[i][0], -1, -1);
        else
            color(base_v[i], -1, -1);
    }
    int k = 0;
    for (int i = 0; i < m; ++i) {
        if (e[i*2].used == 1)
            k++;
    }
    cout << k << endl;
    for (int i = 0; i < m; ++i) {
        if (e[i*2].used == 1)
            cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}