#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, c[MAXN], l[MAXN], r[MAXN];
vector<int> adj[MAXN];

bool vis[MAXN];
int cc;
void dfs(int v) {
    if (vis[v]) return;
    vis[v] = true;
    for (int u: adj[v])
        dfs(u);
}

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int sec[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te; cin >> te;
    while (te--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            adj[i].clear();

        for (int i = 0; i < n; i++)
            cin >> c[i] >> l[i] >> r[i];
        iota(sec, sec + n, 0);
        sort(sec, sec + n, [](int u, int v) {
                return r[u] < r[v];
                });

        deque<int> q[2];
        for (int i = 0; i < n; i++) {
            int v = sec[i];
            auto &other = q[!c[v]];
            int fs = -1;
            while (other.size() && r[other.back()] >= l[v]) {
                int u = other.back();
                if (fs == -1)
                    fs = u;
                add_edge(u, v);
                other.pop_back();
            }
            if (fs != -1)
                other.push_back(fs);
            q[c[v]].push_back(v);
        }

        fill(vis, vis + n, 0);
        cc = 0;
        for (int v = 0; v < n; v++)
            if (!vis[v])
                dfs(v), cc++;
        cout << cc << "\n";
    }
    return 0;
}