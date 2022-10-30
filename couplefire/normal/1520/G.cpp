#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
ll w;
vector<vector<ll>> values;
ll direct, inf = 1e18;
vector<int> stepX{-1, 0, 1, 0}, stepY{0, -1, 0, 1};

ll bfs(int x, int y) {
    vector<vector<ll>> dist(n, vector<ll> (m, inf));
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    ll mn = inf;
    if (values[x][y] != 0) mn = values[x][y];
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int vx = ux + stepX[i], vy = uy + stepY[i];
            if (vx >= 0 && vy >= 0 && vx < n && vy < m && dist[vx][vy] == inf && values[vx][vy] != -1) {
                dist[vx][vy] = dist[ux][uy] + w;
                if (values[vx][vy] != 0) {
                    mn = min(mn, dist[vx][vy] + values[vx][vy]);
                }
                q.push({vx, vy});
            }
        }
    }
    if (x == 0 && y == 0) {
        direct = dist[n - 1][m - 1];
    }
    return mn;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> w;
    values.resize(n, vector<ll> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> values[i][j];
        }
    }
    ll firstPortal = bfs(0, 0), secondPortal = bfs(n - 1, m - 1);
    ll ans = min(direct, firstPortal + secondPortal);
    cout << (ans == inf ? -1 : ans);
}