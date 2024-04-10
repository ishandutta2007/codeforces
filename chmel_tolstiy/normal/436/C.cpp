#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m, k, w;
char f[1024][12][12];

vector<pii> cost[100];

int p[1024];
int get(int x) {
    if (p[x] == x) return x;
    return p[x] = get(p[x]);
}

void unite(int a, int b) {
    p[get(a)] = b;
}

vector<int> g[1024];

int u[1024];

void dfs(int x, int p) {
    if (u[x]) return;
    u[x] = 1;
    
    if (p == -1) cout << x + 1 << ' ' << 0 << endl;
    else cout << x + 1 << ' ' << p + 1 << endl;
    
    for (int i = 0; i < g[x].size(); ++i) if (g[x][i] != p) dfs(g[x][i], x);
}

void solve() {
    cin >> n >> m >> k >> w;
    for (int i = 0; i < k; ++i) for (int r = 0; r < n; ++r) cin >> f[i][r];
    
    for (int i = 0; i < k; ++i) for (int j = i + 1; j < k; ++j) {
        int cs = 0; for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) cs += f[i][r][c] != f[j][r][c];
        if (cs * w < n * m) cost[cs * w].push_back(pii(i, j));
    }
    
    for (int i = 0; i < k; ++i) p[i] = i;
    
    int res = n * m * k;
    
    for (int cs = 0; cs < n * m; ++cs) {
        for (int i = 0; i < cost[cs].size(); ++i) {
            int x = cost[cs][i].first;
            int y = cost[cs][i].second;
            
            if (get(x) != get(y)) {
                g[x].push_back(y);
                g[y].push_back(x);
                unite(x, y);
                
                res -= n * m;
                res += cs;
            }
        }
    }
    
    cout << res << endl;
    for (int i = 0; i < k; ++i) if (u[i] == 0) dfs(i, -1);
}

int main() {
    solve();
    return 0;
}