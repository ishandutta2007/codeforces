#include <bits/stdc++.h>
using namespace std;

const int N = 550000;
int a[N], b[N];
vector<int> adj[N];
bool vis[N];
int main() {
    ios::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) a[i] = i;
    int found = 0;
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
        if (adj[i].size() != n - 1) {
            vis[i] = 1;
            for (auto x: adj[i]) vis[x] = 1;
            for (int j = 1; j <= n; j++) if (!vis[j] && j != i) {
                a[i] = 1, a[j] = 2;
                b[i] = b[j] = 1;
                int cur = 2;
                for (int k = 1; k <= n; k++) if (k != i && k != j) {
                    a[k] = b[k] = ++cur;
                }
                found = 1;
                break;
            }
            break;
        }
    }
    if (!found) return puts("NO"), 0;
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
    for (int i = 1; i <= n; i++) printf("%d%c", b[i], " \n"[i == n]);
    return 0;
}