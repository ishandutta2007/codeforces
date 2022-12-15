#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int n, boss[50], stk[50], top;
bitset<50> G[50], vis;
string mp[50][50];
int idx[50];
vector<int> SCC[50];

int finds(int x) {
    if (x == boss[x]) return x;
    return boss[x] = finds(boss[x]);
}

void Union(int x, int y) {
    x = finds(x), y = finds(y);
    if (x == y) return;
    if (x < y) swap(x, y);
    boss[x] = y;
}

void dfs(int u) {
    vis[u] = 1;
    for (int i = 1; i <= n; ++i)
        if (G[u][i]) {
            if (!vis[i]) dfs(i);
            G[u] |= G[i];
        }
    stk[++top] = u;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    iota(boss + 1, boss + n + 1, 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (x == 1) G[i][j] = 1;
        }
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs(i);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (G[i][j] && G[j][i]) Union(i, j);
    int tp = 0;
    for (int i = 1; i <= n; ++i)
        if (finds(stk[i]) == stk[i]) idx[stk[i]] = tp++;
    for (int i = 1; i <= n; ++i)
        idx[i] = idx[finds(i)], SCC[idx[i]].pb(i);
    int x = 20, y = 3, z = tp * 2;
    string pass = string(x, '#');
    for (int i = 0; i < x; i += 2)
        pass[i] = '.';
    for (int i = 0; i < tp; ++i) {
        for (int j = 0; j < y; ++j)
            mp[i * 2][j] = string(x, '#'), mp[i * 2 + 1][j] = string(x, '.');
        mp[i * 2][0] = mp[i * 2 + 1][0] = pass;
        mp[i * 2 + 1][1] = string(x, '#');
        mp[i * 2][0][i * 2] = '#';
        mp[i * 2 + 1][1][i * 2] = '.';
        bitset<50> nxt;
        for (int j : SCC[i]) {
            for (int k = 1; k <= n; ++k)
                if (G[j][k] && idx[k] != idx[j])
                    nxt[idx[k]] = 1;
            mp[i * 2 + 1][2][j - 1] = '0' + j;
        }
        for (int j = 0; j < tp; ++j)
            if (nxt[j]) mp[i * 2 + 1][1][j * 2] = '.';
    }

    cout << x << " " << y << " " << z << "\n";
    for (int i = tp  - 1; i >= 0; --i) {
        for (int j = 0; j < y; ++j)
            cout << mp[i * 2 + 1][j] << "\n";
        cout << "\n";
        for (int j = 0; j < y; ++j)
            cout << mp[i * 2][j] << "\n";
        if (i != 0) cout << "\n";
    }
        
}