#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int n, m;
vector<vector<char>> grid;
vector<vector<int>> dist;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(pair<int, int> start) {
    queue <pair<int, int>> q;
    dist[start.first][start.second] = 0;
    q.push(start);
    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        // cerr << i << " " << j << endl;
        q.pop();
        forn(k, 0, 4) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(x <= 0 || x > n || y <= 0 || y > m) continue;
            // cerr << x << " " << y << endl;
            if(dist[x][y] != -1) continue;
            if(grid[x][y] != '.') continue;
            // Check if grid[x][y] is possible.
            int dots = 0;
            forn(z, 0, 4) {
                if(grid[x+dir[z][0]][y+dir[z][1]] == '.') dots++;
            }
            if(dots > 1) continue;
            grid[x][y] = '+';
            q.push({x, y});
            dist[x][y] = dist[i][j] + 1;
        }
    }
}

void solve() {
    cin >> n >> m;
    grid.resize(n + 2);
    dist.resize(n + 2);
    forn(i, 0, n + 2) {
        grid[i].resize(m + 2);
        dist[i].resize(m + 2);
    }
    forn(i, 0, n+2) forn(j, 0, m+2) dist[i][j] = -1;
    forn(j, 0, m + 2) {
        grid[0][j] = '#';
        grid[n+1][j] = '#';
    }
    forn(i, 0, n + 2) {
        grid[i][0] = '#';
        grid[i][m+1] = '#';
    }
    pair <int, int> lab;
    forn(i, 1, n+1) forn(j, 1, m+1) {
        cin >> grid[i][j];
        if(grid[i][j] == 'L') {
            lab = {i, j};
        }
    }
    bfs(lab);
    forn(i, 1, n+1) {
        forn(j, 1, m+1) {
            cout << grid[i][j];
        }
        cout << endl;
    }
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