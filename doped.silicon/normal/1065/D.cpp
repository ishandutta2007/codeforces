#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef pair<int, int> pt;

const int N = 12;
const int M = 305;
const int INF = 1e9;

int n;
int a[N][N];
pt pos[N * N];
pt dist[M][M];

pt operator +(const pt &a, const pt &b){
    return mp(a.x + b.x, a.y + b.y);
}

int dx[] = {-2, -1, 1, 2,  2,  1, -1, -2};
int dy[] = { 1,  2, 2, 1, -1, -2, -2, -1};

bool in(int x, int y){
    return (0 <= x && x < n && 0 <= y && y < n);
}

int get(int x, int y, int p){
    return x * n * 3 + y * 3 + p;
}

pt dp[N * N][3];

int main() {
    scanf("%d", &n);
    forn(i, n) forn(j, n){
        scanf("%d", &a[i][j]);
        --a[i][j];
        pos[a[i][j]] = mp(i, j);
    }
    
    forn(i, M) forn(j, M) dist[i][j] = mp(INF, INF);
    forn(i, M) dist[i][i] = mp(0, 0);
    
    forn(x, n) forn(y, n){
        forn(i, 8){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (in(nx, ny))
                dist[get(x, y, 0)][get(nx, ny, 0)] = mp(1, 0);
        }
        
        for (int i = -n + 1; i <= n - 1; ++i){
            int nx = x + i;
            int ny = y + i;
            if (in(nx, ny))
                dist[get(x, y, 1)][get(nx, ny, 1)] = mp(1, 0);
            ny = y - i;
            if (in(nx, ny))
                dist[get(x, y, 1)][get(nx, ny, 1)] = mp(1, 0);
        }
        
        forn(i, n){
            int nx = x;
            int ny = i;
            dist[get(x, y, 2)][get(nx, ny, 2)] = mp(1, 0);
            nx = i;
            ny = y;
            dist[get(x, y, 2)][get(nx, ny, 2)] = mp(1, 0);
        }
        
        forn(i, 3) forn(j, 3){
            if (i != j){
                dist[get(x, y, i)][get(x, y, j)] = mp(1, 1);
            }
        }
    }
    
    forn(k, M) forn(i, M) forn(j, M)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    forn(i, N * N) forn(j, 3) dp[i][j] = mp(INF, INF);
    dp[0][0] = dp[0][1] = dp[0][2] = mp(0, 0);
    forn(i, n * n - 1) forn(j, 3) forn(k, 3)
        dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + dist[get(pos[i].x, pos[i].y, j)][get(pos[i + 1].x, pos[i + 1].y, k)]);
    
    pt ans = mp(INF, INF);
    ans = min(ans, dp[n * n - 1][0]);
    ans = min(ans, dp[n * n - 1][1]);
    ans = min(ans, dp[n * n - 1][2]);
    
    printf("%d %d\n", ans.x, ans.y);
    return 0;
}