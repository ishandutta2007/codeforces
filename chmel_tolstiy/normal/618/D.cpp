#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int nn = 1 << 18;

long long X, Y;
int n;

vector<int> g[nn];

int f[nn][2];

vector<int> t;

void dfs(int v, int p) {
    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (u == p) continue;
        dfs(u, v);
    }

    int free = 0;
    
    t.clear();
    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (u == p) continue;
        free += max(f[u][0], f[u][1]);
        t.push_back(f[u][1] - f[u][0]);
    }
    
    sort(t.begin(), t.end());
    
    if (t.size()) free += 1 - t[0];
    f[v][0] = free;
    
    if (t.size() > 1) free += 1 - t[1];
    f[v][1] = free;
}

int main() {
    cin >> n >> X >> Y;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int D = 0;
    for (int i = 0; i < n; ++i) D = max(D, (int)g[i].size());
    cerr << "D: " << D << endl;
    
    long long ans = 0;
    
    if (n == 2) {
        ans = X;
    } else    
    if (D == n - 1) {
        ans = min((n - 2) * Y + X, 2 * X + (n - 3) * Y);
    } else {
        ans = Y * (n - 1);
        dfs(0, -1);
        int free = max(f[0][0], f[0][1]);
        ans = min(ans, X * free + (n - 1 - free) * Y);
    }
    
    cout << ans << endl;
    
    return 0;
}