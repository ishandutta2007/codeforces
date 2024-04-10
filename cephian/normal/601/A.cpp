#include <iostream>
#include <queue>

using namespace std;

int n, m;
bool g[2][405][405];
int d[405];
const int INF = 0x7fffffff;

int bfs(int t) {
    queue<int> q;
    q.push(0);
    fill(d, d+n, INF);
    d[0] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int i = 0; i < n; ++i) {
            if(!g[t][v][i])
                continue;
            if(d[i] == INF) {
                d[i] = d[v] + 1;
                if(i == n-1)
                    return d[i];
                q.push(i);
            }
        }
    }
    return INF;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            g[0][i][j] = 0;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[0][--a][--b] = 1;
        g[0][b][a] = 1;
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            g[1][i][j] = !g[0][i][j] && (i != j);

    int ans = max(bfs(0), bfs(1));
    if(ans == INF) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}