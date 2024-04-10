#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, m, dis[N][N];
vector<int> e[N];

void bfs(int *dis, int s) {
    dis[s] = 0;
    queue<int> que;
    que.push(s);
    
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto v : e[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    memset(dis, -1, sizeof dis);
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    
    vector<int> x(m), y(m), z(m);
    for (int i = 0; i < m; ++i) {
        cin >> x[i] >> y[i] >> z[i];  
        e[x[i]].push_back(y[i]);
        e[y[i]].push_back(x[i]);
    }

    for (int s = 1; s <= n; ++s) {
        bfs(dis[s], s);
    }

    long long ans = 1e18;
    for (int i = 0; i < m; ++i) {
        int l = min(dis[1][x[i]] + dis[n][y[i]], dis[n][x[i]] + dis[1][y[i]]) + 1;
        for (int s = 1; s <= n; ++s) {
            l = min(l, min(dis[s][x[i]], dis[s][y[i]]) + dis[s][1] + dis[s][n] + 2);
        }
        ans = min(ans, 1ll * l * z[i]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}