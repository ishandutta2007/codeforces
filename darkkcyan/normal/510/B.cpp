#include<iostream>
using namespace std;
 
const int maxn = 55;
int n, m;
char a[maxn][maxn];
 
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};
 
bool visited[maxn][maxn];
bool dfs(int r, int c, int pr, int pc) {
    visited[r][c] = 1;
    for (int dir = 0; dir < 4; ++dir) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (nr < 0 or nr >= n) continue;
        if (nc < 0 or nc >= m) continue;
        if (a[r][c] != a[nr][nc]) continue;
        if (nr == pr and nc == pc) continue;
        if (visited[nr][nc]) {
            return true;
        }
        if (dfs(nr, nc, r, c)) return true;
    }
    return false;
}
 
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    bool ans = false;
    for (int r = 0; r < n; ++r)
    for (int c = 0; c < m; ++c) {
        if (visited[r][c]) continue;
        if (dfs(r, c, -1, -1)) {
            ans = true;
            break;
        }
    }
    cout << (ans ? "Yes" : "No");
    return 0;
}