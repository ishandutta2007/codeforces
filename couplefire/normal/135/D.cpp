#pragma comment(linker, "/STACK:100000000")
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <set>
#include <map>
using namespace std;
 
#define N 1005
 
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
 
char a[N][N];
int u[N][N], uu[N][N];
int b[N][N];
 
int px[N*N], py[N*N];
 
int it, fr, n, m, f;
int ch(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
 
void dfs(int x, int y) {
    int i, xx, yy;
    u[x][y] = 1;
 
    for (i = 0; i < 8; i ++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (!ch(xx, yy)) {
            f = 0;
            continue;
        }
        if (a[xx][yy] == '0' ) {
            if (u[xx][yy] == 0) {
                dfs(xx, yy);
            }
        } else {
            if (b[xx][yy] != it) {
                b[xx][yy] = it;
                px[fr] = xx;
                py[fr] = yy;
                fr ++;
            }
        }
    }
}
int l;
 
void dfs2(int x, int y) {
    int i, xx, yy, t;
    uu[x][y] = 1;
    l ++;
    t = 0;
    for (i = 0; i < 4; i ++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (ch(xx, yy) && uu[xx][yy] == 0 && b[xx][yy] == it) {
            dfs2(xx, yy);
        }
        if (ch(xx, yy) && b[xx][yy] == it) {
            t ++;
        }
    }
    if (t != 2) {
        f = 0;
    }
}
 
int i, j, k, x, y, z, t, res;
 
int main() {
    cin >> n >> m;
    for (i = 0; i < n; i ++) {
        cin >> a[i];
    }
 
    for (i = 0; i < n; i ++) {
        for (j = 0; j < m; j ++) {
            if (a[i][j] == '0' && u[i][j] == 0) {
                it ++;
                fr = 0;
                f = 1;
                dfs(i, j);
                if (f == 0 || fr == 0) {
                    continue;
                }
                l = 0;
                for (k = 0; k < fr; k ++) {
                    uu[px[k]][py[k]] = 0;
                }
                dfs2(px[0], py[0]);
                if (f == 0 || l != fr) {
                    continue;
                }
                if (l > res) {
                    res = l;
                }
            }
        }
    }
 
    memset(b, 0, sizeof(b));
    for (i = 0; i + 1 < n; i ++) {
        for (j = 0; j + 1 < m; j ++) {
            if (a[i][j] == '1' && a[i+1][j] == '1' && a[i][j+1] == '1' && a[i+1][j+1] == '1') {
                if (res < 4) {
                    res = 4;
                }
            }
        }
    }
 
    cout << res << endl;
    return 0;
}