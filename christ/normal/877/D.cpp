#include<bits/stdc++.h>
using namespace std;
const int MN = 1e3+3;
int dist[MN][MN];
queue<pair<int,int>>q;
pair<int,int> d[4] = {{0,1},{0,-1},{1,0},{-1,0}};
char s[MN][MN];
int main() {
    int n,m,k;
    scanf ("%d %d %d",&n,&m,&k);
    memset(dist,0x3f,sizeof dist);
    for (int i = 1; i <= n; i++) {
        scanf ("%s",s[i]+1);
        for (int j = 1; j <= n; j++) if (s[i][j] == '#') dist[i][j] = -1;
    }
    int x,y,x2,y2;
    scanf ("%d%d%d%d",&x,&y,&x2,&y2);
    q.push({x,y}); dist[x][y] = 0;
    while (!q.empty()) {
        int curx = q.front().first, cury = q.front().second; q.pop();
        for (auto p : d) {
            int nx = curx + p.first, ny = cury + p.second;
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && dist[curx][cury] + 1 < dist[nx][ny]) {
                dist[nx][ny] = dist[curx][cury] + 1;
                q.push({nx,ny});
            }
        }
    }
    if (dist[x2][y2] == -1 || dist[x2][y2] > 1e7) return !printf ("-1\n");
    memset(dist,0x3f,sizeof dist);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (s[i][j] == '#') dist[i][j] = -1;
    q.push({x,y}); dist[x][y] = 0;
    while (!q.empty()) {
        int curx = q.front().first, cury = q.front().second; q.pop();
        for (auto p : d) {
            for (int i = 1; i <= k; i++) {
                int nx = curx + p.first * i, ny = cury + p.second * i;
                if (nx <= 0 || nx > n || ny <= 0 || ny > m || s[nx][ny] == '#') break;
                if (dist[curx][cury] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[curx][cury] + 1;
                    if (nx == x2 && ny == y2) {
                        return !printf ("%d\n",dist[nx][ny]);
                    }
                    q.push({nx,ny});
                }
            }
        }
    }
    if (dist[x2][y2] == -1 || dist[x2][y2] > 1e7) return !printf ("-1\n");
    return !printf ("%d\n",dist[x2][y2]);
}