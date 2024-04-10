#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

char d[2000][2000];

int n, m;
bool was[2000][2000];
bool found;
int dx[2000][2000];
int dy[2000][2000];

int xx[] = {-1, 1, 0, 0};
int yy[] = {0, 0, -1, 1};

void dfs(int x, int y, int DX, int DY) {
    if (was[x][y]) {
        if (DX != dx[x][y] || DY != dy[x][y]) {
            found = true;
        }
        return;
    }
    if (found) return;
    was[x][y] = true;
    dx[x][y] = DX;
    dy[x][y] = DY;

    for (int i = 0; i < 4; i++) {
        int _x = x + xx[i];
        int _y = y + yy[i];
        int dxx = DX;
        int dyy = DY;
        if (_x < 0) {
            _x += n;
            dxx--;
        }
        if (_x >= n) {
            _x -= n;
            dxx++;
        }
        if (_y < 0) {
            _y += m;
            dyy--;
        }
        if (_y >= m) {
            _y -= m;
            dyy++;
        }
        if (d[_x][_y] != '#')
            dfs(_x, _y, dxx, dyy);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> d[i];

    int sx, sy;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (d[i][j] == 'S') {
            d[i][j] = '.';
            sx = i;
            sy = j;
        }
    }

    dfs(sx, sy, 0, 0);

    if (found)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    solve();

    return 0;
}