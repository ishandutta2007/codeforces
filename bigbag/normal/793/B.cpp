#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1011, inf = 1011111111;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, sx, sy, fx, fy, dp[max_n][max_n][4][3];
char a[max_n][max_n];
queue<pair<int, int> > q1, q2;

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

void add(int x, int y, int tp, int cnt) {
    if (cnt >= 3) {
        return;
    }
    if (dp[x][y][tp][cnt]) {
        return;
    }
    dp[x][y][tp][cnt] = 1;
    q1.push(make_pair(x, y));
    q2.push(make_pair(tp, cnt));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 'T') {
                fx = i;
                fy = j;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        add(sx, sy, i, 0);
    }
    while (!q1.empty()) {
        pair<int, int> p1 = q1.front();
        pair<int, int> p2 = q2.front();
        q1.pop();
        q2.pop();
        int x = p1.first, y = p1.second;
        int tp = p2.first, cnt = p2.second;
        //cout << x << " " << y <<"   " << tp << " " << cnt << endl;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_in(nx, ny) && a[nx][ny] != '*') {
                add(nx, ny, i, cnt + (i != tp));
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (dp[fx][fy][i][0] || dp[fx][fy][i][1] || dp[fx][fy][i][2]) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}