#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 2010;
const int MOD = 1000000007;

int n, m;
int color[MAXN][MAXN], dist[MAXN][MAXN];
char dir[MAXN][MAXN];
int dfs_timer = 0;

int dfs(int i, int j) {
    color[i][j] = dfs_timer++;
    int x = i, y = j;
    if(dir[i][j]=='R') y++;
    if(dir[i][j]=='L') y--;
    if(dir[i][j]=='U') x--;
    if(dir[i][j]=='D') x++;
    if(x < 0 || y < 0 || x >= n || y >= m) {
        dist[i][j] = 1;
        color[i][j] = MOD;
        return -1;
    }
    if(color[x][y] == -1) {
        int timer = dfs(x, y);
        if(timer == -1) {
            dist[i][j] = dist[x][y] + 1;
            color[i][j] = MOD;
            return -1;
        }
        else {
            if(timer <= color[i][j]) {
                dist[i][j] = dist[x][y];
                color[i][j] = MOD;
                return timer;
            }
            else {
                dist[i][j] = dist[x][y] + 1;
                color[i][j] = MOD;
                return -1;
            }
        }
    }
    else if(color[x][y] == MOD) {
        dist[i][j] = dist[x][y] + 1;
        color[i][j] = MOD;
        return -1;
    }
    else {
        dist[i][j] = color[i][j] - color[x][y] + 1;
        color[i][j] = MOD;
        return color[x][y];
    }
}

void solve() {
    cin >> n >> m;
    forn(i, 0, n) forn(j, 0, m) {
        color[i][j] = -1;
        dist[i][j] = -1;
        cin >> dir[i][j];
    }
    forn(i, 0, n) forn(j, 0, m) {
        if(color[i][j] == -1) {
            dfs_timer = 0;
            dfs(i, j);
        }
    }
    int ans_x = -1, ans_y = -1, ans = -1;
    forn(i, 0, n) forn(j, 0, m) {
        if(dist[i][j] > ans) {
            ans_x = j + 1;
            ans_y = i + 1;
            ans = dist[i][j];
        }
    }
    cout << ans_y << " " << ans_x << " " << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}