#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string v[2010];
int N, M;
int ans[2010][2010];
int vis[2010][2010];
bool cur[2010][2010];
int d;
int cycle = -1;
int dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M) {
        cycle = -1;
        return 0;
    }
    if (cur[x][y]) {
        cycle = x * 3000 + y;
        return d - vis[x][y];
    }
    if (vis[x][y]) {
        cycle = -1;
        return ans[x][y];
    }
    int a = x, b = y;
    if (v[x][y] == 'L') b--;
    if (v[x][y] == 'R') b++;
    if (v[x][y] == 'U') a--;
    if (v[x][y] == 'D') a++;
    vis[x][y] = d;
    d++;
    cur[x][y] = 1;
    int cc = dfs(a, b);
    int aa = cycle;
    cur[x][y] = 0;
    d--;
    if (aa == x * 3000 + y) {
        ans[x][y] = cc;
        cycle = -1;
        return cc;
    }
    if (aa != -1) {
        ans[x][y] = cc;
        cycle = aa;
        return cc;
    }
    ans[x][y] = cc + 1;
    cycle = -1;
    return cc + 1;
}

void solve() {
    cin >> N >> M;
    int ma = 0;
    pair<int, int> best;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        for (int j = 0; j < M; j++) {
            ans[i][j] = 0;
            vis[i][j] = 0;
            cur[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vis[i][j]) {
                d = 1;
                cycle = -1;
                int h = dfs(i, j);
                if (h > ma) {
                    best = {i, j};
                    ma = h;
                }
            }
        }
    }
    cout << best.fi + 1 << " " << best.se + 1 << " " << ma << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}