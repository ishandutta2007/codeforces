#include <bits/stdc++.h>

using namespace std;

const int max_n = 12, inf = 1000111222;
vector<vector<int>> dxs, dys;

int n, a[max_n][max_n], sx, sy, fx, fy, dist[max_n][max_n][3][max_n * max_n][2];

void add_horse() {
    vector<int> dx{-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> dy{-1, 1, -2, 2, -2, 2, -1, 1};
    dxs.push_back(dx);
    dys.push_back(dy);
}

void add_bishop() {
    vector<int> dx, dy;
    for (int i = 1; i < max_n; ++i) {
        dx.push_back(i);
        dy.push_back(i);

        dx.push_back(-i);
        dy.push_back(i);

        dx.push_back(i);
        dy.push_back(-i);

        dx.push_back(-i);
        dy.push_back(-i);
    }
    dxs.push_back(dx);
    dys.push_back(dy);
}

void add_rooc() {
    vector<int> dx, dy;
    for (int i = 1; i < max_n; ++i) {
        dx.push_back(0);
        dy.push_back(i);

        dx.push_back(0);
        dy.push_back(-i);

        dx.push_back(i);
        dy.push_back(0);

        dx.push_back(-i);
        dy.push_back(0);
    }
    dxs.push_back(dx);
    dys.push_back(dy);
}

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < n;
}

bool better(int d1, int d2, int w1, int w2) {
    return make_pair(d1 + d2, d2) < make_pair(w1 + w2, w2);
}

queue<int> qx, qy, qtp, qnum;

void upd(int x, int y, int tp, int num, int d1, int d2) {
    if (better(d1, d2, dist[x][y][tp][num][0], dist[x][y][tp][num][1])) {
        if (dist[x][y][tp][num][0] == inf) {
            qx.push(x);
            qy.push(y);
            qtp.push(tp);
            qnum.push(num);
        }
        dist[x][y][tp][num][0] = d1;
        dist[x][y][tp][num][1] = d2;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    add_horse();
    add_bishop();
    add_rooc();
    cin >> n;
    int sx, sy, fx, fy;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                sx = i;
                sy = j;
            }
            if (a[i][j] == n * n) {
                fx = i;
                fy = j;
            }
        }
    }
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            for (int q = 0; q < 3; ++q) {
                for (int k = 0; k < max_n * max_n; ++k) {
                    for (int w = 0; w < 2; ++w) {
                        dist[i][j][q][k][w] = inf;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        dist[sx][sy][i][1][0] = 0;
        dist[sx][sy][i][1][1] = 0;
        qx.push(sx);
        qy.push(sy);
        qtp.push(i);
        qnum.push(1);
    }
    while (!qx.empty()) {
        int x = qx.front();
        int y = qy.front();
        int tp = qtp.front();
        int num = qnum.front();
        qx.pop();
        qy.pop();
        qtp.pop();
        qnum.pop();
        int d1 = dist[x][y][tp][num][0];
        int d2 = dist[x][y][tp][num][1];
        //if (num == 9) cout << x << " " << y << " " << tp << " " << num << ": " << d1 << " " << d2 << endl;
        for (int i = 0; i < dxs[tp].size(); ++i) {
            int nx = x + dxs[tp][i];
            int ny = y + dys[tp][i];
            if (is_in(nx, ny)) {
                int cur = num;
                if (a[nx][ny] == cur + 1) {
                    ++cur;
                }
                upd(nx, ny, tp, cur, d1 + 1, d2);
            }
        }
        upd(x, y, 0, num, d1, d2 + 1);
        upd(x, y, 1, num, d1, d2 + 1);
        upd(x, y, 2, num, d1, d2 + 1);
    }
    int a1 = inf, a2 = inf;
    for (int tp = 0; tp < 3; ++tp) {
        if (better(dist[fx][fy][tp][n * n][0], dist[fx][fy][tp][n * n][1], a1, a2)) {
            a1 = dist[fx][fy][tp][n * n][0];
            a2 = dist[fx][fy][tp][n * n][1];
            //cout << fx << " " << fy << " " << tp << ": " << a1 << " " << a2 << endl;
        }
    }
    cout << a1 + a2 << " " << a2 << endl;
    return 0;
}