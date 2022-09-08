#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, ax, ay, sx, sy, fx, fy, used[max_n][max_n];

bool is_in(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

bool ok(int x, int y) {
    return x != ax && y != ay && x + y != ax + ay && x - y != ax - ay;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> ax >> ay >> sx >> sy >> fx >> fy;
    queue<int> qx, qy;
    qx.push(sx);
    qy.push(sy);
    used[sx][sy] = 1;
    while (!qx.empty()) {
        int x = qx.front();
        int y = qy.front();
        qx.pop();
        qy.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_in(nx, ny) && ok(nx, ny) && used[nx][ny] == 0) {
                qx.push(nx);
                qy.push(ny);
                used[nx][ny] = 1;
            }
        }
    }
    if (used[fx][fy]) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}