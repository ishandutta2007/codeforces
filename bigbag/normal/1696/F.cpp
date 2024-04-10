/**
 *  created: 25/06/2022, 18:54:48
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 105, inf = 1000111222;

int t, n, used[max_n], d[max_n][max_n];
bool f[max_n][max_n][max_n];
vector<int> g[max_n];
vector<pair<int, int>> edg;

void calc(int v, int p, int d, int dist[]) {
    dist[v] = d;
    for (int to : g[v]) {
        if (to != p) {
            calc(to, v, d + 1, dist);
        }
    }
}

bool check() {
    if (edg.size() + 1 != n) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        calc(i, -1, 0, d[i]);
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (f[k][i][j] != (d[k][i] == d[k][j])) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool dfs(int v, int p) {
    g[p].push_back(v);
    g[v].push_back(p);
    edg.push_back({p, v});
    used[v] = 1;
    for (int to = 0; to < n; ++to) {
        if (to == p) {
            continue;
        }
        if (f[v][p][to]) {
            if (used[to]) {
                return false;
            }
            if (!dfs(to, v)) {
                return false;
            }
        }
    }
    return true;
}

bool check(int root, int son) {
    if (root == son) {
        return false;
    }
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
    edg.clear();
    vector<int> sons;
    for (int i = 0; i < n; ++i) {
        if (f[root][son][i] && root != i) {
            sons.push_back(i);
        }
    }
    used[root] = 1;
    for (int son : sons) {
        if (!dfs(son, root)) {
            return false;
        }
    }
    return check();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        memset(f, 0, sizeof(f));
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                f[k][i][i] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string s;
                cin >> s;
                for (int k = 0; k < n; ++k) {
                    f[k][i][j] = s[k] - '0';
                    f[k][j][i] = s[k] - '0';
                }
            }
        }
        string ans = "No";
        for (int to = 1; to < n; ++to) {
            if (check(0, to)) {
                ans = "Yes";
                break;
            }
        }
        cout << ans << "\n";
        if (ans == "Yes") {
            for (auto [u, v] : edg) {
                cout << u + 1 << " " << v + 1 << "\n";
            }
        }
    }
    return 0;
}