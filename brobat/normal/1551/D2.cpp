#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n, m, k;
vector<vector<int>> grid;
int hor[6][2] = {{0, -1}, {0, 2}, {-1, 0}, {-1, 1}, {1, 0}, {1, 1}};
int ver[6][2] = {{-1, 0}, {2, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 1}};

const int CNT = 4;

void fill_hor(int a, int b) {
    vector <int> d(CNT, 0);
    for(int i = 0; i < 6; i++) {
        int x = a + hor[i][0];
        int y = b + hor[i][1];
        if(x < 0 || y < 0 || x >= n || y >= m) continue;
        if(grid[x][y] == -1) continue;
        d[grid[x][y]]++;
    }
    for(int i = 0; i < CNT; i++) {
        if(d[i] == 0) {
            grid[a][b] = i;
            grid[a][b + 1] = i;
            return;
        }
    }
}

void fill_ver(int a, int b) {
    vector <int> d(CNT, 0);
    for(int i = 0; i < 6; i++) {
        int x = a + ver[i][0];
        int y = b + ver[i][1];
        if(x < 0 || y < 0 || x >= n || y >= m) continue;
        if(grid[x][y] == -1) continue;
        d[grid[x][y]]++;
    }
    for(int i = 0; i < CNT; i++) {
        if(d[i] == 0) {
            grid[a][b] = i;
            grid[a + 1][b] = i;
            return;
        }
    }
}

bool check() {
    if(n % 2 == 0) {
        return (k % 2 == 0 && k <= n*(m/2));
    }
    return (k >= m/2 && (k - m/2)%2 == 0);
}

void solve() {
    cin >> n >> m >> k;
    cout << (check() ? "YES" : "NO") << endl;
    if(!check()) return;
    grid.resize(n);
    for(int i = 0; i < n; i++) {
        grid[i].resize(m);
        for(int j = 0; j < m; j++) {
            grid[i][j] = -1;
        }
    }
    if(n % 2) {
        for(int i = 0; i < m; i += 2) {
            fill_hor(0, i);
            k--;
        }
    }
    while(k) {
        for(int i = 0; i < n; i++) {
            if(k == 0) break;
            for(int j = 0; j < m; j++) {
                if(j == m - 1) continue;
                if(grid[i][j] == -1) {
                    fill_hor(i, j);
                    fill_hor(i + 1, j);
                    k -= 2;
                    if(k == 0) break;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == -1) {
                fill_ver(i, j);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << (char)('a' + grid[i][j]);
        }
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}